#include "ssl.h"

void w32_to_byte(uint32_t val, uint8_t bytes[])
{
    bytes[0] = (uint8_t) val;
    bytes[1] = (uint8_t) (val >> 8);
    bytes[2] = (uint8_t) (val >> 16);
    bytes[3] = (uint8_t) (val >> 24);
}
 
void byte_to_w32(uint8_t val[], uint32_t bytes[])
{
    *bytes = (uint32_t)val[0] | ((uint32_t)val[1] << 8) | ((uint32_t)val[2] << 16) | ((uint32_t)val[3] << 24);
}

void w32_to_4bytes(uint32_t val, uint32_t bytes[])
{
    bytes[3] = val;
    bytes[2] = (val >> 8);
    bytes[1] = (val >> 16);
    bytes[0] = (val >> 24);
}

uint32_t sha_ep0(uint32_t x)
{
    return ((((x) >> (2)) | ((x) << (32-(2)))) ^ (((x) >> (13)) | ((x) << (32-(13)))) ^ (((x) >> (22)) | ((x) << (32-(22)))));
}

uint32_t sha_ep1(uint32_t x)
{
    return ((((x) >> (6)) | ((x) << (32-(6)))) ^ (((x) >> (11)) | ((x) << (32-(11)))) ^ (((x) >> (25)) | ((x) << (32-(25)))));
}

uint32_t sha_ch(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ (~(x) & (z)));
}

uint32_t sha_maj(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
}

uint32_t sha_sig1(uint32_t x)
{
	return (((x >> (7)) | (x << 25)) ^ ((x >> (18)) | (x << 14)) ^ (x >> 3));
}

uint32_t sha_sig0(uint32_t x)
{
	return (((x >> (17)) | (x << 15)) ^ ((x >> (19)) | (x << 13)) ^ (x >> 10));
}

uint32_t md5_lrot(uint32_t x, uint32_t y)
{
    return ((x << y) | (x >> (32 - y)));
}
