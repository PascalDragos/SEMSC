#include "../SEMS_Headers/Random.h"
#include "../SEMS_Headers/Constructor.h"


#include "../SEMS_Headers/Util.h"




void optiga_crypt_random_wrapper(uint8_t random_buff[], uint8_t size)
{
	optiga_crypt_t * me = NULL;
	optiga_lib_status_t return_status = !OPTIGA_LIB_SUCCESS;

	do
	{
		example_optiga_init();

		me = optiga_crypt_create_wrapper();
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

	example_optiga_deinit();

	if (NULL != me)
	{
		optiga_crypt_destroy(me);
	}
}
