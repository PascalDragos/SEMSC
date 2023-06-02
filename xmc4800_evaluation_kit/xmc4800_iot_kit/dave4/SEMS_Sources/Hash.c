#include "../SEMS_Headers/Hash.h"
#include "../SEMS_Headers/Constructor.h"

#include "../SEMS_Headers/Util.h"


void optiga_crypt_hash_data_wrapper(uint8_t data_to_hash[], uint8_t size_of_data, uint8_t digest[])
{
    optiga_crypt_t * me = NULL;
    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    hash_data_from_host_t hash_data_host;

    hash_data_host.buffer = data_to_hash;
    hash_data_host.length = size_of_data;
    optiga_lib_status = OPTIGA_LIB_BUSY;

    do
    {
        example_optiga_init();

        me = optiga_crypt_create_wrapper();

        if (NULL == me)
        {
            break;
        }

        return_status = optiga_crypt_hash(me,
										OPTIGA_HASH_TYPE_SHA_256,
										OPTIGA_CRYPT_HOST_DATA,
										&hash_data_host,
										digest);

        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);


    } while (FALSE);

    example_optiga_deinit();

    if (NULL != me)
    {
        optiga_crypt_destroy(me);
    }
}
