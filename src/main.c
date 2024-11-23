#ifndef TEST
#include "src.h"

Bitstream mapFromBitstream(Bitstream* bitstream, u32 mask_size, u32 offset) {
  Bitstream output = bitstream_init(mask_size);
  for (u32 j = 0; j < mask_size; j++) {
    if (!bitstream_getbit(bitstream, offset + j)) {
      continue;
    }
    bitstream_insertbit(&output, j);
  }
  return output;
}

u8 bitwise_and(u8 x_bit, u8 y_bit) { return x_bit & y_bit; }
u8 bitwise_invert(u8 bit) { return bit == 0 ? 1 : 0; };

bool checkMask(Bitstream* input, Bitstream* mask) {
  Bitstream weighted_mask = bitstream_bitwise(input, mask, &bitwise_and);
  return bitstream_eq(&weighted_mask, input);
}

int main() {
  u32 n = 3;
  u32 powered_n = pow(2, n);
  Bitstream input = bitstream_init(powered_n);

  // // input.data = 0b11011001;
  // bitstream_insertbit(&input, 0);
  // bitstream_insertbit(&input, 1);
  // bitstream_insertbit(&input, 3);
  // bitstream_insertbit(&input, 4);
  // bitstream_insertbit(&input, 7);

  // input.data = 0b00110011;
  bitstream_insertbit(&input, 2);
  bitstream_insertbit(&input, 3);
  bitstream_insertbit(&input, 6);
  bitstream_insertbit(&input, 7);

  Bitstream masks = generate_masks(n);

  for (u32 i = 0; i < n; i++) {
    Bitstream variable_mask =
        mapFromBitstream(&masks, powered_n, i * powered_n);
    Bitstream complement_variable_mask =
        bitstream_bitwise_map(&variable_mask, &bitwise_invert);

    if (checkMask(&input, &variable_mask)) {
      printf("%c", 'A' + i);
    }
    if (checkMask(&input, &complement_variable_mask)) {
      printf("%c", 'a' + i);
    }

    bitstream_deinit(&variable_mask);
    bitstream_deinit(&complement_variable_mask);
  }

  bitstream_deinit(&masks);
  bitstream_deinit(&input);
  return 0;
}

#endif