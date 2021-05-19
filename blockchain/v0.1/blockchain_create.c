#include "blockchain.h"

/**
 * blockchain_create - create a block chain structure
 * Return: a new blockchain structure
 */
blockchain_t *blockchain_create(void)
{
block_t const Genesis = GENESIS_BLOCK_CONTENT;

blockchain_t *blockchain = (blockchain_t *) malloc(sizeof(blockchain_t));
block_t *ptr = (block_t *) malloc(sizeof(block_t));
memcpy(ptr, (block_t *) &Genesis, sizeof(block_t));
blockchain->chain = llist_create(MT_SUPPORT_TRUE);
if (llist_add_node(blockchain->chain, ptr, ADD_NODE_FRONT) != 0)
return (NULL);
return (blockchain);
}
