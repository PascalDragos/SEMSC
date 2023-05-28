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
#include "../SEMS_Headers/RSA.h"
#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/Unlock.h"
#include "../SEMS_Headers/Com.h"
#include "../SEMS_Headers/Hash.h"
#include "../SEMS_Headers/Patcher.h"

extern void example_optiga_crypt_rsa_encrypt_message(void);


extern pal_logger_t logger_console;

//const uint8_t key[] = {
//    //00    01    02    03    04    05    06    07    08    09    0A    0B    0C    0D    0E    0F
//    0x18, 0x02, 0x30, 0x04, 0x30, 0x82, 0x02, 0x05, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x09, 0x00,
//    0x9B, 0x0C, 0x24, 0xB4, 0x5E, 0x7D, 0xE3, 0x73, 0x30, 0x0A, 0x06, 0x08, 0x2A, 0x86, 0x48, 0x31,
//    };

// Generat cu optiga
const uint8_t key[] = {
    //00    01    02    03    04    05    06    07    08    09    0A    0B    0C    0D    0E    0F
	0xcf, 0xdc, 0xcc, 0x0b, 0x9d, 0x7b, 0x78, 0x41, 0x44, 0xff, 0x29, 0x91, 0xd5, 0xea, 0x7b, 0xd2,
	0xcd, 0x89, 0x7f, 0x95, 0x1a, 0x38, 0xc2, 0x58, 0x25, 0x6d, 0x3c, 0x93, 0x3d, 0xdb, 0x0a, 0x76,
    };

extern void example_optiga_crypt_rsa_verify(void);

#define MAX_FAILED_REQ 1
volatile uint8_t failed_req = 0;
volatile uint8_t cooldowned = false;

void my_optiga_shell_begin(void)
{
	uint8_t sec_unlocked = false;
	uint8_t sec_comm = false;

	// Toate comenzile au 32 de bytes
	uint8_t command[32];

    // Se foloseste doar o data in productie, nu la fiecare rulare
//    optiga_util_write_shared_key(0xF1E0, key, sizeof(key));

    example_optiga_crypt_rsa_verify();

	while(true)
	{

		// Wrapper for serial read
		if(0 == read_request(command, sec_unlocked, sec_comm))
		{
			if(true == cooldowned)
			{
				uint8_t buff[32] = {"Denied by cooldown."};
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


			// Cooldown
			failed_req++;
			if(failed_req >= MAX_FAILED_REQ)
			{
				if(cooldowned)
				{
					uint8_t buff[32] = {"Denied by cooldown."};
					optiga_lib_print_bytes(buff, 32);
				}
				else
				{
					uint8_t buff[32] = {"Cooldown activated."};
					uint32_t timeout;
					optiga_lib_print_bytes(buff, 32);

					timeout = 5; // sec
					timeout = timeout * 1000 * 1000 ; // us
					TIMER_SetTimeInterval(&TIMER_Cooldwon, failed_req);
					TIMER_Start(&TIMER_Cooldwon);
					cooldowned = true;
				}
			}
			else
			{
				uint8_t buff[32] = {"Request denied."};
				optiga_lib_print_bytes(buff, 32);
			}
		}

	}
}


void TimerInterval_ISR(void)
{
	if(faile_req > 0)
	{
		failed_req--;
	}
	if(failed_req == 0)
	{
		cooldowned = false;
	}
}


void my_optiga_shell_begin_test(void)
{

    while(TRUE)
    {


//    	// Apoi asteapta SecOC
//
//
//    	// Apoi asteata comenzi obisnuite
//        if (0 == pal_logger_read(&logger_console, &command, 1))
//        {
//        	switch(command)
//        	{
//        	case 'U':
//        		secure_unlock();
//        		break;
//        	case 'C':
//        		// optiga_lib_print_string_with_newline("COM");
//        		secure_communication();
//        		break;
//        	case 'H':
//				//optiga_lib_print_string_with_newline("COM");
//
//        		break;
//        	default:
//        		optiga_lib_print_string_with_newline("IDK");
//        	}
//
//        }
    }
}
