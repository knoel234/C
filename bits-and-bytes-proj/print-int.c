#include <stdio.h>

int main() {
  int x = 10;
  int y = 13;

  printf("x = %d\n", x);
  printf("y = %d\n", y);
  printf("size of signed int in bytes is %zu.\n",sizeof(int));
  printf("size of signed int in bits is %zu.\n",8*sizeof(int));  
  printf("%d + %d = %d.\n",x,y,x+y);
}