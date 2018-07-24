#include "miner.h"
#include "yespower.h"
#include "yespower-best.c"

static const yespower_params_t v1 = {YESPOWER_0_5, 2048, 8, "Client Key", 10};  // ZNY
static const yespower_params_t v2 = {YESPOWER_0_5, 4096, 16, "Client Key", 10}; // YTN

void yespower_hash( const char *input, char *output, uint32_t len )
{
  yespower_tls( (yespower_binary_t*)input, len, &v1, (yespower_binary_t*)output ); // ZNY
}

int scanhash_yespower(int thr_id, uint32_t *pdata, const uint32_t *ptarget,
		      uint32_t max_nonce, unsigned long *hashes_done)
{
	uint32_t data[20] __attribute__((aligned(128)));
	uint32_t hash[8] __attribute__((aligned(32)));
	uint32_t n = pdata[19] - 1;
	const uint32_t first_nonce = pdata[19];

	for (int i = 0; i < 20; i++) {
		be32enc(&data[i], pdata[i]);
	}
	do {
		be32enc(&data[19], ++n);
		yespower_hash((char *)data, (char *)hash, 80);
		if ((hash[7] < ptarget[7]) && fulltest(hash, ptarget)) {
			pdata[19] = n;
			*hashes_done = n - first_nonce + 1;
			return 1;
		}
	} while (n < max_nonce && !work_restart[thr_id].restart);

	*hashes_done = n - first_nonce + 1;
	pdata[19] = n;
	return 0;
}
