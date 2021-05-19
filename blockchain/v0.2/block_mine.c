#include "blockchain.h"

/**
* block_mine - mines a Block in order to insert it in the Blockchain
* @block: points to the Block to be mined
* Return: nothing
*/
void block_mine(block_t *block)
{

block->info.nonce = 0;
do {
/*Create a hash for the block*/
block_hash(block, block->hash);
/*Check if the created hash fulfill the difficulty*/
if (hash_matches_difficulty(block->hash, block->info.difficulty))
{
break;
}
block->info.nonce++;
} while (block->info.nonce != 0);
}
