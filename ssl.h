#ifndef _SSL_H
# define _SSL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

struct sha256_ctx {
	uint32_t data[64];
	uint32_t datalen;
	uint64_t bitlen;
	uint32_t state[8];
};

struct ssl_ctx {
	uint8_t hfun;
	uint8_t flags;
	int8_t	fd;
	uint8_t	*data;
};

extern struct ssl_ctx context;

void md5();

void sha256();

uint8_t *readfile(void);

void byte_to_w32(uint8_t val[], uint32_t *bytes);
void w32_to_byte(uint32_t val, uint8_t bytes[]);
void w32_to_4bytes(uint32_t val, uint32_t bytes[]);

uint32_t sha_ep0(uint32_t x);
uint32_t sha_ep1(uint32_t x);
uint32_t sha_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t sha_maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t sha_sig0(uint32_t x);
uint32_t sha_sig1(uint32_t x);
uint32_t md5_lrot(uint32_t x, uint32_t y);

uint8_t ssl_getopt(uint32_t nargs, char* args[], uint32_t *optind);

#endif
