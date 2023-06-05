#include <DAVE.h>
#include "optiga/optiga_crypt.h"
#include "optiga/optiga_util.h"
#include "optiga/common/optiga_lib_logger.h"
#include "optiga/pal/pal_os_event.h"
#include "optiga/pal/pal.h"
#include "optiga/pal/pal_os_timer.h"
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
	uint8_t command[32];  // Toate comenzile au 32 de bytes

	init_SEMS();

#if LIFECYCLE==TESTING
	uint8_t is_testing = true;
	while(is_testing)
	{
		test();
	}
#endif


	while(true)
	{

		// Wrapper for serial read
		if(0u == read_request(command, sec_unlocked, sec_comm))
		{
			// Valid request
			req_type req_rcv;
			if(true == cooldowned)
			{
				uint8_t buff[32] = "Denied by cooldown.";
				optiga_lib_print_bytes(buff, 32);
				continue;
			}

			req_rcv = decode_req(command);

			switch(req_rcv){
				case SEC_UNLOCK:
				{
					sec_unlocked = secure_unlock();
					sec_comm = 0;  // reset sec_comm flag
					break;
				}
				case SEC_COM: // momentan nu pot da 2 cereri de sec com
				{
					sec_comm = secure_communication();
					break;
				}
				case SEC_LOCK:
				{
					uint8_t buff[32] = "Locked";
					sec_unlocked = 0;
					write_request(buff, sec_comm);
					break;
				}
				case EXAMPLE:
				{
					uint8_t buff[32] = "Command response";
					write_request(buff, sec_comm);
					break;
				}
				case UNKNOWN:
				default:
				{
					uint8_t buff[32] = "Unknown request";
					write_request(buff, sec_comm);
					break;
				}
			}  // end-switch

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






