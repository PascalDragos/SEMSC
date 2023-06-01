#include "../SEMS_Headers/SymEncrypt.h"

#include "../SEMS_Headers/Util.h"


void stream_enc(uint8_t r1[], uint8_t r2[], uint8_t len)
{
    unsigned int i;
    for (i = 0; i < len; ++i)
    {
        r1[i] = r1[i] ^ r2[i];

    }
}


uint8_t compare_bytes(uint8_t a[], uint8_t b[], uint8_t len)
{
	uint8_t is_equal = true;
	uint8_t i;
	for (i = 0; i < len; ++i)
	{
		if(a[i] != b[i])
		{
			is_equal = false; // MISRA single exit
			break;
		}
	}
	return is_equal;
}



