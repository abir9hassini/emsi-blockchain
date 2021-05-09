#include<stdio.h>
#include "blockchain.h"



int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
uint32_t difficulty)
{
int cpt = 0;
for (int i = 0; i < hash.length; i++)
{
for(int bit=7;bit>=0;bit--){
if(hash[i] & 0 >> bit){
cpt++;
}
else{ break;}
}
}
if(cpt == difficulty) return (1);
return (0);
}


