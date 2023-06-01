#ifndef SKEY_H
#define SKEY_H


#include "Dave.h"

void optiga_util_write_shared_key(uint16_t optiga_oid, const uint8_t key[], uint16_t bytes_to_write);
void optiga_util_read_shared_key(uint16_t optiga_oid, uint8_t read_data_buffer[], uint16_t bytes_to_read);


#endif
