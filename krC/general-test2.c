#include <stdio.h>
#include "custom-functions2.h"

int main() {

  char s1[20];
  int n1 = 123;
  int p1 = 10;

  itoa2(n1, s1, p1);

  printf("padded: %s\n", s1);
  
  print_binary(-123);

  return 0;
}

