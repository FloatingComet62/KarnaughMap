#include "src.h"

Bitstream bitstream_init(u32 sizeInBits) {
  u32 sizeInBytes = max(sizeInBits / 8, 1);
  u8* data = malloc(sizeInBytes);
  for (int i = 0; i < sizeInBytes; i++) {
    data[i] = 0;
  }
  return (Bitstream){data, sizeInBytes * 8};
}

void bitstream_deinit(Bitstream* bitstream) { free(bitstream->data); }

void bitstream_insertbit(Bitstream* bitstream, u32 index) {
  if (index >= bitstream->size) {
    return;
  }
  u32 u8Index = index / 8;
  u32 u8Shift = index % 8;
  bitstream->data[u8Index] |= 0b1 << u8Shift;
}

u8 bitstream_getbit(Bitstream* bitstream, u32 index) {
  if (index >= bitstream->size) {
    return 0;
  }
  u32 u8Index = index / 8;
  u32 u8Shift = index % 8;
  return ((bitstream->data[u8Index]) & (0b1 << u8Shift)) == 0 ? 0 : 1;
}

void printBit(u8 bit) {
  if (bit & 1) {
    printf("1");
  } else {
    printf("0");
  }
}

void bitstream_print(Bitstream* bitstream) {
  for (int i = 0; i < bitstream->size / 8; i++) {
    for (int j = 0; j < 8; j++) {
      printBit(bitstream->data[i] >> j);
    }
  }
  // equivalent:
  // for (u32 i = 0; i < bitstream->size; i++) {
  //   printBit(bitstream_getbit(bitstream, i));
  // }
}

Bitstream bitstream_bitwise(Bitstream* x, Bitstream* y,
                            u8 (*comparision_func)(u8 x_bit, u8 y_bit)) {
  Bitstream output = bitstream_init(x->size);
  if (x->size != y->size) {
    // fuck you
    return output;
  }
  for (u32 i = 0; i < x->size; i++) {
    if (!comparision_func(bitstream_getbit(x, i), bitstream_getbit(y, i))) {
      continue;
    }
    bitstream_insertbit(&output, i);
  }
  return output;
}

Bitstream bitstream_bitwise_map(Bitstream* bitstream, u8 (*map)(u8 x_bit)) {
  Bitstream output = bitstream_init(bitstream->size);
  for (u32 i = 0; i < bitstream->size; i++) {
    if (!map(bitstream_getbit(bitstream, i))) {
      continue;
    }
    bitstream_insertbit(&output, i);
  }
  return output;
}

bool bitstream_eq(Bitstream* x, Bitstream* y) {
  if (x->size != y->size) {
    return false;
  }
  for (u32 i = 0; i < x->size; i++) {
    if (bitstream_getbit(x, i) == bitstream_getbit(y, i)) {
      continue;
    }
    return false;
  }
  return true;
}