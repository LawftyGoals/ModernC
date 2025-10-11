#include <stdio.h>
#include <limits.h>

int main() {

  int f = 117;
  int n = 1;
  int b = 116;
  int m = INT_MIN;
  int j = -0;
  int y = -155;
  printf("%d %d %d %d %d %d\n", n & f, n & b, n & m, j & y, j, m & y);


  return 0;

}
