#include <stdio.h>
#include <limits.h>
#include <float.h>



int main() {

  char basechar;
  short baseshort;
  int baseint;
  long baselong;
  
  unsigned char uchar;
  unsigned short ushort;
  unsigned int uint;
  unsigned long ulong;

  signed char schar;
  signed short sshort;
  signed int sint;
  signed long slong;

  printf("char: %c, %c, uchar: %c, %c, schar: %c, %c\n", CHAR_MAX, CHAR_MIN, UCHAR_MAX, 0, SCHAR_MAX, SCHAR_MIN);

  unsigned bobs = 0;
  printf("%u\n", (bobs-1)/8);
  
  return 0;
}
