#include "transaction.h"
/**
 * tx_out_create - creates an output transaction
 * Return: the trasaction output, or NULL if it fails.
 * @amount: the amount in the transaction.
 * @pub: the length of the public key.
*/
tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN])
{
tx_out_t *tx_out = malloc(sizeof(tx_out_t));
if (!pub || !tx_out)
{
free (tx_out);
return (NULL);
}
tx_out->amount = amount;
memcpy(&tx_out->pub, &pub, EC_PUB_LEN);
if (!sha256((const int8_t *)tx_out,
sizeof(tx_out->pub) + sizeof(tx_out->amount), tx_out->hash))
{
free (tx_out);
return (NULL);
}
return (tx_out);
}
