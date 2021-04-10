#include<llist.h>
#include<stdint.h>
#include<stdio.h>

blockchain_t *blockchain_create(void){

typedef struct Blockchain
{
    llist_t     *chain;
};

typedef struct block_info_s
{
    uint32_t    index=0;
    uint32_t    difficulty=0;
    uint64_t    timestamp=1537578000;
    uint64_t    nonce=0;
    uint8_t     prev_hash=0;
} block_info_t;

typedef struct block_data_s
{
    int8_t      data="Holberton School";
    uint32_t    len=16;
} block_data_t;

typedef struct block_s
{
    block_info_t    info;
    block_data_t    data;
    uint8_t     hash="\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03";
} Genesis;


return Blockchain;


}

