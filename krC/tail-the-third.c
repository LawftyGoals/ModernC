#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 100
#define MAXLINES 100
#define LASTLINES 10

int getLine(char *, int);
void error(char *);

int main(int argc, char *argv[]) {
  char line[MAXLEN];
  char *allLines[MAXLINES];

  char *p, *buff, *buffend;
  int size, numlines, len, first, last;

  if(argc == 2 && *argv[1] == '-') {
    size = atoi(++argv[1]);
  } else if (argc == 1) {
    size = LASTLINES;
  } else {
    error("too many arguments");
  }

  if((p = buff = malloc(MAXLINES * MAXLEN)) == NULL) {
      error("unable to allocate memory");
  }

  buffend = buff + MAXLEN * MAXLINES;

  last = 0;
  numlines = 0;

  while((len = getLine(line, MAXLEN)) > 0) {
    if(p + len + 1 > buffend) {
      p = buff;
    }
    allLines[last] = p;
    strcpy(allLines[last], line);
    if(++last >= MAXLINES) {
      last = 0;
    }
    p += len + 1;
    numlines++;
  }

  if(size > numlines) {
    size = numlines;
  }

  first = last - size;

  if(first < 0) {
    first += MAXLINES;
  }

  int i;
  
  for(i = first; size-- > 0; i = (i+1) % MAXLINES) {
    printf("%s", allLines[i]);
  }


  return 0;
}

int getLine(char *s, int maxlen){
  int i;
  char c;
  for(i = 0; i < maxlen -1 && (c = getchar()) != '\n' && c != EOF; i++){
    s[i] = c;
  }

  if(c == '\n') {
    s[i++] = '\n';
  }
  s[i] = '\0';
  
  return i;
}

void error(char *s) {
  printf("%s\n", s);
  exit(1);
}
