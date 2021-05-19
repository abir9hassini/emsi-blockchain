#include "blockchain.h"
#include <time.h>
/**
 * block_create - creates a new block
 * @prev: previous block
 * @data: data for a new block
 * @data_len: length of @data
 * Return: a block or NULL if failed
 */
block_t *block_create(block_t const *prev,
		      int8_t const *data, uint32_t data_len)
{
block_t *block;
int i;
uint32_t max_len = data_len > BLOCKCHAIN_DATA_MAX ?
BLOCKCHAIN_DATA_MAX : data_len;
	
if (prev == NULL || data == NULL)
return (NULL);

block = (block_t *)malloc(sizeof(block_t));
block->info.index = prev->info.index+ 1;
block->info.difficulty = 0;
block->info.timestamp = time(0);
block->info.nonce = 0;
	
for (i = 0; i < BLOCKCHAIN_DATA_MAX; i++)
{
block->data.buffer[i] = 0;
}
for (i = 0; i < (int)max_len; i++)
{
block->data.buffer[i] = data[i];
}
block->data.len = max_len;
for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
{
block->hash[i] = 0;
block->info.prev_hash[i] = prev->hash[i];
}
return (block);
}
