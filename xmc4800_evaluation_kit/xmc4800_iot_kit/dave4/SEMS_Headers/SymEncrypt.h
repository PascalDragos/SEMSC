#ifndef SYMENC_H_
#define SYMENC_H_

void stream_enc(uint8_t r1[], uint8_t r2[], uint8_t len);

void optiga_util_write_shared_key(uint16_t optiga_oid, const uint8_t key[], uint16_t bytes_to_write);
void optiga_util_read_shared_key(uint16_t optiga_oid, uint8_t read_data_buffer[], uint16_t bytes_to_read);

#endif
