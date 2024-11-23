#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define u8 uint8_t
#define u32 uint32_t

#define min(a, b) ((a) > (b)) ? (b) : (a)
#define max(a, b) ((a) > (b)) ? (a) : (b)

typedef struct {
  u8* data;
  u32 size;
} Bitstream;
Bitstream bitstream_init(u32 sizeInBits);
void bitstream_deinit(Bitstream* bitstream);
void bitstream_insertbit(Bitstream* bitstream, u32 index);
u8 bitstream_getbit(Bitstream* bitstream, u32 index);
void bitstream_print(Bitstream* bitstream);

Bitstream bitstream_bitwise(Bitstream* x, Bitstream* y,
                            u8 (*comparision_func)(u8 x_bit, u8 y_bit));
Bitstream bitstream_bitwise_map(Bitstream* bitstream, u8 (*map)(u8 x_bit));
bool bitstream_eq(Bitstream* x, Bitstream* y);

Bitstream generate_masks(u32 number_of_variables);