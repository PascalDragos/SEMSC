#include <SEMS_Headers/Skey.h>
#include "../SEMS_Headers/Patcher.h"
#include "../SEMS_Headers/Util.h"

#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/Hash.h"
#include "../SEMS_Headers/Nonce.h"



extern pal_logger_t logger_console;
extern uint32_t user_token;


uint8_t read_request(uint8_t command[], uint8_t is_secure_unlock, uint8_t is_secure_com)
{
	uint8_t is_invalid_req = false;


	if (0 == pal_logger_read(&logger_console, command, 32))
	{
		if('U' == command[0])
		{
			// nothing to do, sec unlock will be called

		}
		else
		{
			if (0 == is_secure_com)
			{
				uint8_t *received_user_token_start;
				uint32_t received_user_token;
				received_user_token_start = command + 16;
				received_user_token = (received_user_token_start[0] << 24)+
							 (received_user_token_start[1] << 16)+
							 (received_user_token_start[2] <<  8)+
							 (received_user_token_start[3] <<  0);

				if(received_user_token != user_token)
				{
					is_invalid_req = true;
				}

			}
			else
			{
				uint8_t key[32] = {0x01, 0x01, 0x01, 0x01};
				uint8_t *received_digest_start;
				uint8_t calculated_digest[32]; //  SHA 256
				uint8_t *received_user_token_start;
				uint32_t received_user_token;
				uint8_t *received_user_nonce_start;
				uint8_t nonce[4];
				uint16_t optiga_key_oid = 0xF1E0;
				uint16_t optiga_counter_oid = 0xE120;

				// Extract Hash
				received_digest_start = command + 24;  // last 8 bytes of the SHA256(Ciphertext)

				// Calculate Hash
				optiga_crypt_hash_data_wrapper(command, 24, calculated_digest); // SHA256(Ciphertext)

				// Compare digests
				if(0 != memcmp(received_digest_start, calculated_digest + 24, 8))  // compare 8 bytes
				{
					is_invalid_req = true;
				}

				// Retrive Session Key
				optiga_util_read_shared_key(optiga_key_oid, key, sizeof(key));  // sesion key from Secure Comm activation

				// Decrypt ciphertext
				stream_enc(command, key, 24);

				// Extract Token

				received_user_token_start = command + 16;
				received_user_token = (received_user_token_start[0] << 24)+
							 (received_user_token_start[1] << 16)+
							 (received_user_token_start[2] <<  8)+
							 (received_user_token_start[3] <<  0);

				if(received_user_token != user_token)
				{
					is_invalid_req = true;
				}

				// Extract Nonce
				received_user_nonce_start = command + 20;


				// Read Nonce from Optiga
				optiga_util_read_nonce(optiga_counter_oid, nonce, sizeof(nonce));

				// Compare Nonces
				// recv_nonced trebuie sa fie mai mare decat nonce
				// daca e mai mare sau egal, invalid
				if(0 >= memcmp(received_user_nonce_start, nonce, sizeof(nonce)))
				{
					is_invalid_req = true;
				}

				if(false == is_invalid_req)
				{
					optiga_util_update_count_wrapper(optiga_counter_oid, 1);
				}
				// Command will be OUT variable also
			}
		}

	}
	else
	{
		is_invalid_req = true;
	}
	return is_invalid_req;
}




uint8_t write_request(uint8_t msg[], uint8_t is_secure_com)
{
	if(0 == is_secure_com)
	{
		uint8_t response[32] ={0};
		uint8_t send_user_token[4];


		send_user_token[0] = (user_token >> 24) & 0xFF;
				send_user_token[1] = (user_token >> 16) & 0xFF;
				send_user_token[2] = (user_token >>  8) & 0xFF;
				send_user_token[3] = (user_token >>  0) & 0xFF;

		memcpy(response, msg, 16);
		memcpy(response + 16, send_user_token, 4);

		optiga_lib_print_bytes(response, 32);
	}
	else
	{
		uint8_t response[32];
		uint8_t nonce[4];
		uint8_t send_user_token[4];
		uint8_t calculated_digest[32];
		uint8_t key[32] = {0x01, 0x01, 0x01, 0x01};
		uint16_t optiga_key_oid = 0xF1E0;
		uint16_t optiga_counter_oid = 0xE120;



		// Read nonce
		optiga_util_read_nonce(optiga_counter_oid, nonce, sizeof(nonce));

		send_user_token[0] = (user_token >> 24) & 0xFF;
		send_user_token[1] = (user_token >> 16) & 0xFF;
		send_user_token[2] = (user_token >>  8) & 0xFF;
		send_user_token[3] = (user_token >>  0) & 0xFF;


		// First Pack
		memcpy(response, msg, 16);
		memcpy(response + 16, send_user_token, 4);  // global
		memcpy(response + 20, nonce, 4);

		// Retrive Session Key
		optiga_util_read_shared_key(optiga_key_oid, key, sizeof(key));  // sesion key from Secure Comm activation

		// Encrypt ciphertext
		stream_enc(response, key, 24);

		// Calculate Hash
		optiga_crypt_hash_data_wrapper(response, 24, calculated_digest); // SHA256(Ciphertext)

		// Pack the message
		memcpy(response + 24, calculated_digest + 24, 8);

		optiga_lib_print_bytes(response, 32);
	}

	return true;
}


