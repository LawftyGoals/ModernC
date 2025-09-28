#include <stdlib.h>
#include <stdio.h>

#define sum(a, b) a+b
#define max(a, b) ((a) < (b) ? (b) : (a))

int main(int argc, char *argv[argc + 1]) {

  signed i = 8;
  printf("macro sum: %d\n", sum(5, 2)*7);
  printf("macro max: %d\n", max(i++, 5));
  printf("i: %d\n", i); 

  return EXIT_SUCCESS;
}

