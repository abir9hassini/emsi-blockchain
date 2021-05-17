#include "blockchain.h"
/**
 * blockchain_create - creates a blockchain initialized with genesis
 * Return: a new blockchain, NULL on failure.
 */
blockchain_t *blockchain_create(void)
{
block_t *genesisBlock = (block_t *)malloc(sizeof(block_t)),
gen = GENESIS_BLOCK;
blockchain_t *new_blockchain = malloc(sizeof(blockchain_t));
new_blockchain->chain = llist_create(MT_SUPPORT_TRUE);
memcpy(genesisBlock, (block_t *) &gen, sizeof(block_t));
if (!llist_add_node(new_blockchain->chain, genesisBlock, ADD_NODE_FRONT))
return (new_blockchain);
return (NULL);
}
