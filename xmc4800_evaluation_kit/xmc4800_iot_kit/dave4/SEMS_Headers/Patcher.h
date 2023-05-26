#ifndef PATCHER_H_
#define PATCHER_H_

uint8_t read_request(uint8_t command[], uint8_t is_secure_com);
uint8_t write_request(uint8_t msg[], uint8_t is_secure_com);
void optiga_util_read_nonce(uint16_t optiga_oid, uint8_t read_data_buffer[], uint16_t bytes_to_read);
void optiga_util_update_count_wrapper(uint16_t optiga_counter_oid, uint8_t ticks);
void optiga_util_reset_count(uint16_t optiga_counter_oid);


#endif
