#include "ssl.h"

static const uint32_t k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static const uint32_t st[8] = {
	0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

static void sha256_transform(struct sha256_ctx *ctx, uint32_t data[])
{
	uint32_t blocks[8] = {
		ctx->state[0], ctx->state[1], ctx->state[2], ctx->state[3],\
        ctx->state[4], ctx->state[5], ctx->state[6], ctx->state[7]
	};
    uint32_t i, j, tblocks[2], m[64];

	for (i = 0, j = 0; i < 16; ++i, j += 4)
		m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
	for (; i < 64; ++i)
		m[i] = sha_sig0(m[i - 2]) + m[i - 7] + sha_sig1(m[i - 15]) + m[i - 16];
	for (i = 0; i < 64; ++i)
    {
		tblocks[0] = sha_ep1(blocks[4]) + blocks[7] + sha_ch(blocks[4], blocks[5], blocks[6]) + k[i] + m[i];
		tblocks[1] = sha_ep0(blocks[0]) + sha_maj(blocks[0], blocks[1], blocks[2]);
		blocks[7] = blocks[6];
		blocks[6] = blocks[5];
		blocks[5] = blocks[4];
		blocks[4] = blocks[3] + tblocks[0];
		blocks[3] = blocks[2];
		blocks[2] = blocks[1];
		blocks[1] = blocks[0];
		blocks[0] = tblocks[0] + tblocks[1];
	}
    for (i = 0; i < 8; ++i)
        ctx->state[i] += blocks[i];
}

void sha256()
{
    uint32_t i, x;
    uint8_t digest[32];
    struct sha256_ctx ctx;

    ctx.datalen = 0;
	ctx.bitlen = 0;
	for (x = 0; x < 8; ++x)
		ctx.state[x] = st[x];
	for (x = 0; x < strlen((char*)context.data); ++x)
    {
		ctx.data[ctx.datalen] = context.data[x];
		ctx.datalen++;
		if (ctx.datalen == 64)
        {
			sha256_transform(&ctx, ctx.data);
			ctx.bitlen += 512;
			ctx.datalen = 0;
		}
	}
	i = ctx.datalen;
	if (ctx.datalen < 56)
    {
		ctx.data[i++] = 0x80;
		while (i < 56)
			ctx.data[i++] = 0x00;
	}
	else
    {
		ctx.data[i++] = 0x80;
		while (i < 64)
			ctx.data[i++] = 0x00;
		sha256_transform(&ctx, ctx.data);
		memset(ctx.data, 0, 56);
	}
	ctx.bitlen += ctx.datalen * 8;
    w32_to_4bytes(ctx.bitlen, &ctx.data[60]);
    w32_to_4bytes(ctx.bitlen >> 32, &ctx.data[56]);
	sha256_transform(&ctx, ctx.data);
	for (i = 0; i < 4; ++i)
    {
		digest[i] = (ctx.state[0] >> (24 - i * 8)) & 0x000000ff;
		digest[i + 4] = (ctx.state[1] >> (24 - i * 8)) & 0x000000ff;
		digest[i + 8] = (ctx.state[2] >> (24 - i * 8)) & 0x000000ff;
		digest[i + 12] = (ctx.state[3] >> (24 - i * 8)) & 0x000000ff;
		digest[i + 16] = (ctx.state[4] >> (24 - i * 8)) & 0x000000ff;
		digest[i + 20] = (ctx.state[5] >> (24 - i * 8)) & 0x000000ff;
		digest[i + 24] = (ctx.state[6] >> (24 - i * 8)) & 0x000000ff;
		digest[i + 28] = (ctx.state[7] >> (24 - i * 8)) & 0x000000ff;
	}
    for(x = 0; x < 32; ++x)
        printf("%02x", digest[x]);
    printf("\n");
}