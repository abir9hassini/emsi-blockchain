#include<stdio.h>
#include "blockchain.h"



int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
uint32_t difficulty)
{
uint32_t i,cpt = 0;
uint32_t bit = 7;

for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
{
if(!hash[i])
cpt += 8;
else
break;
for (bit = 1; bit <= 8; bit++)
{
if (hash[i] << bit == 0)
{
cpt += bit;
break;
}
}
}
if (cpt >= difficulty)
return (1);
return (0);
}
