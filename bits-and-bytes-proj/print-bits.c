#include <stdio.h>


void function(char value)
{
  int mask = 0x80;
  for(int i = 0; i < 8; i++)
  {
    printf("%d", ( value & (1 << (7-i)) ) >> (7-i));
  }
  printf("\n");
}


int main() {
  unsigned char a = 181;
  signed char b = -75;

  function(a);
  function(b);

}
