#ifndef PATCHER_H_
#define PATCHER_H_


#include "Dave.h"

uint8_t read_request(uint8_t command[], uint8_t is_secure_unlock, uint8_t is_secure_com);
uint8_t write_request(uint8_t msg[], uint8_t is_secure_com);


#endif
