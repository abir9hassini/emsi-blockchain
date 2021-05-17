#include "blockchain.h"
block_t *block_create(block_t const *prev, int8_t const
*data, uint32_t data_len)
{
block_t *block = NULL;
if (!prev || !data)
return (NULL);
block = (block_t *) malloc(sizeof(block_t));
block->info.index = prev->info.index + 1;
block->info.difficulty = 0;
block->info.nonce = 0;
block->info.timestamp = time(0);
block->data.len = (((BLOCKCHAIN_DATA_MAX) < (data_len)) ?
(BLOCKCHAIN_DATA_MAX) : (data_len));
memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
memcpy(block->data.buffer, data, BLOCKCHAIN_DATA_MAX);
memset(block->hash, 0, SHA256_DIGEST_LENGTH);
return (block);
}
