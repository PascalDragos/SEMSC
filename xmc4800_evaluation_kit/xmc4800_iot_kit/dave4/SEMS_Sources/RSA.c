#include "optiga/optiga_crypt.h"
#include "optiga_example.h"
#include "../SEMS_Headers/RSA.h"
#include "../SEMS_Headers/Hash.h"
#include <DAVE.h>

#ifdef OPTIGA_CRYPT_RSA_ENCRYPT_ENABLED

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
extern void example_optiga_init(void);
extern void example_optiga_deinit(void);
#endif



void example_util_encode_rsa_public_key_in_bit_string_format(const uint8_t * n_buffer,
                                                        uint16_t n_length,
                                                        const uint8_t * e_buffer,
                                                        uint16_t e_length,
                                                        uint8_t * pub_key_buffer,
                                                        uint16_t * pub_key_length);

/**
 * Callback when optiga_crypt_xxxx operation is completed asynchronously
 */
static volatile optiga_lib_status_t optiga_lib_status;
//lint --e{818} suppress "argument "context" is not used in the sample provided"
static void optiga_crypt_callback(void * context, optiga_lib_status_t return_status)
{
    optiga_lib_status = return_status;
    if (NULL != context)
    {
        // callback to upper layer here
    }
}

// RSA 1024 public key
static const uint8_t rsa_public_key_modulus [] =
{
    //Public key modulus
	0xD6, 0x79, 0x78, 0x52, 0xFD, 0x1C, 0x66, 0x01, 0x20, 0x6A, 0x4A, 0x7F, 0x24, 0x54, 0xF1, 0xC2,
	0x86, 0xEB, 0x1A, 0xC5, 0xFF, 0xC2, 0xEB, 0x29, 0xE6, 0x2A, 0x8F, 0x3E, 0xFF, 0xF1, 0x92, 0x62,
	0xFD, 0x20, 0xEB, 0x8C, 0xCC, 0xA3, 0x13, 0x4E, 0x15, 0x28, 0x1D, 0xE3, 0x0A, 0x1A, 0x7B, 0x85,
	0x16, 0xC4, 0xEA, 0x69, 0x6F, 0x75, 0x60, 0x43, 0x62, 0x85, 0x2B, 0x3C, 0xB1, 0x4A, 0xBF, 0xDF,
	0xB5, 0x33, 0x00, 0x6F, 0x4D, 0xF7, 0x87, 0x34, 0xB9, 0x4A, 0xF3, 0x07, 0xD6, 0x84, 0x3E, 0x4A,
	0x9B, 0x16, 0xDD, 0x39, 0xFA, 0x32, 0x7F, 0xAA, 0x13, 0x6A, 0xDB, 0x0D, 0x69, 0x42, 0x16, 0xF4,
	0x63, 0xEF, 0xD4, 0xA4, 0xB2, 0x0E, 0x1E, 0xD6, 0x29, 0x11, 0xFF, 0xAF, 0xAC, 0x72, 0xF6, 0x3E,
	0x4C, 0xDB, 0x0D, 0xBC, 0x62, 0x09, 0xE7, 0xF6, 0xD7, 0x44, 0x10, 0x1B, 0x56, 0xB9, 0x42, 0x21,
};

// RSA 1024 public key
static const uint8_t rsa_public_key_exponent [] =
{
    //Public Exponent
    0x00, 0x01, 0x00, 0x01
};

static uint8_t rsa_public_key[150] = {0x00};
static uint16_t rsa_public_key_length = 0;

/**
 * The below example demonstrates RSA encryption
 * #optiga_crypt_rsa_encrypt_message where message is provided by user
 *
 */
void optiga_crypt_rsa_encrypt_message_wrapper(uint8_t message[], uint8_t message_length, uint8_t encrypted_message[], uint16_t* encrypted_message_length)
{
    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    optiga_rsa_encryption_scheme_t encryption_scheme;
    public_key_from_host_t public_key_from_host;

    optiga_crypt_t * me = NULL;

    do
    {

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
        /**
         * Open the application on OPTIGA which is a precondition to perform any other operations
         * using optiga_util_open_application
         */
        example_optiga_init();
#endif //OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY

        /**
         * 1. Create OPTIGA Crypt Instance
         *
         */
        me = optiga_crypt_create(0, optiga_crypt_callback, NULL);
        if (NULL == me)
        {
            break;
        }

        /**
         * 2. RSA encryption
         */
        // Form rsa public key in bit string format
        example_util_encode_rsa_public_key_in_bit_string_format(rsa_public_key_modulus,
                                                           sizeof(rsa_public_key_modulus),
                                                           rsa_public_key_exponent,
                                                           sizeof(rsa_public_key_exponent),
                                                           rsa_public_key,
                                                           &rsa_public_key_length);

        encryption_scheme = OPTIGA_RSAES_PKCS1_V15;
        public_key_from_host.public_key = rsa_public_key;
        public_key_from_host.length = rsa_public_key_length;
        public_key_from_host.key_type = (uint8_t)OPTIGA_RSA_KEY_1024_BIT_EXPONENTIAL;
        optiga_lib_status = OPTIGA_LIB_BUSY;


        return_status = optiga_crypt_rsa_encrypt_message(me,
                                                            encryption_scheme,
                                                            message,
															message_length,
                                                            NULL,
                                                            0,
                                                            OPTIGA_CRYPT_HOST_DATA,
                                                            &public_key_from_host,
                                                            encrypted_message,
                                                            encrypted_message_length);

        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);


        return_status = OPTIGA_LIB_SUCCESS;

    } while (FALSE);
    OPTIGA_EXAMPLE_LOG_STATUS(return_status);

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
    /**
     * Close the application on OPTIGA after all the operations are executed
     * using optiga_util_close_application
     */
    example_optiga_deinit();
#endif //OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY

    if (me)
    {
        //Destroy the instance after the completion of usecase if not required.
        return_status = optiga_crypt_destroy(me);
    }

}
#endif  //OPTIGA_CRYPT_RSA_ENCRYPT_ENABLED

// Hash
// Encrypt Hash with PV


uint8_t optiga_crypt_rsa_verify_message_wrapper(uint8_t message[], uint8_t message_length, uint8_t signature[], uint16_t signature_length)
{
	uint8_t hashed_digest[32];
	uint8_t decrypted_digest[32];
	uint16_t decrypted_digest_length;
	// Get digest
	optiga_crypt_hash_data_wrapper(message, message_length, hashed_digest);
	// Decrypt digest with public key => received digest
	optiga_crypt_rsa_encrypt_message_wrapper(signature, signature_length, decrypted_digest, &decrypted_digest_length);
	// compare digest
	if (hashed_digest[0] == decrypted_digest[0])
	{
		return true;
	}
	return false;
}


uint8_t optiga_crypt_rsa_verify_wrapper(uint8_t message[], uint8_t message_length, uint8_t signature[], uint16_t signature_length)
{
	uint8_t succes = false;
	uint8_t hashed_digest  [] =
	{
	    0x91, 0x70, 0x02, 0x48, 0x3F, 0xBD, 0x5F, 0xDD, 0xD5, 0x38, 0xEB, 0xDA, 0x9A, 0x5E, 0x1F, 0x46,
	    0xFC, 0xAD, 0x8F, 0x1E, 0x2C, 0x75, 0xB0, 0x83, 0xD0, 0x71, 0x2B, 0x80, 0xD4, 0xAA, 0xC6, 0x9B
	};
	optiga_crypt_hash_data_wrapper(message, message_length, hashed_digest);

	uint8_t signature2 [] =
	{
	    0x5B, 0xDE, 0x46, 0xE4, 0x35, 0x48, 0xF4, 0x81, 0x45, 0x7C, 0x72, 0x31, 0x54, 0x55, 0xE8, 0x9F,
	    0x1D, 0xD0, 0x5D, 0x9D, 0xEC, 0x40, 0xE6, 0x6B, 0x89, 0xF3, 0xBC, 0x52, 0x68, 0xB1, 0xD8, 0x70,
	    0x35, 0x05, 0xFC, 0x98, 0xF6, 0x36, 0x99, 0x24, 0x53, 0xF0, 0x17, 0xB8, 0x9B, 0xD4, 0xA0, 0x5F,
	    0x12, 0x04, 0x8A, 0xA1, 0xA7, 0x96, 0xE6, 0x33, 0xCA, 0x48, 0x84, 0xD9, 0x00, 0xE4, 0xA3, 0x8E,
	    0x2F, 0x6F, 0x3F, 0x6D, 0xE0, 0x1D, 0xF8, 0xEA, 0xE0, 0x95, 0xBA, 0x63, 0x15, 0xED, 0x7B, 0x6A,
	    0xB6, 0x6E, 0x20, 0x17, 0xB5, 0x64, 0xDE, 0x49, 0x64, 0x97, 0xCA, 0x5E, 0x4D, 0x84, 0x63, 0xA0,
	    0xF1, 0x00, 0x6C, 0xEE, 0x70, 0x89, 0xD5, 0x6E, 0xC5, 0x05, 0x31, 0x0D, 0xAA, 0xB7, 0xBA, 0xA0,
	    0xAA, 0xBF, 0x98, 0xE8, 0x39, 0x93, 0x70, 0x07, 0x2D, 0xFF, 0x42, 0xF9, 0xA4, 0x6F, 0x1B, 0x00
	};
    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    optiga_crypt_t * me = NULL;
    uint32_t time_taken = 0;

    // Form rsa public key in bit string format
    example_util_encode_rsa_public_key_in_bit_string_format(rsa_public_key_modulus,
                                                       sizeof(rsa_public_key_modulus),
                                                       rsa_public_key_exponent,
                                                       sizeof(rsa_public_key_exponent),
                                                       rsa_public_key,
                                                       &rsa_public_key_length);

    public_key_from_host_t public_key_details =
    {
         rsa_public_key,
         rsa_public_key_length,
         (uint8_t)OPTIGA_RSA_KEY_1024_BIT_EXPONENTIAL
    };

    do
    {

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
        /**
         * Open the application on OPTIGA which is a precondition to perform any other operations
         * using optiga_util_open_application
         */
        example_optiga_init();
#endif //OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY

        /**
         * 1. Create OPTIGA Crypt Instance
         */
        me = optiga_crypt_create(0, optiga_crypt_callback, NULL);
        if (NULL == me)
        {
            break;
        }

        /**
         * 2. Verify RSA signature using public key from host
         */
        optiga_lib_status = OPTIGA_LIB_BUSY;


        return_status = optiga_crypt_rsa_verify (me,
                                                 OPTIGA_RSASSA_PKCS1_V15_SHA256,
												 hashed_digest,
                                                 sizeof(hashed_digest),
												 signature2,
												 signature_length,
                                                 OPTIGA_CRYPT_HOST_DATA,
                                                 &public_key_details,
                                                 0x0000);

        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);

        READ_PERFORMANCE_MEASUREMENT(time_taken);

        return_status = OPTIGA_LIB_SUCCESS;
    } while (FALSE);
    OPTIGA_EXAMPLE_LOG_STATUS(return_status);

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
    /**
     * Close the application on OPTIGA after all the operations are executed
     * using optiga_util_close_application
     */
    example_optiga_deinit();
#endif //OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
    OPTIGA_EXAMPLE_LOG_PERFORMANCE_VALUE(time_taken, return_status);

    if (me)
    {
        //Destroy the instance after the completion of usecase if not required.
        return_status = optiga_crypt_destroy(me);
    	succes = true;

    }
    return succes;
}


