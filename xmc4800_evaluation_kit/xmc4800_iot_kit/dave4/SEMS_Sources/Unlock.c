#include "optiga/optiga_crypt.h"
#include "optiga/optiga_util.h"
#include "optiga/common/optiga_lib_logger.h"
#include "optiga/pal/pal_os_event.h"
#include "optiga/pal/pal.h"
#include "optiga/pal/pal_os_timer.h"
#include "optiga_example.h"
#include "optiga/pal/pal_logger.h"

#include "../SEMS_Headers/Unlock.h"
#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/RSA.h"
#include "../SEMS_Headers/Random.h"

extern pal_logger_t logger_console;

uint8_t secure_unlock(void)
{
    uint8_t random_buf[32] = {0x00};
    uint8_t ciphertext[32] = {0x00};
    uint8_t key[32] = {0x00};
    uint8_t response[9] = {0x00, 0x01, 0x02, 0x03 , 0x04, 0x05, 0x06, 0x07, 0x08};
    uint8_t success = false;

	// Generate random number using Optiga
	optiga_crypt_random_wrapper(random_buf, 32);

	// Send seed to App
	optiga_lib_print_bytes(random_buf, 32);

	// Compute enc
	//optiga_crypt_rsa_encrypt_message_wrapper(random_buf, 32, enc_random_buf, &enc_random_buf_len);

	// retrive key
	optiga_util_read_shared_key(0xF1E0, key, sizeof(key));

	// compute enc XOR
	stream_enc(random_buf, key, 32);


	// Receive enc' from App
	if (0 == pal_logger_read(&logger_console, (uint8_t *)ciphertext, 32))
	{
		// Compare enc and enc'
		success = compare_bytes(random_buf, ciphertext, 32);

		// Assing response
		response[0] = success;
		if(success)
		{
			// Generate random number using Optiga
			optiga_crypt_random_wrapper(response + 1, 8);

			// Adauga intr-o structura
		}
		// Send response
		optiga_lib_print_bytes(response, 9);
	}

	return 0;
}
