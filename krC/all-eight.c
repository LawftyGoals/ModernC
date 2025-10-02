#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define limit 80

unsigned getline(char line[]);


int main() {
  unsigned len;
  char line[MAXLINE];

  while ((len = getline(line)) > 0){
    printf("%u\n",len);
    if(len > limit) {
      printf("%s", line);
    }
  }

  return EXIT_SUCCESS;
}


unsigned getline(char s[]) {
  unsigned i;
  char c;
  for(i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

