#ifndef TEST
#include "src.h"

int main() {
  // int* x = malloc(5 * 5);
  // for (int i = 0; i < 25; i++) {
  //   x[i] = 0;
  // }

  // int y = calloc(5, 5);

  // return 0;
  // int n = 3;
  // Bitstream masks = generate_masks(n);

  Bitstream masks = bitstream_init(32);
  bitstream_insertbit(&masks, 5);

  printf("%d", bitstream_getbit(&masks, 5));

  printf("\n");
  bitstream_print(&masks);
  return 0;
}

#endif