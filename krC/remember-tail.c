#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#define LINES 100
#define MAXLEN 100
#define DEFAULTLINES 10

int getLine(char *, int);
void error(char *);


int main(int argc, char *argv[]){
  char line[MAXLEN];
  char *allLines[LINES];

  char *p, *buff, *buffend;
  
  int size, first, last, nlines, len;

  if (argc == 2 && *argv[1] == '-') {
    size = atoi(++(argv[1]));
  } else if (argc == 1) {
    size = DEFAULTLINES;
  } else {
    error("invalid number of arguments");
  }

  if((p = buff = malloc(MAXLEN * LINES)) == NULL) {
    error("can not allocate memory for buffer");
  }

  buffend = buff + MAXLEN * LINES;
  last = 0;
  nlines = 0;


  while((len = getLine(line, MAXLEN)) > 0) {
    if(p + len + 1 >= buffend) p = buff;
    allLines[last] = p;
    strcpy(allLines[last], line);
    if(++last >= LINES){
      last = 0;
    }
    p += len + 1;
    nlines++;
  }


  if(size > nlines) {
    size = nlines;
  }

  first = last - size;
  if(first < 0) {
    first += LINES;
  }

  int i;
  for(i = first; size-- > 0; i = (i + 1) % LINES){
    printf("%s", allLines[i]);
  }


  return 0;
}

int getLine(char *s, int maxlen) {

  char c;
  int i;

  for(i = 0; (c = getchar()) != '\n' && c != EOF && i < (maxlen - 1); i++) {
    s[i] = c;
  }

  if(c == '\n') s[i++] = '\n';

  s[i] = '\0';
  
  return i;
}

void error(char *s) {
  printf("%s", s);
  exit(1);
}
