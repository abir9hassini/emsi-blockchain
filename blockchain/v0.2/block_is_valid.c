#include "blockchain.h"

/**
 * block_is_valid - verifies that a Block is valid
 * @block: points to the Block to check
 * @prev_block: points to the previous Block in the Blockchain
 * Return: 0 on sucess, 1 otherwise
 */
int block_is_valid(block_t const *block, block_t const *prev_block)
{
uint8_t hash_buffer[SHA256_DIGEST_LENGTH] = {0};
block_t GENESIS = GENESIS_BLOCK;

/*
*block should not be NULL and prev_block should be
*NULL ONLY if blocks index is 0
*/
if (!block || (!prev_block && block->info.index != 0))
return (1);
/*
*If the Block index is 0, the Block should
*match the Genesis Block described in the first task
*/
if (block->info.index == 0)
return (memcmp(block, &GENESIS, sizeof(GENESIS)));
/*The Blocks index must be the previous Blocks index, plus 1*/
if (block->info.index != prev_block->info.index + 1)
return (1);
/*The computed hash of the previous block must match the one it stores*/
if (!block_hash(prev_block, hash_buffer) ||
memcmp(hash_buffer, prev_block->hash, SHA256_DIGEST_LENGTH))
return (1);
/*
	 *The computed hash of the previous block must match the reference one
	 *stored in block
*/
if (memcmp(prev_block->hash, block->info.prev_hash, SHA256_DIGEST_LENGTH))
return (1);
/*The computed hash of the Block must match the one it stores*/
if (!block_hash(block, hash_buffer) ||
memcmp(hash_buffer, block->hash, SHA256_DIGEST_LENGTH))
return (1);
/*The Block data length must not exceed BLOCKCHAIN_DATA_MAX*/
if (block->data.len > BLOCKCHAIN_DATA_MAX)
return (1);
/*The hash matches a given difficulty*/
if (!hash_matches_difficulty(block->hash, block->info.difficulty))
return (1);
return (0);
}
