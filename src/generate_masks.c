#include "src.h"

Bitstream generate_masks(u32 number_of_variables) {
  u32 powered_n = pow(2, number_of_variables);
  Bitstream bitstream = bitstream_init(number_of_variables * powered_n);

  u32 iter = 0;
  for (u32 i = powered_n; i >= 1; i /= 2) {
    for (u32 _ = 0; _ < powered_n / i; _++) {
      iter += i / 2;
      for (u32 j = 0; j < i / 2; j++) {
        bitstream_insertbit(&bitstream, iter++);
      }
    }
  }
  return bitstream;
}