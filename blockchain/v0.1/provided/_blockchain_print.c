#include <stdio.h>
#include <string.h>
#include "blockchain.h"

static int _block_print(block_t const *block, unsigned int index,
        char const *indent)
{
        if (!block)
        {
                printf("%snil\n", indent);
                return (0);
        }

        printf("%sBlock: {\n", indent);

        printf("%s\tinfo: {\n", indent);
        printf("%s\t\tindex: %u,\n", indent, block->info.index);
        printf("%s\t\tdifficulty: %u,\n", indent, block->info.difficulty);
        printf("%s\t\ttimestamp: %lu,\n", indent, block->info.timestamp);
        printf("%s\t\tnonce: %lu,\n", indent, block->info.nonce);
        printf("%s\t\tprev_hash: ", indent);
        _print_hex_buffer(block->info.prev_hash, SHA256_DIGEST_LENGTH);
        printf("\n%s\t},\n", indent);

        printf("%s\tdata: {\n", indent);
        printf("%s\t\tbuffer: \"%s\",\n", indent, block->data.buffer);
        printf("%s\t\tlen: %u\n", indent, block->data.len);
        printf("%s\t},\n", indent);

        printf("%s\thash: ", indent);
        _print_hex_buffer(block->hash, SHA256_DIGEST_LENGTH);

        printf("\n%s}\n", indent);

        (void)index;
        return (0);
}

