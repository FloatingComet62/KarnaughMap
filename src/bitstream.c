#include "src.h"

Bitstream bitstream_init(u32 sizeInBits) {
  u32 sizeInBytes = sizeInBits / 8;
  u8* data = malloc(max(sizeInBytes, 1));
  for (int i = 0; i < sizeInBytes; i++) {
    data[i] = 0;
  }
  return (Bitstream){data, sizeInBits};
}

void bitstream_insertbit(Bitstream* bitstream, u32 index) {
  u32 u8Index = index / 8;
  u32 u8Shift = index % 8;
  bitstream->data[u8Index] |= 0b1 << u8Shift;
}

u8 bitstream_getbit(Bitstream* bitstream, u32 index) {
  u32 u8Index = index / 8;
  u32 u8Shift = index % 8;
  return ((bitstream->data[u8Index]) & (0b1 << u8Shift)) == 0 ? 0 : 1;
}

void bitstream_print(Bitstream* bitstream) {
  for (int i = 0; i < bitstream->size / 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((bitstream->data[i] >> j) & 1) {
        printf("1");
      } else {
        printf("0");
      }
    }
  }
}