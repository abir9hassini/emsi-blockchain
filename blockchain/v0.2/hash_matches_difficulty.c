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

/*Iterate every byte*/
for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
/*check if every byte == "00" */
if (!hash[i])
cpt += 8;
else
break;
/*Check every bit from left to right*/
for (bit = 1; bit < 8; bit++)
/**
* If we found something equals to zero we increment
* the cpt variable by 8- bit
*/
if (hash[i] >> bit == 0)
{
cpt += (8 - bit);
break;
}
/**
* at the end , if we found that cpt < difficulty that
* mean that the hash doesn't match the difficulty
* or if cpt >= difficulty so that what we want and
* we can say that the hash match the difficulty
*/
if (cpt < difficulty)
return (0);
return (1);
}
