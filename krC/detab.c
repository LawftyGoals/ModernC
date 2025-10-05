#include <stdio.h>

#define MAXLINE 1000
const int TABWIDTH = 8;
int tabreplace(char line[MAXLINE]);

int main() {

  char line[MAXLINE];

  printf("%d", 0 % 8);
  while(tabreplace(line) > 0) {
    printf("%s", line);
  }

  printf("\ttab1\n");
  printf("ta\tb2\n");
  printf("1234567890\n");
  return 0;
}


int tabreplace(char s[MAXLINE]){
  int i = 0;
  char c;
  
  while (i < MAXLINE && (c = getchar()) != EOF && c != '\n'){
    
    if(c == '\t') {
      int j;
      int mod = i % TABWIDTH; 
      for(j = 0; j < (mod ? TABWIDTH - mod : TABWIDTH); ++j){
        s[i] = ' ';
        ++i;
      }
    } else {
      s[i] = c;
      ++i;
    }
  }
  if(c == '\n') {
     s[i] = '\n';
     ++i;
     s[i] = '\0';
  }

  return i;
}

