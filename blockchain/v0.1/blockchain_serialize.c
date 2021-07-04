#include "blockchain.h"

/**
 * write_block - a function that serializes a Blockchain into a file
 * @ptr: pointer to the block to be serialized
 * @idx: index of the parameter
 * @arg: The file in which the data will be written
 * Return: 0 upon success, or -1 upon failure
 */
int block_to_file(llist_node_t ptr, unsigned int no, void *file)
{
block_t *block = ptr;
FILE *fptr;
no = -1;
if (file) 
{
fptr=(FILE*)file;
fwrite((void *)&block->info, sizeof(block->info), 1, fptr);
fwrite((void *)&block->data.len, sizeof(block->data.len), 1, fptr);
fwrite(block->data.buffer, block->data.len, 1, fptr);
fwrite(block->hash, sizeof(block->hash), 1, fptr);
return no;
}
return 0;
}
/**
 * blockchain_serialize - a function that serializes a Blockchain into a file
 * @blockchain: pointer to blockchain to be serialized
 * @path: the path to a file to serialize the Blockchain into
 *
 * Return: 0 upon success, or -1 upon failure
 */

int blockchain_serialize(blockchain_t const *blockchain, char const *path) 
{
uint8_t hblk_magic[4];
uint8_t hblk_version[3];
uint8_t hblk_endian;
int32_t hblk_blocks;
FILE *fptr = fopen(path, "w");
if (!fptr)
return (-1);
if (blockchain && path)
{
hblk_blocks = llist_size(blockchain->chain);
if (hblk_blocks == -1) 
return (-1);
memcpy(hblk_magic, "HBLK", 4);
memcpy(hblk_version, "0.1", 3);
hblk_endian = _get_endianness();
fwrite(&hblk_magic, sizeof(hblk_magic), 1, fptr);
fwrite(&hblk_version, sizeof(hblk_version), 1, fptr);
fwrite(&hblk_endian, sizeof(hblk_endian), 1, fptr);
fwrite(&hblk_blocks, sizeof(hblk_blocks), 1, fptr);
if (llist_for_each(blockchain->chain, block_to_file, fptr))
{
fclose(fptr);
return 0;
}
}
fclose(fptr);
return -1;
