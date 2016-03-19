#include <stdio.h>

int main() {
  unsigned int i1 = 1835098984u;
  unsigned int i2 = 1768842611u;
  unsigned char c1,c2,c3,c4,c5,c6,c7,c8 = 0;

  c1 = i1 >> 24;
  c2 = i1 >> 16;
  c3 = i1 >> 8;
  c4 = i1 >> 0;

  c5 = i2 >> 24;
  c6 = i2 >> 16;
  c7 = i2 >> 8;
  c8 = i2 >> 0;

  printf("%c%c%c%c%c%c%c%c\n",c1,c2,c3,c4,c5,c6,c7,c8);

}
