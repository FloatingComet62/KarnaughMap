#include "../src/src.h"
#include "test.h"

bool test_comparision() {
  Bitstream x = bitstream_init(8);
  bitstream_insertbit(&x, 1);
  bitstream_insertbit(&x, 3);
  bitstream_insertbit(&x, 5);
  Bitstream y = bitstream_init(8);
  bitstream_insertbit(&y, 1);
  bitstream_insertbit(&y, 3);
  bitstream_insertbit(&y, 5);

  return bitstream_eq(&x, &y);
}

u8 bitwise_and(u8 x_bit, u8 y_bit) { return x_bit & y_bit; }

bool test_bitwise() {
  Bitstream x = bitstream_init(8);
  bitstream_insertbit(&x, 1);
  bitstream_insertbit(&x, 3);
  bitstream_insertbit(&x, 5);
  Bitstream y = bitstream_init(8);
  bitstream_insertbit(&y, 1);
  bitstream_insertbit(&y, 3);
  bitstream_insertbit(&y, 5);

  Bitstream response = bitstream_bitwise(&x, &y, &bitwise_and);
  return bitstream_eq(&response, &y);
}

void test_func(bool (*fun_ptr)(), const char* function_name) {
  printf("Testing \033[1;33m%s\033[0m ...", function_name);
  if (fun_ptr()) {
    printf(" \033[1;32mpassed\033[0m\n");
  } else {
    printf(" ... \033[1;31mfailed\033[0m\n");
  }
}

int main() {
  test_func(&test_bitwise, "bitstream:bitwise");
  test_func(&test_comparision, "bitstream:comparision");
  return 0;
}
