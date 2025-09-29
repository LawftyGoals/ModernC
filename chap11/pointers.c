#include <stdio.h>
#include <stdlib.h>

void double_swap(double *p0, double *p1, double *p2) {
  auto tmp = *p0;
  *p0 = *p1;
  *p1 = *p2;
  *p2 = tmp;
}
  



int main(int argc, char *argv[argc+1]){

  double d0 = 9.0;
  double d1 = 3.0;
  double d2 = 6.0;

  double_swap(&d0, &d1, &d2);

  printf("d0: %f, d1: %f, d2: %f\n", d0, d1, d2);

  return EXIT_SUCCESS;
}
