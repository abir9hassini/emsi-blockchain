#include <stdlib.h>
#include <stdio.h>

#include "blockchain.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
blockchain_t *blockchain;
block_t *first, *block;

blockchain = blockchain_create();
first = llist_get_head(blockchain->chain);

block = block_create(first, (int8_t *)"Holberton", 9);
block_hash(block, block->hash);
llist_add_node(blockchain->chain, block, ADD_NODE_REAR);

if (block_is_valid(first, NULL) != 0 ||
block_is_valid(block, first) != 0)
{
fprintf(stderr, "Block invalid\n");
return (EXIT_FAILURE);
}
printf("Block is valid\n");

blockchain_destroy(blockchain);

return (EXIT_SUCCESS);
}
