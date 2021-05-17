#include "blockchain.h"
/**
 * block_hash - hashes info + data
 * @block: the block to be hashed.
 * @hash_buf: the digest.
 * Return: the digest, or NULL.
*/
uint8_t *block_hash(block_t const *block, uint8_t
hash_buf[SHA256_DIGEST_LENGTH])
{
if (!block)
return (NULL);
SHA256((unsigned char *)block, block->data.len + sizeof(block->info),
hash_buf);
return ((uint8_t *)(hash_buf));
}
