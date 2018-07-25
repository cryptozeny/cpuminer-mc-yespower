#include "miner.h"
#include "yespower.h"
#include "yespower-opt.c"

static const yespower_params_t yespower_BITZENY = {YESPOWER_0_5, 2048, 8, "Client Key", 10};  // ZNY
static const yespower_params_t yespower_YENTEN = {YESPOWER_0_5, 4096, 16, "Client Key", 10}; // YTN
static const yespower_params_t yespower_WAVI = {YESPOWER_0_5, 4096, 32, "WaviBanana", 10}; // WAVI
static yespower_params_t yespower_KOTO = {YESPOWER_0_5, 2048, 8, NULL, 80}; // KOTO: without const, because it obtains from loop: thanks twitter@WO01_

void yespower_hash( const char *input, char *output, uint32_t len )
{
  yespower_KOTO.pers = input;  // KOTO: input variable
  yespower_tls( (yespower_binary_t*)input, len,
                &yespower_BITZENY,                  // ZNY
                // &yespower_YENTEN,                   // YTN
                // &yespower_WAVI,                     // WAVI
                // &yespower_KOTO,                     // KOTO
                (yespower_binary_t*)output );
}

extern struct work_restart *work_restart;

extern bool fulltest(const uint32_t *hash, const uint32_t *target);

static int pretest(const uint32_t *hash, const uint32_t *target)
{
	return hash[7] < target[7];
}

int scanhash_yespower(int thr_id, uint32_t *pdata, const uint32_t *ptarget,
		      uint32_t max_nonce, unsigned long *hashes_done)
{
	uint32_t data[20] __attribute__((aligned(64)));
	uint32_t hash[8] __attribute__((aligned(64)));
	uint32_t n = pdata[19] - 1;
	const uint32_t first_nonce = pdata[19];

	for (int k = 0; k < 19; k++) {
		be32enc(&data[k], pdata[k]);
	}
	do {
		be32enc(&data[19], ++n);
		yespower_hash((char *)data, (char *)hash, 80);
		if (pretest(hash, ptarget) && fulltest(hash, ptarget)) {
			pdata[19] = n;
			*hashes_done = n - first_nonce + 1;
			return 1;
		}
	} while (n < max_nonce && !work_restart[thr_id].restart);

	*hashes_done = n - first_nonce + 1;
	pdata[19] = n;
	return 0;
}
