#include "../SEMS_Headers/Constructor.h"
#include "../SEMS_Headers/Config.h"

// in Util.h: extern volatile optiga_lib_status_t optiga_lib_status;
volatile optiga_lib_status_t optiga_lib_status;


static void optiga_crypt_callback(void * const context, optiga_lib_status_t return_status)
{
    optiga_lib_status = return_status;
    if (NULL != context)
    {
        // callback to upper layer here
    }
}


static void optiga_util_callback(void * const context, optiga_lib_status_t return_status)
{
    optiga_lib_status = return_status;
    if (NULL != context)
    {
        // callback to upper layer here
    }
}



optiga_crypt_t * optiga_crypt_create_wrapper(void)
{
	optiga_crypt_t * me;
	me = optiga_crypt_create(0, optiga_crypt_callback, NULL);
#if LIFECYCLE==PRODUCTION
	OPTIGA_CRYPT_SET_COMMS_PROTECTION_LEVEL(me, OPTIGA_COMMS_FULL_PROTECTION);
#else
	OPTIGA_CRYPT_SET_COMMS_PROTECTION_LEVEL(me, OPTIGA_COMMS_NO_PROTECTION);
#endif

	return me;
}


optiga_util_t * optiga_util_create_wrapper(void)
{
	optiga_util_t * me;
	me = optiga_util_create(0, optiga_util_callback, NULL);

#if LIFECYCLE==PRODUCTION
	OPTIGA_UTIL_SET_COMMS_PROTECTION_LEVEL(me, OPTIGA_COMMS_FULL_PROTECTION);
#else
	OPTIGA_UTIL_SET_COMMS_PROTECTION_LEVEL(me, OPTIGA_COMMS_NO_PROTECTION);
#endif

	return me;
}
