#if defined(__ARM_NEON__)||defined(__ARM_NEON)
#include "yespower-neon.c"
// #elif defined __SSE2__
// #include "yespower-sse.c"
#else
#include "yespower-opt.c"
#endif
