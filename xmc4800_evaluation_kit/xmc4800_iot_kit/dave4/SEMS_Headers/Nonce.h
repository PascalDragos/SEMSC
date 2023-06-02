#ifndef NONCE_H_
#define NONCE_H_


#include "Dave.h"

void optiga_util_read_nonce(uint16_t optiga_oid, uint8_t read_data_buffer[], uint16_t bytes_to_read);
void optiga_util_update_count_wrapper(uint16_t optiga_counter_oid, uint8_t ticks);
void optiga_util_reset_count(uint16_t optiga_counter_oid);


#endif
