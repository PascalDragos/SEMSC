#ifndef DECODER_H_
#define DECODER_H_


#include "Dave.h"


typedef enum _req_type {
	SEC_UNLOCK,
	SEC_COM,
	SEC_LOCK,
	EXAMPLE
} req_type;

req_type decode_req(uint8_t command[32]);

#endif
