#include "blockchain.h"
/**
* hash_matches_difficulty - checks if hash matches difficulty
* @hash: hash to check
* @difficulty: difficulty of a block
* Return: 1 if hash matches difficulty, otherwise 0
*/
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
uint32_t difficulty)
{
uint8_t i, bit, cpt = 0;

/**
* Iterate the hash table byte by byte
*/
for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
/**
* if a byte ==0 we increment directly the cpt
*/
if (!hash[i])
cpt += 8;
else
/**
* else , we check bit by bit if hash[i] >> bit is equal to 00000000
*/
break;
for (bit = 1; bit < 8; bit++)
if (hash[i] >> bit == 0)
{
/**
* in this case we increment cpt by 8 - bit
*/
cpt += (8 - bit);
break;
}
/**
* after checking all the bytes , if we found cpt >= difficulty
* we can say that the hash match difficulty , if not , the hash doesn't
* match the difficulty
*/
if (cpt >= difficulty)
return (1);
return (0);
}
