#include "hblk_crypto.h"


/**
 * ec_verify - Verifies a given set of bytes, using a given EC_KEY private key
 * @key: EC key pair already generated
 * @msg: message to be signed
 * @msglen: length of that message
 * @sig: pointer to save the signature into
 *
 * Return: pointer to the signature on sucess, NULL on failure
 **/
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
sig_t const *sig)
{
if (key == 0 || msg == 0 || sig == 0 || sig->len == 0)
return (0);
if (ECDSA_verify(0, msg, msglen,
(void *)sig->sig, (int)(sig->len), (void *)key) != 1)
return (0);
return (1);
}
