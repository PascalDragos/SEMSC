#include "optiga/optiga_crypt.h"
#include "optiga/optiga_util.h"
#include "optiga/common/optiga_lib_logger.h"
#include "optiga/pal/pal_os_event.h"
#include "optiga/pal/pal.h"
#include "optiga/pal/pal_os_timer.h"
#include "optiga_example.h"
#include "optiga/pal/pal_logger.h"

#include "../SEMS_Headers/Com.h"
#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/RSA.h"
#include "../SEMS_Headers/Random.h"

extern pal_logger_t logger_console;


uint8_t secure_communication(void)
{
    uint8_t random_buf[32] = {0x01, 0x01, 0x01, 0x01};
    uint8_t ciphertext[129] = {0x00};
    uint16_t ciphertext_len = 128;

	// Generate random number using Optiga for session key
	optiga_crypt_random_wrapper(random_buf, 32);

	// Encrypt the session key with RSA
	optiga_crypt_rsa_encrypt_message_wrapper(random_buf, sizeof(random_buf), ciphertext, &ciphertext_len);

	// Send session key to the App
	if(ciphertext_len == 128)
	{
		optiga_lib_print_bytes(ciphertext, 129); // TODO: TREBUIE SA TRIMIT CU UNUL IN PLUS ALTFEL RAMAN BLOCAT
	}
	else
	{
		// Sens 128 0s, encrypt nu a functionat
		optiga_lib_print_bytes(ciphertext, 129);
	}

	ciphertext_len = 128; // for breakpoint

	return 0;
}
