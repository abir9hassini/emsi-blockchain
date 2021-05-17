#include "blockchain.h"
/**
 * is_genesis - returns 0 if the block is genesis.
 * @block: the block to be verified.
 * Return: 0 if matching, 1 else.
*/
int is_genesis(block_t const *block)
{
blockchain_t *blockchain = blockchain_create();
if (!blockchain)
return (-1);
if (memcmp(block, llist_get_head(blockchain->chain), sizeof(*block)) != 0)
{
blockchain_destroy(blockchain);
return (-1);
}
blockchain_destroy(blockchain);
return (0);
}
/**
* block_is_valid - checks if a given block is valid.
* @block: the block to be checked.
* @prev_block: its previous block.
* Return: 0 if valid, else 50.
*/
int block_is_valid(block_t const *block, block_t const *prev_block)
{
uint8_t hash_buf[SHA256_DIGEST_LENGTH];
if (!block || ((block->info.index == 0) && prev_block != NULL))
return (-1);
if (block->info.index == 0)
return (is_genesis(block));
if (block->info.index != prev_block->info.index + 1)
return (-1);
if (!block_hash(prev_block, hash_buf) || memcmp(hash_buf,
prev_block->hash, SHA256_DIGEST_LENGTH))
return (-1);
if (memcmp(prev_block->hash, block->info.prev_hash, SHA256_DIGEST_LENGTH))
return (-1);
if (!block_hash(block, hash_buf) || memcmp(hash_buf,
block->hash, SHA256_DIGEST_LENGTH))
return (-1);
if (memcmp(block->info.prev_hash, prev_block->hash, SHA256_DIGEST_LENGTH))
return (-1);
if (block->data.len <= BLOCKCHAIN_DATA_MAX)
return (0);
return (-1);
}
