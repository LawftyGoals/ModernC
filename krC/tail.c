#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXLEN 100
#define LASTLINES 10
#define LINES 100

int getLine(char*, int);

int main(int argc, char *argv[]) {
  char line[MAXLEN];
  char *lines[LINES];
  size_t size = 10;

  if (argc > 1 && (*++argv)[0] == '-'){
    size = atoi(++(*argv));
  }




  int j = 0;

  while(getLine(line, MAXLEN) > 0) {
    strcpy(lines[j], line);
    j++;
  }

  int i;
  char *test;
  for(i = 0; i < size && i < j; i++){
    if((test = lines[i]) != NULL){
      printf("%s\n", test);
    }
  }



}

int getLine(char line[], int maxlength){
  char c;
  int i = 0;
  while((c = getchar()) != '\n' && c != EOF && i++ <( maxlength-1)){
    *line++ = c;
  }
  if(c == '\n') *line++ = '\n';
  *line = '\0';
  return i;
}
