#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef B_STATIC
#define B_API static
#else
#define B_API extern
#endif

B_API void test_bytes_order();

B_API void bit_print_bin(const size_t size, const void * const ptr);
B_API int  bit_print_hex_little_endian(unsigned char *buff,long size);
B_API int  bit_print_hex_big_endian(unsigned char *buff,long size);


B_API int  bit_get(uint8_t byte,int idx);
B_API void bit_set(uint8_t *byte,int idx,bool val);


B_API void bit_toggle(uint8_t *byte,int idx,bool val);
B_API void bit_clear(uint8_t *byte,int idx);




B_API unsigned short bit_reverse_bit(unsigned short x);


#ifdef __cplusplus
}
#endif
	
