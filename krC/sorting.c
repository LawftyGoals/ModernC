#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int getLine(char *, int);
int numcmp(const char *, const char *);

void qSort(void *lineptr[], int left, int right, int (*comp)(const void *, const void *));

int main(int argc, char *argv[]){
  int nlines;
  int numeric = 0;

  if(argc > 1 && strcmp(argv[1], "-n") == 0) numeric = 1;

  if((nlines = readlines(lineptr, MAXLINES)) >= 0){
    qSort((void **) lineptr, 0, nlines-1, (int (*)(const void *, const void *))(numeric ? numcmp : strcmp));
    return 0;
  } else {
    printf("input too big for sort\n");
    return 1;
  }
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
  for(i = 0; i < nlines; i++) {
    printf("%s\n", lptr[i]);
    free(lptr[i]);
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
  qsort(v, left, last-1, comp);
  qsort(v, last+1, right, comp);
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
