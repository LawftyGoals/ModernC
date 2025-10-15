#include <stdio.h>

int main(){

  size_t test = 100000000;

  printf("%lu\n", sizeof(test));

  int i = 0;
  while(i++ < 10){
    printf("%d\n", i);
  }

  return 0;
}

