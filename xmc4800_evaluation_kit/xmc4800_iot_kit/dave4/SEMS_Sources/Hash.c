#include "optiga/optiga_crypt.h"
#include "optiga_example.h"
#include "../SEMS_Headers/Hash.h"

#ifdef OPTIGA_CRYPT_HASH_ENABLED

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
extern void example_optiga_init(void);
extern void example_optiga_deinit(void);
#endif

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


void optiga_crypt_hash_data_wrapper(uint8_t data_to_hash[], uint8_t size_of_data, uint8_t digest[])
{
    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;

    hash_data_from_host_t hash_data_host;


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

        OPTIGA_EXAMPLE_LOG_MESSAGE(__FUNCTION__);

        /**
         * 1. Create OPTIGA Crypt Instance
         */
        me = optiga_crypt_create(0, optiga_crypt_callback, NULL);
        if (NULL == me)
        {
            break;
        }

        /**
         * 2. Initialize the hashing context at OPTIGA
         */
        hash_data_host.buffer = data_to_hash;
        hash_data_host.length = size_of_data;
        optiga_lib_status = OPTIGA_LIB_BUSY;


        return_status = optiga_crypt_hash(me, OPTIGA_HASH_TYPE_SHA_256, OPTIGA_CRYPT_HOST_DATA, &hash_data_host, digest);
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

#endif  //OPTIGA_CRYPT_HASH_ENABLED
/**
* @}
*/
