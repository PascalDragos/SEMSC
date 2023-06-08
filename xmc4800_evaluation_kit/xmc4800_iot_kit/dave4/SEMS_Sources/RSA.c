#include "../SEMS_Headers/RSA.h"
#include "../SEMS_Headers/Hash.h"
#include "../SEMS_Headers/Constructor.h"

#include "../SEMS_Headers/Util.h"



void example_util_encode_rsa_public_key_in_bit_string_format(const uint8_t * n_buffer,
                                                        uint16_t n_length,
                                                        const uint8_t * e_buffer,
                                                        uint16_t e_length,
                                                        uint8_t * pub_key_buffer,
                                                        uint16_t * pub_key_length);


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


void optiga_crypt_rsa_encrypt_message_wrapper(uint8_t message[], uint8_t message_length, uint8_t encrypted_message[], uint16_t* encrypted_message_length)
{
    optiga_crypt_t * me = NULL;
    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;

    optiga_rsa_encryption_scheme_t encryption_scheme;
    public_key_from_host_t public_key_from_host;

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


    do
    {
        example_optiga_init();

        me = optiga_crypt_create_wrapper();
        if (NULL == me)
        {
            break;
        }

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


    } while (FALSE);

    example_optiga_deinit();


    if (NULL != me)
    {
       optiga_crypt_destroy(me);
    }
}


uint8_t optiga_crypt_rsa_verify_wrapper(uint8_t message[], uint8_t message_length, uint8_t signature[], uint16_t signature_length)
{
	uint8_t success = false;
	uint8_t hashed_digest[32];

	optiga_crypt_hash_data_wrapper(message, message_length, hashed_digest);
//	hashed_digest[5] = 5; Pentru a verifica ca si cazul negativ

    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    optiga_crypt_t * me = NULL;


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

        example_optiga_init();

        me = optiga_crypt_create_wrapper();
        if (NULL == me)
        {
            break;
        }

        optiga_lib_status = OPTIGA_LIB_BUSY;


        return_status = optiga_crypt_rsa_verify (me,
                                                 OPTIGA_RSASSA_PKCS1_V15_SHA256,
												 hashed_digest,
                                                 sizeof(hashed_digest),
												 signature,
												 signature_length,
                                                 OPTIGA_CRYPT_HOST_DATA,
                                                 &public_key_details,
                                                 0x0000);

        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);

        /* RSA verify result
         * 0x0000 -> signature match
         * 0x082c -> signature doesn't match
         */
        if(0 == return_status)
        {
        	success = true;
        }

    } while (FALSE);

    example_optiga_deinit();

    if (NULL != me)
    {
         optiga_crypt_destroy(me);
    }

    return success;
}


