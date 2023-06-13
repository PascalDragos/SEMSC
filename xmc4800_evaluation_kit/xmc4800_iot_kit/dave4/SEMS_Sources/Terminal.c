#include <DAVE.h>
#include <SEMS_Headers/SecCom.h>
#include <SEMS_Headers/SecUnlock.h>
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
#include "../SEMS_Headers/Hash.h"
#include "../SEMS_Headers/Patcher.h"
#include "../SEMS_Headers/Config.h"
#include "../SEMS_Headers/Init.h"
#include "../SEMS_Headers/Test.h"
#include "../SEMS_Headers/Decoder.h"
#include "../SEMS_Headers/SecNvM.h"


extern pal_logger_t logger_console;
extern void example_optiga_crypt_ecc_generate_keypair_wrapper(void);

volatile uint8_t failed_req = 0;
volatile uint8_t cooldowned = false;


void terminal_main(void)
{

	uint8_t is_sec_unlocked = false;
	uint8_t is_sec_comm = false;
	uint8_t received_request[32];  // Toate comenzile au 32 de bytes

	init_SEMS();


#if LIFECYCLE==TESTING
	uint8_t is_testing = true;
	while(is_testing)
	{
		test();
	}
#endif

#if LIFECYCLE==FACTORY
	while (true)
	{
		write_sec_config();
		optiga_util_reset_count(OPTIGA_NONCE_OID);
	}
#endif


	while(true)
	{

		// Wrapper for serial read, verifies token, nonce, hash
		if(0u == read_and_verify_req(received_request, is_sec_unlocked, is_sec_comm))
		{
			// Valid request
			req_type request_type;
			if(true == cooldowned)
			{
				uint8_t buff[32] = "Denied by cooldown.";
				optiga_lib_print_bytes(buff, 32);
				continue;
			}

			request_type = decode_req(received_request);

			switch(request_type){
				case SEC_UNLOCK:
				{
					is_sec_unlocked = secure_unlock();
					is_sec_comm = 0;  // reset sec_comm flag
					break;
				}
				case SEC_COM: // momentan nu pot da 2 cereri de sec com
				{
					is_sec_comm = secure_communication();
					break;
				}
				case SEC_LOCK:
				{
					uint8_t buff[32] = "Locked";
					is_sec_unlocked = 0;
					write_and_pack_request(buff, is_sec_comm);
					break;
				}
				case EXAMPLE:
				{
					uint8_t buff[32] = "Command response";

					// default behaviour, there would be some processing
					write_and_pack_request(buff, is_sec_comm);
					break;
				}
				case REQUEST:
				{
					uint8_t buff[32] = "Req  response";

					// default behaviour, there would be some processing
					buff[3] = received_request[3];
					write_and_pack_request(buff, is_sec_comm);
					break;
				}
				case UNKNOWN:
				default:
				{
					uint8_t buff[32] = "Unknown request";
					write_and_pack_request(buff, is_sec_comm);
					break;
				}
			}  // end-switch

		}
		else
		{
			// Request before unlock or invalid Token, Nonce, Hash

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






