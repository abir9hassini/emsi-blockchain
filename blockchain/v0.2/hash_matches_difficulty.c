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


for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
if (!hash[i])
cpt += 8;
else
break;
for (bit = 1; bit < 8; bit++)
if (hash[i] >> bit == 0)
{
cpt += (8 - bit);
break;
}
if (cpt >= difficulty)
return (1);
return (0);
}
