#include "../SEMS_Headers/SymEncrypt.h"

#include "../SEMS_Headers/Util.h"


void stream_enc(uint8_t r1[], const uint8_t r2[], uint8_t len)
{
    unsigned int i;
    for (i = 0; i < len; ++i)
    {
        r1[i] = r1[i] ^ r2[i];
    }
}





