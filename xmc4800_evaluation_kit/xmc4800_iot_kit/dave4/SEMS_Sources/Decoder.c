#include "../SEMS_Headers/Decoder.h"

req_type decode_req(uint8_t command[32])
{
	// Activate secure unlock
	if(0 == strcmp((char *)command, "Unlock"))
	{
		return SEC_UNLOCK;
	}

	// Activate secure communication
	if(0 == strcmp((char *)command, "SecCom"))
	{
		return SEC_COM;
	}

	// Lock
	if(0 == strcmp((char *)command, "Lock"))
	{
		return SEC_LOCK;

	}

	// Usual command
	if(0 == strcmp((char *)command, "Command"))
	{
		return EXAMPLE;
	}

	return UNKNOWN;
}






