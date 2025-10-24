

#include <stdio.h>

void expand(char s1[], char s2[]);


int main() {

  char s1[] = "hello a-z, 1-3";
  char s2[100];

  expand(s1, s2);
  printf("%s\n", s2);

  return 0;
}

void expand(char s1[], char s2[]){

  int i, j;
  for (i = j = 0; s1[i] != '\0'; ++i) {

    if(s1[i] == '-') {
      char c = s1[i-1] + 1;
      while(c < s1[i+1]) {
        s2[j++] = c;
        c++;
      }
    } else {
      s2[j++] = s[i];
    }


  }


}
