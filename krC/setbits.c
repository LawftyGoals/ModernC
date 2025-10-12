#include <stdio.h>

unsigned rightrot(unsigned, int);

unsigned setbits(unsigned, int, int, unsigned);

unsigned invert(unsigned, int, int);


int main() {


  printf("%u\n", setbits(10, 4, 3, 5));
  
  printf("%u\n", rightrot(343, 3));

  printf("%u\n", invert(343, 4, 2));

  printf("%i\n", (~((int)0)<<1));
  return 0;
}

unsigned invert(unsigned x, int p, int n){
  unsigned oned = (unsigned)((~(unsigned)0) << ((sizeof(x) * 8) - p)) >> ((sizeof(x) * 8) - n);
  printf("oned: %u / %u / %u\n", oned, ((~(unsigned)0) >> 4 ), ~(unsigned)0);
  unsigned inversed = (oned & ~x);
  printf("inversed: %u\n", inversed);
  unsigned hollowed = (~oned) & x;
  
  return inversed + hollowed;
}


unsigned rightrot(unsigned x, int n) {
  unsigned leftshoft = x << ((sizeof(x)*8)-n);
  unsigned rightshift = x >> n;

  return rightshift + leftshoft;
}



unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned leftmosty = (y & ~((~0) << n)) << p;
  unsigned center = ~(((~0) >> ((sizeof(x) * 8) - n)) << p);
  unsigned removedx = x & center;

  return removedx + leftmosty;
}

/*
 * 1010
 *  101
 * 0000000101011011
 * 0000000101010111 
*/

