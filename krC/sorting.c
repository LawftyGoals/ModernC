#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MAXLINES 5000
#define NUMERIC 1
#define REVERSE 2
#define FOLD 4
#define DIRECTORY 8

char *lineptr[MAXLINES];

static short options = 0;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int getLine(char *, int);
int numcmp(const char *, const char *);
int charCompare(const char*, const char*);
int toLower(char);

void qSort(void *lineptr[], int left, int right, int (*comp)(const void *, const void *));

int main(int argc, char *argv[]){
  int nlines;
  int argcount = argc;

  while(--argcount > 0){
    if((*++argv)[0] == '-'){
      char c;
      while((c = *++argv[0])){
        switch(c) {
          case 'n':
            options |= NUMERIC;
            break;
          case 'r':
            options |= REVERSE;
            break;
          case 'f':
            options |= FOLD;
            break;
          case 'd':
            options |= DIRECTORY;
            break;
          default:
            argcount = 1;
            printf("unrecognized argument %c\n", c);
            break;
          }
      }
    }
  }

  if(argcount) {
    printf("invalid argument usage: -dfnr\n");
    return 1;
  } else if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
    if(NUMERIC & options)
      qSort((void **) lineptr, 0, nlines-1, (int (*)(const void *, const void*))numcmp);
    else
      qSort((void **) lineptr, 0, nlines-1, (int (*)(const void *, const void*))charCompare);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big for sort\n");
    return 1;
  }
}


int charCompare(const char *s, const char *t){

  char a, b;

  int fold = FOLD & options;
  int directory = DIRECTORY & options;
  do {
    if(directory){
      while(!isalnum(*s) && *s != ' ' && *s != '\0') s++;
      while(!isalnum(*t) && *t != ' ' && *t != '\0') t++;
    }

    a = fold ? toLower(*s) : *s;
    s++;
    b = fold ? toLower(*t) : *t;
    t++;

    if(a == '\0' && a == b) return 0;
  } while(a == b);
  
  return a - b;

}

int toLower(char c){
  return c >= 'A' && c <= 'Z' ? c + 32 : c;
}


int readlines(char *lptr[], int maxlines){
  int len, nlines;
  char *p, line[maxlines];

  nlines = 0;
  while((len = getLine(line, MAXLEN)) > 0) {
    if(nlines >= maxlines || (p = malloc(len)) == NULL){
      return -1;
    } else {
      line[len-1] = '\0';
      strcpy(p, line);
      lptr[nlines++] = p;
    }
  }

  return nlines;
}

void writelines(char *lptr[], int nlines){
  int i;
  if(options & REVERSE) {
    for(i = nlines-1; i >= 0; i--) {
      printf("%s\n", lptr[i]);
    }
  }  
  else {
    for(i = 0; i < nlines; i++) {
      printf("%s\n", lptr[i]);
    }
  }
}


void qSort(void *v[], int left, int right, int (*comp)(const void *, const void *)){
  int i, last;
  void swap(void *v[], int, int);

  if(left >= right) return;
  swap(v, left, (left + right)/2);
  last = left;

  for(i = left + 1; i <= right; i++){
    if((*comp)(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  }
  
  swap(v, left, last);
  qSort(v, left, last-1, comp);
  qSort(v, last+1, right, comp);
}


void swap(void *v[], int i, int j){
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int getLine(char *s, int maxlen){
  int i;
  char c;
  for (i = 0; i < maxlen - 1 && (c = getchar()) != '\n' && c != EOF; i++){
    s[i] = c;
  }
  if(c == '\n') s[i++] = c;

  s[i] = '\0';

  return i;
}


int numcmp(const char *s1, const char *s2){
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);

  if(v1 < v2) return -1;
  else if (v1 > v2) return 1;
  else return 0;
}
