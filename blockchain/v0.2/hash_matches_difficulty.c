#include<stdio.h>
#include "blockchain.h"



int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
uint32_t difficulty)
{
uint32_t cpt = 0;
int i = 0;
int bit = 7;
{
for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
for (bit = 7; bit >= 0; bit--)
{
if (hash[i] & (1 << bit))
break;
else
cpt++;
}
}
if (cpt >= difficulty)
return (1);
else
return (0);
}





