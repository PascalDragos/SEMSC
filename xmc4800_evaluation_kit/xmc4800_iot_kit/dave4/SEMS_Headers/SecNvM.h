#ifndef SECNVM_H_
#define SECNVM_H_


#include "Dave.h"

uint8_t write_sec_nvm(uint8_t block_id, uint8_t data_buffer[], uint32_t size);
uint8_t read_sec_nvm(uint8_t block_id, uint8_t data_buffer[], uint32_t size);

void write_sec_config(void);
void read_sec_config(void);

#endif
