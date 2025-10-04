#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int reverse(char line[MAXLINE]);


int main() {
  char line[MAXLINE];
  
  while(reverse(line) > 0){
    printf("%s", line);
  }

  return EXIT_SUCCESS;
}


int reverse(char s[MAXLINE]) {
  int i;
  char c;
  i = 0;
  while((c = getchar()) != EOF && c != '\n' && i < MAXLINE) {
    s[i] = c;
    ++i;
  }
  if(c == '\n' || c == EOF){
    s[i] = c;
    s[i + 1] = '\0'; 
  } 
  if(i < 2) return i;
  
  int mid = i / 2;
  --i;
  int j;
  for(j = 0; j < mid; ++j) {
    char temp = s[j];
    s[j] = s[i-j];
    s[i-j] = temp;
  }

  return i;
}



  
