#ifndef CONFIG_H_
#define CONFIG_H_


#include "Dave.h"

#define DEVELOPMENT (0u)
#define PRODUCTION (1u)
#define TESTING (2u)
#define FACTORY (3u)

#define LIFECYCLE PRODUCTION

#define TIMEOUT_IN_SECONDS (1u)  // timer period
#define MAX_FAILED_REQ (10u)


// #define OPTIGA_KEY_OID (0xF1E0u)  // working, but Type2 only 100 accesses
#define OPTIGA_SESKEY_OID (0xF1D6u)  // working, Type 3 (200k accesses)

#define OPTIGA_NVMKEY_OID (0xF1D8u)  // working, Type 3 (200k accesses)

#define OPTIGA_NONCE_OID (0xE120u)  // one of four monotonic counters

#endif
