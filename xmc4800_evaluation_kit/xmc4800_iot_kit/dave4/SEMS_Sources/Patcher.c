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


	if (0u == pal_logger_read(&logger_console, command, 32))
	{
		if('U' == command[0])
		{
			// nothing to do, sec unlock will be called

		}
		else
		{
			if (0u == is_secure_com)
			{
				uint8_t *received_user_token_start;
				uint32_t received_user_token;
				received_user_token_start = command + 16u;
				received_user_token = (received_user_token_start[0] << 24u)+
							 (received_user_token_start[1] << 16u)+
							 (received_user_token_start[2] <<  8u)+
							 (received_user_token_start[3] <<  0u);

				if(received_user_token != user_token)
				{
					is_invalid_req = true;
				}

			}
			else
			{
				uint8_t key[32];
				uint8_t *received_digest_start;
				uint8_t calculated_digest[32]; //  SHA 256
				uint8_t *received_user_token_start;
				uint32_t received_user_token;
				uint8_t *received_user_nonce_start;
				uint8_t nonce[4];
				uint16_t optiga_key_oid = 0xF1E0u;
				uint16_t optiga_counter_oid = 0xE120u;

				// Extract Hash
				received_digest_start = command + 24u;  // last 8 bytes of the SHA256(Ciphertext)

				// Calculate Hash
				optiga_crypt_hash_data_wrapper(command, 24u, calculated_digest); // SHA256(Ciphertext)

				// Compare digests
				if(0 != memcmp(received_digest_start, calculated_digest + 24u, 8u))  // compare 8 bytes
				{
					is_invalid_req = true;
				}

				// Retrive Session Key
				optiga_util_read_shared_key(optiga_key_oid, key, sizeof(key));  // sesion key from Secure Comm activation

				// Decrypt ciphertext
				stream_enc(command, key, 24u);

				// Extract Token

				received_user_token_start = command + 16u;
				received_user_token = (received_user_token_start[0] << 24u)+
							 (received_user_token_start[1] << 16u)+
							 (received_user_token_start[2] <<  8u)+
							 (received_user_token_start[3] <<  0u);

				if(received_user_token != user_token)
				{
					is_invalid_req = true;
				}

				// Extract Nonce
				received_user_nonce_start = command + 20u;


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
					optiga_util_update_count_wrapper(optiga_counter_oid, 1u);
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
	if(0u == is_secure_com)
	{
		uint8_t response[32];
		uint8_t send_user_token[4];


		send_user_token[0] = (user_token >> 24u) & 0xFFu;
				send_user_token[1] = (user_token >> 16u) & 0xFFu;
				send_user_token[2] = (user_token >>  8u) & 0xFFu;
				send_user_token[3] = (user_token >>  0u) & 0xFFu;

		memcpy(response, msg, 16u);
		memcpy(response + 16u, send_user_token, 4u);

		optiga_lib_print_bytes(response, 32u);
	}
	else
	{
		uint8_t response[32];
		uint8_t nonce[4];
		uint8_t send_user_token[4];
		uint8_t calculated_digest[32];
		uint8_t key[32];
		uint16_t optiga_key_oid = 0xF1E0u;
		uint16_t optiga_counter_oid = 0xE120u;



		// Read nonce
		optiga_util_read_nonce(optiga_counter_oid, nonce, sizeof(nonce));

		send_user_token[0] = (user_token >> 24u) & 0xFFu;
		send_user_token[1] = (user_token >> 16u) & 0xFFu;
		send_user_token[2] = (user_token >>  8u) & 0xFFu;
		send_user_token[3] = (user_token >>  0u) & 0xFFu;


		// First Pack
		memcpy(response, msg, 16u);
		memcpy(response + 16u, send_user_token, 4u);  // global
		memcpy(response + 20u, nonce, 4u);

		// Retrive Session Key
		optiga_util_read_shared_key(optiga_key_oid, key, sizeof(key));  // sesion key from Secure Comm activation

		// Encrypt ciphertext
		stream_enc(response, key, 24u);

		// Calculate Hash
		optiga_crypt_hash_data_wrapper(response, 24u, calculated_digest); // SHA256(Ciphertext)

		// Pack the message
		memcpy(response + 24u, calculated_digest + 24u, 8u);

		optiga_lib_print_bytes(response, 32u);
	}

	return true;
}


