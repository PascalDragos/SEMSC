#include <DAVE.h>
#include "optiga/optiga_crypt.h"
#include "optiga/optiga_util.h"
#include "optiga/common/optiga_lib_logger.h"
#include "optiga/pal/pal_os_event.h"
#include "optiga/pal/pal.h"
#include "optiga/pal/pal_os_timer.h"
#include "optiga_example.h"
#include "optiga/pal/pal_logger.h"

#include "optiga_example.h"
#include "optiga/optiga_util.h"
#include "../SEMS_Headers/Timer.h"
#include "../SEMS_Headers/Random.h"
#include "../SEMS_Headers/RSA.h"
#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/Unlock.h"
#include "../SEMS_Headers/Com.h"
#include "../SEMS_Headers/Hash.h"
#include "../SEMS_Headers/Patcher.h"
#include "../SEMS_Headers/Config.h"
#include "../SEMS_Headers/Init.h"
#include "../SEMS_Headers/Test.h"

#include "../SEMS_Headers/Util.h"


void testing(void)
{
	uint8_t i = 0;
	uint8_t data_to_hash[32] = {0};
	uint8_t digest[32] = {0};
	uint8_t res;
	for(i = 0; i < sizeof(data_to_hash); ++i)
	{
		data_to_hash[i] = i;
	}
	optiga_crypt_hash_data_wrapper(data_to_hash, sizeof(data_to_hash), digest);
	res = digest[1];
	digest[1] = res;
}
