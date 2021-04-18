#include <stdio.h>
#include <string.h>
#include <llist.h>

#include "blockchain.h"


void _blockchain_print(Blockchain const *blockchain);

int main(void)
{
    Blockchain *blockchain;
    Blockchain *blockchain2;

    blockchain = blockchain_create();

    _blockchain_print(blockchain);

    return (EXIT_SUCCESS);
}

