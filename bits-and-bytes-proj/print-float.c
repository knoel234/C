#include <stdio.h>

int main() {
  float x = 10.000000;
  float y = 13.000000;

  printf("x = %f\n", x);
  printf("y = %f\n", y);
  printf("size of float in bytes is %zu.\n",sizeof(int));
  printf("size of float in bits is %zu.\n",8*sizeof(int));  
  printf("%f + %f = %f.\n", x,y,x+y);
  printf("%f + %f = %d.\n", x,y,(int)(x+y));
}