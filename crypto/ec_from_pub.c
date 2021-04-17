#include "hblk_crypto.h"

/**
 * ec_from_pub - generates EC_KEY from pub key
 * @pub: the pub key in buffer
 * Return: pointer to generated EC_KEY struct or NULL
 */
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY *key;
	EC_POINT *point;

	if (!pub) /* Needed? */
		return (NULL);
	key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!key)
		return (NULL);
	point = EC_POINT_new(EC_KEY_get0_group(key));
	if (!point)
	{
		EC_KEY_free(key);
		return (NULL);
	}
	if (!EC_POINT_oct2point(EC_KEY_get0_group(key), point, pub, EC_PUB_LEN, NULL)
		|| !EC_KEY_set_public_key(key, point))
	{
		EC_KEY_free(key);
		EC_POINT_free(point);
		return (NULL);
	}
	EC_POINT_free(point);
	return (key);
}
