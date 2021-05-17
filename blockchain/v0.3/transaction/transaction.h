#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <llist.h>

#include "../../../crypto/hblk_crypto.h"

#define COINBASE_AMOUNT								\
	50

/**
 * struct transaction_s - transaction structure
 *
 * @id: transaction ID (a hash of all the inputs and outputs)
 * @inputs: list of `tx_in_t *` transaction inputs
 * @outputs: list of `tx_out_t *` transaction outputs
 */
typedef struct transaction_s
{
	uint8_t	id[SHA256_DIGEST_LENGTH];
	llist_t	*inputs;
	llist_t	*outputs;
} transaction_t;

/**
 * struct tx_out_s - transaction output
 *
 * @amount: amount received
 * @pub: receiver's public address
 * @hash: hash of @amount and @pub (serves as output ID)
 */
typedef struct tx_out_s
{
	uint32_t	amount;
	uint8_t	pub[EC_PUB_LEN];
	uint8_t	hash[SHA256_DIGEST_LENGTH];
} tx_out_t;

/**
 * struct tx_in_s - transaction input
 *
 * Description: A transaction input always refers to a previous transaction
 * output. The only exception is for a coinbase transaction, which adds new
 * coins to ciruclation.
 *
 * @block_hash: hash of the Block containing the transaction @tx_id
 * @tx_id: ID of the transaction containing @tx_out_hash
 * @tx_out_hash: hash of the referenced transaction output
 * @sig: signature by the receiver of the referenced transaction output
 */
typedef struct tx_in_s
{
	uint8_t	block_hash[SHA256_DIGEST_LENGTH];
	uint8_t	tx_id[SHA256_DIGEST_LENGTH];
	uint8_t	tx_out_hash[SHA256_DIGEST_LENGTH];
	sig_t	sig;
} tx_in_t;

/**
 * struct unspent_tx_out_s - unspent transaction output
 *
 * Description: This structure helps identify transaction outputs that were not
 * used in any transaction input yet, making them "available".
 *
 * @block_hash: hash of the Block containing the transaction @tx_id
 * @tx_id: ID of the transaction containing @out
 * @out: copy of the referenced transaction output
 */
typedef struct unspent_tx_out_s
{
	uint8_t	block_hash[SHA256_DIGEST_LENGTH];
	uint8_t	tx_id[SHA256_DIGEST_LENGTH];
	tx_out_t	out;
} unspent_tx_out_t;

tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN]);

/**
 * struct visitor_s - visitor structure
 *
 * @sender_unspent: list to collect sender's unspent transaction outputs
 * @sender_pub: sender's public key
 * @total_amount: amount of unspent transaction outputs
 * @amount: amount to send
 */
typedef struct visitor_s
{
	llist_t *sender_unspent;
	uint8_t *sender_pub;
	uint64_t total_amount;
	uint64_t amount;

} visitor_t;

/**
 * struct validation_visitor_s - validation visitor structure
 *
 * @in_amount: total transaction input amount
 * @out_amount: total transaction output amount
 * @all_unspent: all unspent transaction outputs
 * @tx: transaction to validate
 * @block_index: the block index cointaining @tx
 * @valid: whether or not tx is valid
 */
typedef struct validation_visitor_s
{
	int64_t in_amount;
	int64_t out_amount;
	llist_t *all_unspent;
	transaction_t const *tx;
	uint32_t block_index;
	int32_t valid;
} validation_vistor_t;

unspent_tx_out_t *unspent_tx_out_create(
	uint8_t block_hash[SHA256_DIGEST_LENGTH],
	uint8_t tx_id[SHA256_DIGEST_LENGTH], tx_out_t const *out);

tx_in_t *tx_in_create(unspent_tx_out_t const *unspent);

uint8_t *transaction_hash(
	transaction_t const *transaction,
	uint8_t hash_buf[SHA256_DIGEST_LENGTH]);

sig_t *tx_in_sign(
	tx_in_t *in, uint8_t const tx_id[SHA256_DIGEST_LENGTH],
	EC_KEY const *sender, llist_t *all_unspent);

transaction_t *transaction_create(
	EC_KEY const *sender, EC_KEY const *receiver, uint32_t amount,
	llist_t *all_unspent);

int transaction_is_valid(
	transaction_t const *transaction, llist_t *all_unspent);

transaction_t *coinbase_create(EC_KEY const *receiver, uint32_t block_index);

int coinbase_is_valid(transaction_t const *coinbase, uint32_t block_index);

void transaction_destroy(transaction_t *transaction);

llist_t *update_unspent(
	llist_t *transactions, uint8_t block_hash[SHA256_DIGEST_LENGTH],
	llist_t *all_unspent);

#endif /* _TRANSACTION_H_ */
