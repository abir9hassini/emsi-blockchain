CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g3

SRC = sha256.c ec_create.c ec_to_pub.c ec_from_pub.c ec_save.c ec_load.c ec_sign.c ec_verify.c
OBJS = $(patsubst %.c, %.o, $(SRC))
LIB = libhblk_crypto.a

.PHONY: libhblk_crypto.a

libhblk_crypto.a: $(OBJS)
	ar rcs $(LIB) $(OBJS)
