#include <stdio.h>
#include <string.h>




int main(void){
  char *test1 = "abcd";
  char *test2 = "abde";

  printf("abcd - abde : %d\n", strcmp(test1, test2));
  printf("abde - abcd : %d\n", strcmp(test2, test1));

  return 0;
}
