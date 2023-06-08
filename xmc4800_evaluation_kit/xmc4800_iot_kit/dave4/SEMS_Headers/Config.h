#ifndef CONFIG_H_
#define CONFIG_H_


#include "Dave.h"

#define DEVELOPMENT (0u)
#define PRODUCTION (1u)
#define TESTING (2u)
#define LOADING (3u)

#define LIFECYCLE LOADING

#define TIMEOUT_IN_SECONDS (1u)
#define MAX_FAILED_REQ (1u)


#define OPTIGA_SESKEY_OID (0xF1D6u)
// #define OPTIGA_KEY_OID (0xF1E0u)

#define OPTIGA_NVMKEY_OID (0xF1D8u)

#define OPTIGA_NONCE_OID (0xE120u)

#endif
