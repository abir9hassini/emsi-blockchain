#include "blockchain.h"
/**
 * blockchain_serialize - serializes a block into a file.
 * @path: the path where to create/override the file.
 * @blockchain: the block to serialize
 * Return: 0 upon succes, -1 else.
 */
int blockchain_serialize(blockchain_t const *blockchain, char const *path)
{
uint8_t end = _get_endianness();
int f, i;
block_t *myblock;
int32_t list_size = llist_size(blockchain->chain);
f = open(path, O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR);
if (!blockchain || !path || !f)
return (-1);
write(f, HBLK_MAGIC, 4);
write(f, HBLK_VERSION, 3);
write(f, &end, 1);
write(f, &list_size, 4);
for (i = 0 ; i < list_size ; i++)
{
myblock = llist_get_node_at(blockchain->chain, i++);
if (write(f, &(myblock->info), sizeof(myblock->info))
!= sizeof(myblock->info) ||
write(f, &(myblock->data.len), sizeof(myblock->data.len))
!= myblock->data.len ||
write(f, &(myblock->hash), SHA256_DIGEST_LENGTH) != SHA256_DIGEST_LENGTH ||
write(f, myblock->data.buffer, myblock->data.len) != myblock->data.len)
return (-1);
}
close(f);
return (0);
}
