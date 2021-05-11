#include "transaction.h"

/**
 * tx_out_create - creates a new transaction output structure
 * @amount: the transaction amount
 * @pub: public key of receiver
 * Return: pointer to new structure or NULL
 */
tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN])
{
tx_out_t *new_tx_output = NULL;

new_tx_output = calloc(1, sizeof(tx_out_t));

if (new_tx_output == NULL)
{
return (NULL);
}
new_tx_output->amount = amount;
memcpy(new_tx_output->pub, pub, sizeof(new_tx_output->pub));
if (!sha256((int8_t const *)new_tx_output,
sizeof(new_tx_output->amount) + sizeof(new_tx_output->pub),
new_tx_output->hash))
{
free(new_tx_output);
return (NULL);
}
return (new_tx_output);

