#ifndef HBLK_CRYPTO_H
#define HBLK_CRYPTO_H
#define EC_CURVE      NID_secp256k1
#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/sha.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>

uint8_t *sha256(int8_t const *s, size_t len,
uint8_t digest[SHA256_DIGEST_LENGTH]);
EC_KEY *ec_create(void);
#endif

