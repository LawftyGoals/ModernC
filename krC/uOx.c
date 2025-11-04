#include <stdio.h>
#include <tgmath.h>
int main(){
  unsigned us = 0;
  unsigned oxs = 0x8000;

  printf("%u us, %u oxs, test: %d, u: %u, l: %lu, ll: %llu\n", us-1, oxs, (int)pow(2, 16)/2, -1U, -1UL, -1ULL);

  return 0;
}
