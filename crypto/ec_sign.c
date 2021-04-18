#include "hblk_crypto.h"

/**
 * ec_sign - Signs a given set of bytes, using a given EC_KEY private key
 * @key: EC key pair already generated
 * @msg: message to be signed
 * @msglen: length of that message
 * @sig: pointer to save the signature into
 *
 * Return: pointer to the signature on sucess, NULL on failure
 **/
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
sig_t *sig)
{
if (key == 0 || msg == 0 || sig == 0)
return (NULL);
if (ECDSA_sign(0, msg, msglen,
sig->sig, (void *)&(sig->len),
(void *)key) != 1)
return (0);
return (sig->sig);
}
