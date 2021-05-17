#include "blockchain.h"
/**
 * blockchain_destroy - destroys a blockchain if
 * it isn't already pointing on NULL.
 * @blockchain: the blockchain to be freed.
 */
void blockchain_destroy(blockchain_t *blockchain)
{
if (!blockchain)
return;
llist_destroy(blockchain->chain, 1, (node_dtor_t)free);
free(blockchain);
}
