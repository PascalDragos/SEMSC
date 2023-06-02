#include "../SEMS_Headers/Decoder.h"

req_type decode_req(uint8_t command[32])
{
	req_type response;

	response = 5;
	// Activate secure unlock
	if(0 == strncmp((char *)command, "Unlock", 1))
	{
		response = SEC_UNLOCK;
	}

	// Activate secure communication
	if(command[0] == 'C')
	{
		response = SEC_COM;

	}

	// Lock
	if(command[0] == 'L')
	{
		response = SEC_LOCK;

	}

	// Usual command
	if(command[0] == 'A')
	{
		response = EXAMPLE;

	}

	return response;
}






