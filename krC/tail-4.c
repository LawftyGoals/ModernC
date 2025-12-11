#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 100
#define MAXLINES 100
#define DEFAULTPOOL 10

int getLine(char *, int);
void error(char *);

int main(int argc, char *argv[]){
  char line[MAXLEN];
  char *allLines[MAXLINES];
  char *p, *buff, *buffend;
  int first, last, len, nlines, size;

  if(argc == 2 && *argv[1] == '-'){
    size = atoi(++argv[1]);
  } else if(argc == 1){
    size = DEFAULTPOOL;
  } else {
    error("too many arguments");
  }

  if((p = buff = malloc(MAXLEN * MAXLINES)) == NULL) {
    error("cannot allocat memory");
  }
  buffend = buff + MAXLEN * MAXLINES;
  last = 0;
  nlines = 0;

  while((len = getLine(line, MAXLEN)) > 0) {
    if(p + len + 1 >= buffend) {
      p = buff;
    }
    allLines[last] = p;
    strcpy(allLines[last], line);
    if(++last >= MAXLINES){
      last = 0;
    }
    p += len + 1;
    nlines++;
  }

  if(size > nlines){
    size = nlines;
  }
  
  first = last - size;

  if(first < 0){
    first += MAXLINES;
  }

  int i;
  for(i = first; size-- > 0; i = (i+1) % MAXLINES){
    printf("%s", allLines[i]);
  }

  return 0;
}



int getLine(char *s, int maxlen){
  int i;
  char c;
  for(i = 0; (c = getchar()) != '\n' && c != EOF && i < (maxlen + 1); i++) {
    s[i] = c;
  }

  if(c == '\n') s[i++] = c;
  s[i] = '\0';
  
  return i;
}
