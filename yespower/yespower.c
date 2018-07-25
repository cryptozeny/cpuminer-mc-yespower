#include "miner.h"
#include "yespower.h"
#include "yespower-opt.c"

// ref from yespower-opt.c
// int yespower_tls
// (
//   const uint8_t *src,
//   size_t srclen,
//   const yespower_params_t *params,
//   yespower_binary_t *dst
// )

// ref from yespower-opt.c
// int yespower(yespower_local_t *local,
//     const uint8_t *src, size_t srclen,
//     const yespower_params_t *params,
//     yespower_binary_t *dst)
// {
// 	yespower_version_t version = params->version;
// 	uint32_t N = params->N;
// 	uint32_t r = params->r;
// 	const uint8_t *pers = params->pers;
// 	size_t perslen = params->perslen;
// 	uint32_t Swidth;
// 	size_t B_size, V_size, XY_size, need;
// 	uint8_t *B, *S;
// 	salsa20_blk_t *V, *XY;
// 	pwxform_ctx_t ctx;
// 	uint8_t sha256[32];
// }

static const yespower_params_t v1 = {YESPOWER_0_5, 2048, 8, "Client Key", 10};  // ZNY
static const yespower_params_t v2 = {YESPOWER_0_5, 4096, 16, "Client Key", 10}; // YTN

// NOTWORK >> TODO >> KOTO
static const yespower_params_t v3 = {YESPOWER_0_5, 2048, 8, NULL, 80}; // KOTO

void yespower_hash( const char *input, char *output, uint32_t len )
{
  yespower_tls( (yespower_binary_t*)input, len,
                &v1,                                // ZNY
                // &v2,                                // YTN
                // &v3,                                // KOTO
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
