nclude <stdio.h>
#include <string.h>
#include <llist.h>

#include "blockchain.h"


void _blockchain_print(blockchain_t const *blockchain);

int main(void)
{
    blockchain_t *blockchain;
    blockchain_t *blockchain2;

    blockchain = blockchain_create();

    _blockchain_print(blockchain);

    return (EXIT_SUCCESS);
}
