#include <DAVE.h>
#include "optiga/optiga_crypt.h"
#include "optiga/optiga_util.h"
#include "optiga/common/optiga_lib_logger.h"
#include "optiga/pal/pal_os_event.h"
#include "optiga/pal/pal.h"
#include "optiga/pal/pal_os_timer.h"
#include "optiga_example.h"
#include "optiga/pal/pal_logger.h"

#include "optiga_example.h"
#include "optiga/optiga_util.h"

#include "../SEMS_Headers/Nonce.h"
#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/RSA.h"
#include "../SEMS_Headers/Timer.h"
#include "../SEMS_Headers/Random.h"
#include "../SEMS_Headers/SymEncrypt.h"
#include "../SEMS_Headers/Unlock.h"
#include "../SEMS_Headers/Com.h"
#include "../SEMS_Headers/Hash.h"
#include "../SEMS_Headers/Patcher.h"
#include "../SEMS_Headers/Config.h"
#include "../SEMS_Headers/Init.h"
#include "../SEMS_Headers/Test.h"
#include "../SEMS_Headers/Skey.h"
#include "../SEMS_Headers/Util.h"
#include "../SEMS_Headers/SecNvM.h"


#if LIFECYCLE==TESTING
uint8_t test_write_read(void)
{
	uint8_t passed = true;
	uint8_t key_written[32] = {0};
	uint8_t key_read[32] = {0};
	uint16_t i = 0;

	for(i = 0u; i < sizeof(key_written); i++)
	{
		key_written[i] = i;
	}

	// Write key
	optiga_util_write_shared_key(OPTIGA_SESKEY_OID, key_written, sizeof(key_written));
	// Read key
	optiga_util_read_shared_key(OPTIGA_SESKEY_OID, key_read, sizeof(key_read));

	for(i = 0; i < sizeof(key_written); i++)
	{
		if(key_written[i] != key_read[i])
		{
			passed = false;
			break;
		}
	}
	optiga_lib_print_bytes(&passed, 1);

	return passed;
}

void testing0(void)
{
	uint16_t i = 0;
	uint8_t data_to_hash[32] = {0};
	uint8_t digest[32] = {0};
	uint8_t res;
	for(i = 0; i < sizeof(data_to_hash); ++i)
	{
		data_to_hash[i] = i;
	}
	optiga_crypt_hash_data_wrapper(data_to_hash, sizeof(data_to_hash), digest);
	res = digest[1];
	digest[1] = res;
}

volatile uint32_t one_time = 0; // volatile to avoid optimization
volatile uint32_t n_times = 0; // volatile to avoid optimization
uint8_t test_time_write_read(uint16_t n)
{
	uint8_t passed = true;
	uint8_t key_written[32] = {0};
	uint8_t key_read[32] = {0};
	uint16_t i = 0;
	uint32_t time_taken; // will be optimized

	for(i = 0u; i < sizeof(key_written); i++)
	{
		key_written[i] = i;
	}

	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Write key
		optiga_util_write_shared_key(OPTIGA_SESKEY_OID, key_written, sizeof(key_written));
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);


	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Read key
		optiga_util_read_shared_key(OPTIGA_SESKEY_OID, key_read, sizeof(key_read));
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);
	one_time = time_taken;
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);


	for(i = 0; i < sizeof(key_written); i++)
	{
		if(key_written[i] != key_read[i])
		{
			passed = false;
			break;
		}
	}

	return passed;
}


uint32_t test_time_read_session_key(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler
	uint8_t key_read[32] = {0};

	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	optiga_util_read_shared_key(OPTIGA_SESKEY_OID, key_read, sizeof(key_read));
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		optiga_util_read_shared_key(OPTIGA_SESKEY_OID, key_read, sizeof(key_read));
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}

uint32_t test_time_write_session_key(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler
	uint8_t key_written[32] = {0};

	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	optiga_util_write_shared_key(OPTIGA_SESKEY_OID, key_written, sizeof(key_written));
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		optiga_util_write_shared_key(OPTIGA_SESKEY_OID, key_written, sizeof(key_written));
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}



uint32_t test_time_random_generate(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler
	uint8_t buffer[32] = {0};

	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	optiga_crypt_random_wrapper(buffer, sizeof(buffer));
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		optiga_crypt_random_wrapper(buffer, sizeof(buffer));
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}



uint32_t test_time_hash(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler
	uint8_t buffer[32] = {0};
	uint8_t digest[32] = {0};

	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	optiga_crypt_hash_data_wrapper(buffer, sizeof(buffer), digest);
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		optiga_crypt_hash_data_wrapper(buffer, sizeof(buffer), digest);
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}


uint32_t test_time_stream_encrypt(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler
	uint8_t buffer1[32] = {0};
	uint8_t buffer2[32] = {0};

	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	stream_enc(buffer1, buffer2, sizeof(buffer1));
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		stream_enc(buffer1, buffer2, sizeof(buffer1));
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}



uint32_t test_time_rsa_verify(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler
	uint8_t buffer1[100] = {0};
	uint8_t buffer2[128] = {0};

	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	optiga_crypt_rsa_verify_wrapper(buffer1, (uint8_t)sizeof(buffer1), buffer2, (uint16_t)sizeof(buffer2));
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		optiga_crypt_rsa_verify_wrapper(buffer1, (uint8_t)sizeof(buffer1), buffer2, (uint16_t)sizeof(buffer2));
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}

uint32_t test_time_rsa_encrypt(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler
	uint8_t buffer1[32] = {0};
	uint8_t buffer2[128] = {0};
	uint16_t len = 128;

	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	optiga_crypt_rsa_encrypt_message_wrapper(buffer1, sizeof(buffer1), buffer2, &len);
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		optiga_crypt_rsa_encrypt_message_wrapper(buffer1, sizeof(buffer1), buffer2, &len);
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}


uint32_t test_time_read_nonce(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler
	uint8_t buffer1[4] = {0};


	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	optiga_util_read_nonce(OPTIGA_NONCE_OID, buffer1, sizeof(buffer1));
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		optiga_util_read_nonce(OPTIGA_NONCE_OID, buffer1, sizeof(buffer1));
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}


uint32_t test_time_update_nonce(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler


	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	optiga_util_update_count_wrapper(OPTIGA_NONCE_OID, 1);
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		optiga_util_update_count_wrapper(OPTIGA_NONCE_OID, 1);
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}


uint32_t test_time_init(uint16_t n)
{
	uint16_t i = 0;
	uint32_t time_taken;  // will be optimized out by compiler


	/* One call test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	example_optiga_init_true();
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	one_time = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	/* n calls test */
	START_PERFORMANCE_MEASUREMENT(time_taken);
	for(i = 0u; i < n; ++i)
	{
		// Optiga operation here
		example_optiga_init_true();
	}
	READ_PERFORMANCE_MEASUREMENT(time_taken);

	n_times = time_taken;  // to watch in debugger
	optiga_lib_print_bytes((uint8_t *)&time_taken, 4);

	return time_taken;
}

volatile E_EEPROM_XMC4_STATUS_t flash_status;
uint8_t data_buffer[32];
void test_nvm(void)
{
	flash_status = read_nvm(data_buffer, sizeof(data_buffer));
	flash_status = flash_status;
}

void test_time(void)
{
//	test_time_write_read(1000);
//	test_time_write_session_key(1000);
//	test_time_random_generate(1000);
	test_time_hash(10000);
//	test_time_stream_encrypt(2000);
//	test_time_rsa_verify(1000);
//	test_time_rsa_encrypt(1000);
//	test_time_read_nonce(1000);
//	test_time_update_nonce(1000);
//	test_time_init(1000);
	n_times = 0;
}


void test(void)
{
	test_nvm();
}
#endif
