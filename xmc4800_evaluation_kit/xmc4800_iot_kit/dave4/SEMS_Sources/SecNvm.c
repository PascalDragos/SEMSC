#include <SEMS_Headers/SecNvM.h>
#include "../SEMS_Headers/Hash.h"
#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/Skey.h"
#include "../SEMS_Headers/Config.h"
#include "../SEMS_Headers/Random.h"

#include "../SEMS_Headers/Util.h"


// size <= 128
uint8_t write_sec_nvm(uint8_t block_id, uint8_t data_buffer[], uint32_t size)
{
	E_EEPROM_XMC4_STATUS_t flash_status;
	uint8_t data[128] = {0};
	uint8_t key[128];
	uint8_t digest[32];
	uint32_t start_addr;

	start_addr = block_id * 160u;

	memcpy(data, data_buffer, size);


	/* For testing */
//	key[0] = 0x01;
//	optiga_crypt_random_wrapper(key, sizeof(key));
//	optiga_util_write_shared_key(OPTIGA_NVMKEY_OID, key, sizeof(key));
//	key[0] = 127;

	optiga_util_read_shared_key(OPTIGA_NVMKEY_OID, key, sizeof(key));
	stream_enc(data, key, sizeof(key));

	optiga_crypt_hash_data_wrapper(data, sizeof(data), digest);

	// Fill the RAM buffer with the data elements
	E_EEPROM_XMC4_WriteArray(start_addr + 0U, data, size);
	E_EEPROM_XMC4_WriteArray(start_addr + 128U, digest, size);

	// Write the RAM buffer to flash
	flash_status = E_EEPROM_XMC4_UpdateFlashContents();

	return flash_status;
}

volatile uint8_t bb;
uint8_t read_sec_nvm(uint8_t block_id, uint8_t data_buffer[], uint32_t size)
{
	volatile uint8_t success;
	uint8_t block_buffer[160] = {0};
	uint8_t digest_calc[32] = {0};
	uint8_t key[128] = {0};

	E_EEPROM_XMC4_ReadArray(0, block_buffer, sizeof(block_buffer));

	optiga_crypt_hash_data_wrapper(block_buffer, sizeof(key), digest_calc);

	if(0 == memcmp(digest_calc, block_buffer + 128, sizeof(digest_calc)))
	{
		success = true;

		optiga_util_read_shared_key(OPTIGA_NVMKEY_OID, key, sizeof(key));
		stream_enc(block_buffer, key, sizeof(key));

	}
	else
	{
		success = false;
	}

	bb = block_buffer[4];

	return success;
}


void write_sec_config(void)
{

	volatile E_EEPROM_XMC4_STATUS_t flash_status;

	uint8_t data_config[128];

	uint16_t i;
	for(i = 0; i < sizeof(data_config); ++i)
	{
		data_config[i] = i;
	}

	flash_status = write_sec_nvm(0, data_config, sizeof(data_config));
	flash_status = flash_status;
}


void read_sec_config(void)
{
	volatile E_EEPROM_XMC4_STATUS_t flash_status;
	uint8_t data_buffer[128];

	flash_status = read_sec_nvm(0, data_buffer, sizeof(data_buffer));
	flash_status = flash_status;

}

