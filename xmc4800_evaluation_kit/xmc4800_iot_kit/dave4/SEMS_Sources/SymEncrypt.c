#include "optiga/optiga_util.h"
#include "optiga_example.h"
#include <DAVE.h>

#include "../SEMS_Headers/SymEncrypt.h"

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
extern void example_optiga_init(void);
extern void example_optiga_deinit(void);
#endif




void stream_enc(uint8_t r1[], uint8_t r2[], uint8_t len)
{
    unsigned int i;
    for (i = 0; i < len; ++i)
    {
        r1[i] = r1[i] ^ r2[i];

    }
}

uint8_t compare_bytes(uint8_t a[], uint8_t b[], uint8_t len)
{
	uint8_t is_equal = true;
	uint8_t i;
	for (i = 0; i < len; ++i)
	{
		if(a[i] != b[i])
		{
			is_equal = false; // MISRA single exit
			break;
		}
	}
	return is_equal;
}


static volatile optiga_lib_status_t optiga_lib_status;
//lint --e{818} suppress "argument "context" is not used in the sample provided"
static void optiga_util_callback(void * context, optiga_lib_status_t return_status)
{
    optiga_lib_status = return_status;
    if (NULL != context)
    {
        // callback to upper layer here
    }
}

static volatile optiga_lib_status_t optiga_lib_status;



void optiga_util_write_shared_key(uint16_t optiga_oid, const uint8_t key[], uint16_t bytes_to_write)
{
    uint16_t offset = 0;

    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    optiga_util_t * me = NULL;

    do
    {

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
        /**
         * Open the application on OPTIGA which is a precondition to perform any other operations
         * using optiga_util_open_application
         */
        example_optiga_init();
#endif //OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY




        me = optiga_util_create(0, optiga_util_callback, NULL);
        if (NULL == me)
        {
            break;
        }


//        OPTIGA_UTIL_SET_COMMS_PROTECTION_LEVEL(me, OPTIGA_COMMS_NO_PROTECTION);

        optiga_lib_status = OPTIGA_LIB_BUSY;


        return_status = optiga_util_write_data(me,
                                               optiga_oid,
                                               OPTIGA_UTIL_ERASE_AND_WRITE,
                                               offset,
                                               key,
											   bytes_to_write);

        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);


        return_status = OPTIGA_LIB_SUCCESS;

    } while (FALSE);


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
        return_status = optiga_util_destroy(me);
        if(OPTIGA_LIB_SUCCESS != return_status)
        {
            //lint --e{774} suppress This is a generic macro

        }
    }

}


/**
 * The below example demonstrates read data/metadata functionalities
 *
 * Example for #optiga_util_read_data and #optiga_util_read_metadata
 *
 */
void optiga_util_read_shared_key(uint16_t optiga_oid, uint8_t read_data_buffer[], uint16_t bytes_to_read)
{
    uint16_t offset = 0x00;
    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    optiga_util_t * me = NULL;

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
         * 1. Create OPTIGA Util Instance
         */
        me = optiga_util_create(0, optiga_util_callback, NULL);
        if (NULL == me)
        {
            break;
        }


        // OPTIGA Comms Shielded connection settings to enable the protection
//        OPTIGA_UTIL_SET_COMMS_PROTOCOL_VERSION(me, OPTIGA_COMMS_PROTOCOL_VERSION_PRE_SHARED_SECRET);
//        OPTIGA_UTIL_SET_COMMS_PROTECTION_LEVEL(me, OPTIGA_COMMS_RESPONSE_PROTECTION);

        /**
         * 2. Read data from a data object (e.g. certificate data object)
         *    using optiga_util_read_data.
         */
        optiga_lib_status = OPTIGA_LIB_BUSY;



        return_status = optiga_util_read_data(me,
                                              optiga_oid,
                                              offset,
                                              read_data_buffer,
                                              &bytes_to_read);

        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);


        return_status = OPTIGA_LIB_SUCCESS;
    } while (FALSE);


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
        return_status = optiga_util_destroy(me);
    }
}
