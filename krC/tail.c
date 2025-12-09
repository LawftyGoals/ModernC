#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXLEN 100
#define LASTLINES 10
#define LINES 100

int getLine(char*, int);
void error(char*);

int main(int argc, char *argv[]) {
  char line[MAXLEN];
  char *lines[LINES];
  size_t size;
  char *p, *buff, *buffend;
  int last, first, len, nlines;


  if(argc == 1) {
    size = LASTLINES;
  }
  else if (argc == 2 && (*++argv)[0] == '-'){
    size = atoi(++(*argv));
  } else {
    error("usage: tail (-n)");
  }

  if((p = buff = malloc(LINES * MAXLEN)) == NULL){
    error("tail: cannot allocate buffer");
  }

  buffend = buff + LINES * MAXLEN;
  last = 0;
  nlines = 0;

  while((len = getLine(line, MAXLEN)) > 0) {
    if(p + len + 1 >= buffend) {
      p = buff;
    }
    lines[last] = p;
    strcpy(lines[last], line);
    if(++last >= LINES) {
      last = 0;
    }
    p += len + 1;
    nlines++;
  }

  if(size > nlines) {
    size = nlines;
  }
  first = last - size;
  if( first < 0 ) {
    first += LINES;
  }
  
  int i;
  for(i = first; size-- > 0; i = (i + 1) % LINES){
    printf("%s", lines[i]);
  }

  return 0;

}

int getLine(char line[], int maxlength){
  char c;
  int i = 0;
  while((c = getchar()) != '\n' && c != EOF && i < (maxlength - 1)){
    line[i++] = c;
  }
  if(c == '\n') line[i++] = '\n';

  line[i] = '\0';
  
  return i;

}

void error(char *s){
  printf("%s\n", s);
  exit(1);
}
