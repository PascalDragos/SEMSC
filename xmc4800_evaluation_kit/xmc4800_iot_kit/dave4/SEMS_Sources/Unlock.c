#include "optiga/pal/pal_logger.h"
#include "optiga/common/optiga_lib_logger.h"

#include "../SEMS_Headers/Unlock.h"
#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/RSA.h"
#include "../SEMS_Headers/Random.h"
#include "../SEMS_Headers/Skey.h"

extern pal_logger_t logger_console;

uint32_t user_token = 0;


uint8_t secure_unlock(void)
{
    uint8_t random_buf[32];
    uint8_t signature[128];

    uint8_t success = false;

	// Generate random number using Optiga
	optiga_crypt_random_wrapper(random_buf, 32u);

	// Send seed to App
	optiga_lib_print_bytes(random_buf, 32u);


	// Receive signature
	if (0u == pal_logger_read(&logger_console, (uint8_t *)signature, 128u))
	{
	    uint8_t response[1 + 4] = {0x00, 0x01, 0x02, 0x03, 0x04};
		// Compare enc and enc'
		success = optiga_crypt_rsa_verify_wrapper(random_buf, sizeof(random_buf), signature, sizeof(signature));
		if(success)
		{

			// Assign response
			response[0] = success;
			// Generate random number using Optiga
			optiga_crypt_random_wrapper(response + 1, 8u);  // nu pot genera doar 6

			// Adauga intr-o structura
			user_token = (response[1] << 24u)+
						 (response[2] << 16u)+
						 (response[3] <<  8u)+
						 (response[4] <<  0u);

		}
		// Send response
		optiga_lib_print_bytes(response, 5u);
	}

	return success;
}

