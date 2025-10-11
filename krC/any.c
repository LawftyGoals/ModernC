#include <stdio.h>


int any(char string1[], char string2[]);

int main(){

  char s1[] = "this is a test";
  char s2[] = "cba";

  printf("index of same letter: %d\n", any(s1, s2));

  return 0;
}


int any(char s1[], char s2[]){

  int i;
  i=0;


  while (s1[i] != '\0'){
    int j;
    for(j = 0; s2[j] != '\0'; j++){
      if((s1[i] == s2[j])){
        return i;
      }
    }
    i++;
  }

  return -1;
}
