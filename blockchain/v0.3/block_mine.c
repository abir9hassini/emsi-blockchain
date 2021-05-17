#include "blockchain.h"
/**
 * block_mine - finds a hash that respects difficulty and mines the block.
 * @block: the block to mine.
*/
void block_mine(block_t *block)
{
uint8_t hash_buff[SHA256_DIGEST_LENGTH];
block_hash(block, hash_buff);
while (!hash_matches_difficulty(hash_buff, block->info.difficulty))
{
block->info.nonce++;
block_hash(block, hash_buff);
}
memcpy(block->hash, hash_buff, SHA256_DIGEST_LENGTH);
}
