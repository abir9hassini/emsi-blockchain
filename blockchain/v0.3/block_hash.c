#include "blockchain.h"

/**
 * block_hash - get the hash of a block
 * @block: block to be hashed, only hash field will not be hashed
 * @hash_buf: buffer for digest
 * Return: hash digest or NULL if failed
 */
uint8_t *block_hash(block_t const *block,
		    uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
memset(hash_buf, 0, SHA256_DIGEST_LENGTH);
return (SHA256((const unsigned char *)block,
	       sizeof(block->info) + block->data.len, hash_buf));
}
