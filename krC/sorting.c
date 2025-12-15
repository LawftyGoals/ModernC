#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);
int getLine(char *, int);
int numcmp(const char *, const char *);
void toLowerCase(char *);

void qSort(void *lineptr[], int fold,  int left, int right, int (*comp)(const void *, const void *));

int main(int argc, char *argv[]){
  int nlines;
  int numeric = 0;
  int reverse = 0;
  int fold = 0;
  int argcount = argc;

  while(--argcount > 0){
    if((*++argv)[0] == '-'){
      char c;
      while((c = *++argv[0])){
        switch(c) {
          case 'n':
            numeric = 1;
            break;
          case 'r':
            reverse = 1;
            break;
          case 'f':
            fold = 1;
            break;
          default:
            printf("unrecognized argument %c\n", c);
            break;
          }
      }
    }
  }

  if((nlines = readlines(lineptr, MAXLINES)) >= 0){
    qSort((void **) lineptr, fold, 0, nlines-1, (int (*)(const void *, const void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines, reverse);
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

void writelines(char *lptr[], int nlines, int reverse){
  int i;
  if(reverse) {
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


void qSort(void *v[], int fold, int left, int right, int (*comp)(const void *, const void *)){
  int i, last;
  void swap(void *v[], int, int);

  if(left >= right) return;
  swap(v, left, (left + right)/2);
  last = left;

  if(fold) {
    char sleft[MAXLEN]; 
    strcpy(sleft, v[left]);
    toLowerCase(sleft);
    for(i = left + 1; i <= right; i++){
      char si[MAXLEN];
      strcpy(si, v[i]);
      toLowerCase(si);
      if((*comp)(si, sleft) < 0){
        swap(v, ++last, i);
      }
    }
  } else {
    for(i = left + 1; i <= right; i++){
      if((*comp)(v[i], v[left]) < 0) {
        swap(v, ++last, i);
      }
    }
  }
  swap(v, left, last);
  qSort(v, fold, left, last-1, comp);
  qSort(v, fold, last+1, right, comp);
}

void toLowerCase(char *s){
  size_t i;
  for(i = 0; s[i] != '\0'; i++){
    if(s[i] >= 'A' && s[i] <= 'Z') {
      s[i] += 32;
    }
  }
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
