#include "Dave.h"
#include "optiga_example.h"
#include "optiga/optiga_util.h"
#include "optiga/pal/pal_logger.h"
#include "../SEMS_Headers/Patcher.h"

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
extern void example_optiga_init(void);
extern void example_optiga_deinit(void);
#endif


/**
 * Callback when optiga_util_xxxx operation is completed asynchronously
 */
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


extern pal_logger_t logger_console;
extern uint32_t user_token;


uint8_t read_request(uint8_t command[], uint8_t is_secure_com)
{
	uint8_t invalid_req = false;


	if (0 == pal_logger_read(&logger_console, command, 32))
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
				invalid_req = true;
			}

		}
		else
		{



			// Extract Hash

			// Calculate Hash

			// Compare digests


			// Retrive Session Key


			// Decrypt ciphertext


			// Extract Token


			// Extract Nonce
			uint8_t *received_user_nonce_start = command + 20;
			uint8_t nonce[4];
			uint16_t optiga_counter_oid = 0xE120;


			// Read Nonce from Optiga
			optiga_util_read_nonce(optiga_counter_oid, nonce, sizeof(nonce));

			// Compare Nonces
			if(0 != memcmp(nonce, received_user_nonce_start, sizeof(nonce)))
			{
				invalid_req = true;
			}

			// Extract command to be returned



		}

	}
	else
	{
		invalid_req = true;
	}
	return invalid_req;
}



void optiga_util_read_nonce(uint16_t optiga_oid, uint8_t read_data_buffer[], uint16_t bytes_to_read)
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





void optiga_util_update_count_wrapper(uint16_t optiga_counter_oid, uint8_t ticks)
{
    uint32_t time_taken = 0;


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

        OPTIGA_EXAMPLE_LOG_MESSAGE(__FUNCTION__);
        /**
         * 1. Create OPTIGA Util Instance
         */
        me = optiga_util_create(0, optiga_util_callback, NULL);
        if (NULL == me)
        {
            break;
        }

        /**
         * Pre-condition
         * Any data object can be converted to counter data object by changing metadata as mentioned below:
         * - As precondition  write access should be always or LCSO < OPERATIONAL
         * - Write metadata as "0xD0, 0x01, 0x01" using #optiga_util_write_metadata
        */

        /**
         * Write default count and threshold value to counter data object (e.g. E120)
         * using optiga_util_write_data.
         *
         * Use Erase and Write (OPTIGA_UTIL_ERASE_AND_WRITE) option,
         * in order to correctly update the used length of the object.
         */
        optiga_counter_oid = 0xE120;



        START_PERFORMANCE_MEASUREMENT(time_taken);


        // In this example, the counter is update by 5 and the final count would be 15
        optiga_lib_status = OPTIGA_LIB_BUSY;
        return_status = optiga_util_update_count(me,
                                                 optiga_counter_oid,
												 ticks);


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
        return_status = optiga_util_destroy(me);
        if(OPTIGA_LIB_SUCCESS != return_status)
        {
            //lint --e{774} suppress This is a generic macro
            OPTIGA_EXAMPLE_LOG_STATUS(return_status);
        }
    }
}


void optiga_util_reset_count(uint16_t optiga_counter_oid)
{
	const uint8_t initial_counter_object_data [] =
	{
	    // Initial counter value
	    0x00, 0x00, 0x00, 0x02,
	    // Maximum counter value
	    0xFF, 0xFF, 0xFF, 0xFF,
	};
    uint32_t time_taken = 0;
    uint8_t offset;

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

        OPTIGA_EXAMPLE_LOG_MESSAGE(__FUNCTION__);
        /**
         * 1. Create OPTIGA Util Instance
         */
        me = optiga_util_create(0, optiga_util_callback, NULL);
        if (NULL == me)
        {
            break;
        }

        /**
         * Pre-condition
         * Any data object can be converted to counter data object by changing metadata as mentioned below:
         * - As precondition  write access should be always or LCSO < OPERATIONAL
         * - Write metadata as "0xD0, 0x01, 0x01" using #optiga_util_write_metadata
        */

        /**
         * Write default count and threshold value to counter data object (e.g. E120)
         * using optiga_util_write_data.
         *
         * Use Erase and Write (OPTIGA_UTIL_ERASE_AND_WRITE) option,
         * in order to correctly update the used length of the object.
         */

        offset = 0x00;
        optiga_lib_status = OPTIGA_LIB_BUSY;


        return_status = optiga_util_write_data(me,
                                               optiga_counter_oid,
                                               OPTIGA_UTIL_ERASE_AND_WRITE,
                                               offset,
                                               initial_counter_object_data,
                                               sizeof(initial_counter_object_data));

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

    OPTIGA_EXAMPLE_LOG_PERFORMANCE_VALUE(time_taken, return_status);

    if (me)
    {
        //Destroy the instance after the completion of usecase if not required.
        return_status = optiga_util_destroy(me);
        if(OPTIGA_LIB_SUCCESS != return_status)
        {

        }
    }
}
