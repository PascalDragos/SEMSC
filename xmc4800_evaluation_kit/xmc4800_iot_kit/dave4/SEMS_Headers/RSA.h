#ifndef RSA_H_
#define RSA_H_

#include "Dave.h"


void optiga_crypt_rsa_encrypt_message_wrapper(uint8_t message[], uint8_t message_length, uint8_t encrypted_message[], uint16_t* encrypted_message_length);
uint8_t optiga_crypt_rsa_verify_message_wrapper(uint8_t message[], uint8_t message_length, uint8_t signature[], uint16_t signature_length);
uint8_t optiga_crypt_rsa_verify_wrapper(uint8_t message[], uint8_t message_length, uint8_t signature[], uint16_t signature_length);


#endif
