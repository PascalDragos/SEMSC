#include "../SEMS_Headers/Com.h"

#include "../SEMS_Headers/Util.h"

#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/RSA.h"
#include "../SEMS_Headers/Random.h"
#include "../SEMS_Headers/Patcher.h"
#include "../SEMS_Headers/Nonce.h"
#include "../SEMS_Headers/Skey.h"
#include "../SEMS_Headers/Config.h"

extern pal_logger_t logger_console;


extern void example_optiga_util_update_count(void);

uint8_t secure_communication(void)
{
    uint8_t random_buf[32];
    uint8_t ciphertext[129];
    uint16_t ciphertext_len = 128;
    uint8_t nonce[4];
	uint16_t optiga_counter_oid = OPTIGA_NONCE_OID;
	uint16_t optiga_key_oid = OPTIGA_SESKEY_OID;


	// Generate random number using Optiga for session key
	optiga_crypt_random_wrapper(random_buf, 32);

	// Get Nonce
//	optiga_util_reset_count(optiga_counter_oid);
	optiga_util_read_nonce(optiga_counter_oid, nonce, sizeof(nonce));


	// Encrypt the session key with RSA
	uint8_t plaintext[32 + 4] = {0};
	memcpy(plaintext, random_buf, 32);
	memcpy(&plaintext[32], nonce, 4);
	optiga_crypt_rsa_encrypt_message_wrapper(plaintext, sizeof(plaintext), ciphertext, &ciphertext_len);

	// Send session key to the App
	if(ciphertext_len == 128u)
	{
		// Pana la 127 merge ok
		optiga_lib_print_bytes(ciphertext, 129); // TODO: TREBUIE SA TRIMIT CU UNUL IN PLUS ALTFEL RAMAN BLOCAT
	}
	else
	{
		// Sens 128 0s, encrypt nu a functionat
		optiga_lib_print_bytes(ciphertext, 129);
	}

	// Store session key
	optiga_util_write_shared_key(optiga_key_oid, random_buf, sizeof(random_buf));


	// Read session key, Testing
//	uint8_t key[32] = {0x01, 0x01, 0x01, 0x01};
//	optiga_util_read_shared_key(optiga_key_oid, key, sizeof(key));
//	ciphertext_len = ciphertext_len; // BR
	return true;
}
