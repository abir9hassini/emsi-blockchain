#ifndef HBLK_CRYPTO_H
#define HBLK_CRYPTO_H
#define EC_CURVE      NID_secp256k1

/* EC_KEY public key octet string length (using 256-bit curve) */
#define EC_PUB_LEN	65

#define PUB_FILENAME	"key_pub.pem"
#define PRI_FILENAME	"key.pem"

/* Maximum signature octet string length (using 256-bit curve) */
#define SIG_MAX_LEN	72


#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/sha.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>

/**
 * struct sig_s - EC Signature structure
 *
 * @sig: Signature buffer. The whole space may not be used
 * @len: Signature size. Can't exceed SIG_MAX_LEN, therefore stored on a byte
 */
typedef struct sig_s
{
	/*
	 * @sig must stay first, so we can directly use the structure as
	 * an array of char
	 */
uint8_t	sig[SIG_MAX_LEN];
uint8_t	len;
} sig_t;

uint8_t *sha256(int8_t const *s, size_t len,
uint8_t digest[SHA256_DIGEST_LENGTH]);
EC_KEY *ec_create(void);
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN]);
int ec_save(EC_KEY *key, char const *folder);
EC_KEY *ec_load(char const *folder);
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
size_t msglen, sig_t *sig);
#endif

