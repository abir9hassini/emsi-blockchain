#include <stdio.h>
#include <stdint.h>


void _print_hex_buffer(uint8_t const *buf, size_t len)
{

size_t index;


for (index = 0 ; index < len ; index++)
{
printf("%02x", buf[index]);
}
printf("\n");
}

