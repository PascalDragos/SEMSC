#include "../SEMS_Headers/ECC.h"
#include "../SEMS_Headers/Util.h"
#include "../SEMS_Headers/Constructor.h"


static const uint8_t digest [] =
{
    // Size of digest to be chosen based on Curve
    0x61, 0xC7, 0xDE, 0xF9, 0x0F, 0xD5, 0xCD, 0x7A,0x8B, 0x7A, 0x36, 0x41, 0x04, 0xE0, 0x0D, 0x82,
    0x38, 0x46, 0xBF, 0xB7, 0x70, 0xEE, 0xBF, 0x8F,0x40, 0x25, 0x2E, 0x0A, 0x21, 0x42, 0xAF, 0x9C,
};


volatile int res;
void example_optiga_crypt_ecc_generate_keypair_wrapper(void)
{
    volatile optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    optiga_key_id_t optiga_key_id = OPTIGA_KEY_ID_E0F1;
    uint8_t public_key [100];
    uint16_t public_key_length = sizeof(public_key);
    uint8_t signature [80];
    uint16_t signature_length = sizeof(signature);

    optiga_crypt_t * crypt_me = NULL;

    do
    {
        crypt_me = optiga_crypt_create_wrapper();
        if (NULL == crypt_me)
        {
            break;
        }


        optiga_lib_status = OPTIGA_LIB_BUSY;
        return_status = optiga_crypt_ecc_generate_keypair(crypt_me,
                                                          OPTIGA_ECC_CURVE_NIST_P_256,
                                                          (uint8_t)OPTIGA_KEY_USAGE_SIGN,
                                                          FALSE,
                                                          &optiga_key_id,
                                                          public_key,
                                                          &public_key_length);
        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);
        return_status = OPTIGA_LIB_SUCCESS;

        optiga_lib_status = OPTIGA_LIB_BUSY;
		return_status = optiga_crypt_ecdsa_sign(crypt_me,
												  digest,
												  sizeof(digest),
												  OPTIGA_KEY_ID_E0F0,
												  signature,
												  &signature_length);

		  WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);

		  optiga_lib_status = OPTIGA_LIB_BUSY;
			 return_status = optiga_crypt_ecdsa_verify (crypt_me,
														digest,
														sizeof(digest),
														signature,
														signature_length,
														OPTIGA_CRYPT_HOST_DATA,
														&public_key);

			 WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);


    } while (FALSE);


    example_optiga_deinit();


    if (NULL != crypt_me)
    {
       optiga_crypt_destroy(crypt_me);
    }
    res = public_key[0]; // for breakpoint
}

