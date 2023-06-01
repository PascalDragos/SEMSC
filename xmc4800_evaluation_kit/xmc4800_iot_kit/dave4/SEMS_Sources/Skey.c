#include <SEMS_Headers/Skey.h>

#include "../SEMS_Headers/Util.h"
#include "../SEMS_Headers/Constructor.h"



void optiga_util_write_shared_key(uint16_t optiga_oid, const uint8_t key[], uint16_t bytes_to_write)
{
    uint16_t offset = 0;

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

        return_status = optiga_util_write_data(me,
                                               optiga_oid,
                                               OPTIGA_UTIL_ERASE_AND_WRITE,
                                               offset,
                                               key,
											   bytes_to_write);

        WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);

        return_status = OPTIGA_LIB_SUCCESS;

    } while (FALSE);


    example_optiga_deinit();



    if (me)
    {
        return_status = optiga_util_destroy(me);
    }
}


void optiga_util_read_shared_key(uint16_t optiga_oid, uint8_t read_data_buffer[], uint16_t bytes_to_read)
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
