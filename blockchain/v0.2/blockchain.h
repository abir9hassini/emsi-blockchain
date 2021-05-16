#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <llist.h>
#include <openssl/sha.h>
#include "../../crypto/hblk_crypto.h"

#define BLOCKCHAIN_DATA_MAX 1024
#define UNUSED(x) (void)(x)


#define GENESIS_BLOCK { \
{ /* info */ \
0 /* index */, \
0, /* difficulty */ \
1537578000, /* timestamp */ \
0, /* nonce */ \
{0} /* prev_hash */ \
}, \
{ /* data */ \
"Holberton School", /* buffer */ \
16 /* len */ \
}, \
"\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d" \
"\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03" \
}

typedef struct blockchain_s
{
llist_t     *chain;
} blockchain_t;

typedef struct block_info_s
{
uint32_t    index;
uint32_t    difficulty;
uint64_t    timestamp;
uint64_t    nonce;
uint8_t     prev_hash[SHA256_DIGEST_LENGTH];

} block_info_t;

typedef struct block_data_s
{
int8_t      buffer[BLOCKCHAIN_DATA_MAX];
uint32_t    len;

} block_data_t;

typedef struct block_s
{
block_info_t    info;
block_data_t    data;
uint8_t     hash[SHA256_DIGEST_LENGTH];

} block_t;

extern block_t const _genesis;

blockchain_t *blockchain_create(void);

void _blockchain_print(blockchain_t const *blockchain);

void _blockchain_destroy(blockchain_t *blockchain);

block_t *block_create(block_t const *prev, int8_t const *data,
uint32_t data_len);

void block_destroy(block_t *block);

void blockchain_destroy(blockchain_t *blockchain);

uint8_t *block_hash(block_t const *block,
uint8_t hash_buf[SHA256_DIGEST_LENGTH]);

int blockchain_serialize(blockchain_t const *blockchain, char const *path);

uint8_t _get_endianness(void);

void _swap_endian(void *p, size_t size);

blockchain_t *blockchain_deserialize(char const *path);

int block_is_valid(block_t const *block, block_t const *prev_block);
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
uint32_t difficulty);
void block_mine(block_t *block);
#endif

