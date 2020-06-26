#include "Bits.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

B_API void bit_print_bin(const size_t size, const void * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
        printf(" ");
    }
    puts("");
}


B_API int bit_print_hex_big_endian(unsigned char *buff,long size)
{
    for (int i=0;i<size;++i)
    {
        printf ("%02X ",buff[i]);
    }
    printf ("\n");
    return size;
}

B_API int bit_print_hex_little_endian(unsigned char *buff,long size)
{
    for (int i=size-1;i>=0;--i)
    {
        printf ("%02X ",buff[i]);
    }
    printf ("\n");
    return size;
}


B_API int bit_get(uint8_t byte,int idx)
{
    int i;

    for(i = 7; 0 <= i; i --)
    {
        if(i==idx)
        {
            //printf("bit idx: %d value: %d\n",idx ,(byte >> i) & 0x01);
            return (int)( (byte >> i) & 0x01);
        }

    }
    return -1;
}
//sets bits


B_API unsigned short bit_reverse_bit(unsigned short x)
{
    x = (x & 0xFF) << 8 | (x & 0xFF00) >>  8;
    return x;
}

B_API void bit_toggle(uint8_t *byte,int idx,bool val)
{
    *byte |= val << idx;

}
B_API void bit_clear(uint8_t *byte,int idx)
{
    *byte &= ~(1UL << idx);

}
B_API void bit_set(uint8_t *byte,int idx,bool x)
{
    *byte^= (-x ^ *byte) & (1UL << idx);

}

B_API void test_bytes_order()
{
    uint16_t x = 1; /* 0x0001 */
    printf("%s\n", *((uint8_t *) &x) == 0 ? "big-endian" : "little-endian");
}
