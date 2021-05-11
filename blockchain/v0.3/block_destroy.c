#include "blockchain.h"
/**
 * block_destroy - deletes the block
 * @block: block to be deleted
 */
void block_destroy(block_t *block)
{
free(block);
}
