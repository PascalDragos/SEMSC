#include <DAVE.h>
#include "optiga/optiga_crypt.h"
#include "optiga/optiga_util.h"
#include "optiga/common/optiga_lib_logger.h"
#include "optiga/pal/pal_os_event.h"
#include "optiga/pal/pal.h"
#include "optiga/pal/pal_os_timer.h"
#include "optiga_example.h"
#include "optiga/pal/pal_logger.h"


#include "../SEMS_Headers/Random.h"

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
extern void example_optiga_init(void);
extern void example_optiga_deinit(void);
#endif
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


void optiga_crypt_random_wrapper(uint8_t random_buff[], uint8_t size)
{
	optiga_crypt_t * me = NULL;
	optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;

	do
	{
#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
		/**
		 * Open the application on OPTIGA which is a precondition to perform any other operations
		 * using optiga_util_open_application
		 */
		example_optiga_init();
#endif //OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY

		me = optiga_crypt_create(0, optiga_crypt_callback, NULL);
		if (NULL == me)
		{
			break;
		}

		optiga_lib_status = OPTIGA_LIB_BUSY;

		return_status = optiga_crypt_random(me,
											OPTIGA_RNG_TYPE_TRNG,
											random_buff,
											size);

		WAIT_AND_CHECK_STATUS(return_status, optiga_lib_status);


	} while (FALSE);

#ifndef OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY
	example_optiga_deinit();
#endif //OPTIGA_INIT_DEINIT_DONE_EXCLUSIVELY

	if (me)
	{
		//Destroy the instance after the completion of usecase if not required.
		return_status = optiga_crypt_destroy(me);
	}


}
