#include "../SEMS_Headers/Nonce.h"

#include "../SEMS_Headers/Util.h"


void optiga_util_read_nonce(uint16_t optiga_oid, uint8_t read_data_buffer[], uint16_t bytes_to_read)
{
    uint16_t offset = 0x00;
    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    optiga_util_t * me = NULL;

    do
    {
        example_optiga_init();

        me = optiga_util_create_wrapper();
        if (NULL == me)
        {
            break;
        }

        optiga_lib_status = OPTIGA_LIB_BUSY;



        return_status = optiga_util_read_data(me,
                                              optiga_oid,
                                              offset,
                                              read_data_buffer,
                                              &bytes_to_read);

        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);


        return_status = OPTIGA_LIB_SUCCESS;
    } while (FALSE);

    example_optiga_deinit();

    if (me)
    {
        return_status = optiga_util_destroy(me);
    }
}


void optiga_util_update_count_wrapper(uint16_t optiga_counter_oid, uint8_t ticks)
{

    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    optiga_util_t * me = NULL;

    do
    {
        example_optiga_init();

        me = optiga_util_create_wrapper();
        if (NULL == me)
        {
            break;
        }

        optiga_lib_status = OPTIGA_LIB_BUSY;
        return_status = optiga_util_update_count(me,
                                                 optiga_counter_oid,
												 ticks);


        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);

        return_status = OPTIGA_LIB_SUCCESS;
    } while (FALSE);

    example_optiga_deinit();


    if (me)
    {
    	return_status = optiga_util_destroy(me);

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
    uint8_t offset;

    optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;
    optiga_util_t * me = NULL;

    do
    {

        example_optiga_init();

        me = optiga_util_create_wrapper();
        if (NULL == me)
        {
            break;
        }

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

    example_optiga_deinit();

    if (me)
    {
    	return_status = optiga_util_destroy(me);
    }
}
