#include <stdio.h>
#include <string.h>




int main(void){
  char *test1 = "abcd";
  char *test2 = "abde";

  printf("%d\n", strncmp(test1, test2, 3));

  return 0;
}
