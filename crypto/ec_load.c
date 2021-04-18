#include "hblk_crypto.h"

/**
 * ec_load - load an EC key pair from the disk
 * @folder: path to folder from which to load the keys
 *
 * Return: pointer to created EC key pair, NULL on error
 */
EC_KEY *ec_load(char const *folder)
{
EC_KEY *key = NULL;
char buf[BUFSIZ];
FILE *fp;

if (!folder || strlen(folder) + strlen(PUB_FILENAME) > BUFSIZ)
return (NULL);

sprintf(buf, "%s/%s", folder, PUB_FILENAME);
fp = fopen(buf, "r");
if (!fp)
return (NULL);
if (!PEM_read_EC_PUBKEY(fp, &key, NULL, NULL))
goto out;
sprintf(buf, "%s/%s", folder, PRI_FILENAME);
fp = fopen(buf, "r");
if (!fp)
return (NULL);
if (!PEM_read_ECPrivateKey(fp, &key, NULL, NULL))
goto out;
out:
fclose(fp);
return (key);
}

