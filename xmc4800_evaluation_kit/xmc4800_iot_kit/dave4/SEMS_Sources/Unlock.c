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
    uint8_t random_buf[32] = {0x00};
    uint8_t signature[128] = {0x00};
    // 1 (succes) + 4 (token)
    uint8_t response[1 + 4] = {0x00, 0x01, 0x02, 0x03};
    uint8_t success = false;

	// Generate random number using Optiga
	optiga_crypt_random_wrapper(random_buf, 32);

	// Send seed to App
	optiga_lib_print_bytes(random_buf, 32);


	// Receive signature
	if (0 == pal_logger_read(&logger_console, (uint8_t *)signature, 128))
	{
		// Compare enc and enc'
		success = optiga_crypt_rsa_verify_wrapper(random_buf, sizeof(random_buf), signature, sizeof(signature));
		if(success)
		{

			// Assign response
			response[0] = success;
			// Generate random number using Optiga
			optiga_crypt_random_wrapper(response + 1, 8);  // nu pot genera doar 6

			// Adauga intr-o structura
			user_token = (response[1] << 24)+
						 (response[2] << 16)+
						 (response[3] <<  8)+
						 (response[4] <<  0);

		}
		// Send response
		optiga_lib_print_bytes(response, 5);
	}

	return success;
}


uint8_t secure_unlock_old(void)
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

	return success;
}



