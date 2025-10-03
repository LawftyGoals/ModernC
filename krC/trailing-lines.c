#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

signed remove_trailing(char line[MAXLINE]);


int main() {

  char line[MAXLINE];
  signed length;
  while((length = remove_trailing(line)) > 0){
      if(length > 0){
        printf("%s", line);
      }
  }

  return EXIT_SUCCESS;
}


signed remove_trailing(char s[MAXLINE]){
  signed i;
  char c;

  for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i){
    s[i] = c;
  }

  --i;

  while(i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
    --i;
  }

  if(i >= 0) {
    i++;
    s[i] = '\n';
    i++;
    s[i] = '\0';
  }

  return i;
}




  
