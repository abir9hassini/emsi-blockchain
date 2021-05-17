#include "blockchain.h"

/**
 * blockchain_difficulty - adjust difficulty for next block of blockchain
 * @blockchain: pointer to working blockchain
 * Return: adjusted difficulty
 */
uint32_t blockchain_difficulty(blockchain_t const *blockchain)
{
block_t *last_block, *adjusted_block;
uint64_t expectedElapsed_time, actualElapsed_time, half;

if (!blockchain)
return (0);
last_block = llist_get_tail(blockchain->chain);
if (!last_block)
return (0);
if (last_block->info.index == 0 ||
last_block->info.index % DIFFICULTY_ADJUSTMENT_INTERVAL)
return (last_block->info.difficulty);
adjusted_block = llist_get_node_at(blockchain->chain,
last_block->info.index + 1 - DIFFICULTY_ADJUSTMENT_INTERVAL);
expectedElapsed_time = DIFFICULTY_ADJUSTMENT_INTERVAL *
BLOCK_GENERATION_INTERVAL;
actualElapsed_time = last_block->info.timestamp -
adjusted_block->info.timestamp;
half = expectedElapsed_time / 2;
if (actualElapsed_time < half)
return (last_block->info.difficulty + 1);
else if (actualElapsed_time > 2 * expectedElapsed_time)
return (last_block->info.difficulty > 0 ?
last_block->info.difficulty - 1 : 0);
return (last_block->info.difficulty);
}
