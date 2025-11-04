#include "custom-functions2.h"
#include <stdio.h>

void itoa2(int, char *, int);
void reverse(char *);



void itoa2(int n, char s[], int p) {

  int i, sign;

  if(n < 0) sign = 1;
  else sign = 0;

  unsigned un = (unsigned) n;

  i = 0;
  do {
    s[i++] = un % 10 + '0';
  } while ((un /= 10) > 0);

  if(sign) {
    s[i++] = '-';
  }

  while(i < p-1){
    s[i++] = ' ';
  }

  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]){
  int i = 0;
  while(s[i] != '\0'){i++;}

  int mid = i/2;
  int j;
  --i;
  for(j = 0; j <= mid; j++) {
    char temp = s[i];
    s[i--] = s[j];
    s[j] = temp;
  }
}


void print_binary(int n){
  unsigned INT_SIZE = sizeof(n) * 8;
  signed WORKING_SIZE = INT_SIZE;
  char s1[INT_SIZE + 1];
  int workingN = n;

  s1[WORKING_SIZE--] = '\0';

  while(WORKING_SIZE >= 0) {
    s1[WORKING_SIZE--] = (1 & workingN) + '0';
    workingN = workingN >> 1;
  }

  printf("%s\n", s1);
}
