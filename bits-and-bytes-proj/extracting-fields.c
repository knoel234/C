#include <stdio.h>


int main() {
  unsigned int a = 0xCAFEBABE;
  
  unsigned int b = a >> 29;
  unsigned int c = (a << 3) >> 28;
  unsigned int d = (a << 7) >> 28;
  unsigned int e = (a << 11) >> 29;
  unsigned int f = (a << 14) >> 29;
  unsigned int g = (a << 17) >> 28;
  unsigned int h = (a << 21) >> 28;
  unsigned int i = (a << 25) >> 29;
  unsigned int j = (a << 28) >> 30;
  unsigned int k = (a << 30) >> 30;

  printf("%d %d %d %d %d %d %d %d %d %d\n",b,c,d,e,f,g,h,i,j,k);

}
