#include <stdio.h>

int main() {

  int i;

  for(i = 0; i < 3; ++i) {
    printf("++i: %d\n", i);
  }
  for(i = 0; i < 3; i++) {   
    printf("i++: %d\n", i);
  }
  int j = 0;
  while(++j < 3) {
    printf("++j < 3: %d\n", j);
  }

  j = 0;
  while(j++ < 3) {
    printf("j++ < 3: %d\n", j);
  }




  return 0;
}
