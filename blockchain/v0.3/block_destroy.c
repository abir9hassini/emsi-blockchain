#include "blockchain.h"
/**
 * block_destroy - destroys a block.
 * @block: the block that is going to be destroyed.
 */
void block_destroy(block_t *block)
{
free(block);
}
