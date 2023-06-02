#include <DAVE.h>
#include "optiga/optiga_crypt.h"
#include "optiga/optiga_util.h"
#include "optiga/common/optiga_lib_logger.h"
#include "optiga/pal/pal_os_event.h"
#include "optiga/pal/pal.h"
#include "optiga/pal/pal_os_timer.h"
#include "optiga_example.h"
#include "optiga/pal/pal_logger.h"


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
#include "../SEMS_Headers/Decoder.h"

extern pal_logger_t logger_console;



volatile uint8_t failed_req = 0;
volatile uint8_t cooldowned = false;


void my_optiga_shell_begin(void)
{

	uint8_t sec_unlocked = false;
	uint8_t sec_comm = false;

	// Toate comenzile au 32 de bytes
	uint8_t command[32];

#if LIFECYCLE==TESTING
	uint8_t is_testing = true;
	while(is_testing)
	{
		testing();
	}
#endif

	init_SEMS();

	while(true)
	{

		// Wrapper for serial read
		if(0u == read_request(command, sec_unlocked, sec_comm))
		{

			if(true == cooldowned)
			{
				uint8_t buff[32] = "Denied by cooldown.";
				optiga_lib_print_bytes(buff, 32);
				continue;
			}


			// Activate secure unlock
			if(command[0] == 'U')
			{

				sec_unlocked = secure_unlock();
				sec_comm = 0;  // reset sec_comm flag
				continue;
			}


			// Activate secure communication
			if(command[0] == 'C') // momentatn nu pot da 2 cereri de sec com
			{
				sec_comm = secure_communication();
				continue;
			}


			// Lock
			if(command[0] == 'L')
			{
				uint8_t buff[32] = {"Locked"};

				sec_unlocked = 0;

				write_request(buff, sec_comm);
				continue;
			}

			// Usual command
			if(command[0] == 'A')
			{
				uint8_t buff[32] = {"AABBCCDEFG"};
				write_request(buff, sec_comm);
				continue;
			}

			// Uknow request
			uint8_t buff[32] = {"Unknown request"};
			write_request(buff, sec_comm);

		}
		else
		{
			// Req before unlock || invalid Token, Nonce, Hash

			failed_req++;
			if(true == cooldowned)
			{
				uint8_t buff[32] = "Denied by cooldown.";
				optiga_lib_print_bytes(buff, 32);
			}
			else
			{
				if(failed_req >= MAX_FAILED_REQ)
				{
					uint8_t buff[32] = "Cooldown activated.";
					optiga_lib_print_bytes(buff, 32);
					cooldowned = true;
				}
				else
				{
					// Just a wrong request
					uint8_t buff[32] = "Request denied.";
					optiga_lib_print_bytes(buff, 32);
				}
			}

		}

	}
}






