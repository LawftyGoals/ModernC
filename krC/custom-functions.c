#include "custom-functions.h"
#include <stdio.h>

void itoa(int n, char s[]){
  int i, sign;
  unsigned un = (unsigned) n;
  if((sign=n) < 0) n = -n;

  i = 0;
  do {
    s[i++] = un % 10 + '0';
  } while((un /= 10) > 0);
  
  if(sign < 0) s[i++] = '-';
  s[i] = '\0';
  reverse(s);
 
}

void itob(int n, char s[], int b) {
  int i, sign;
  unsigned un = (unsigned) n;
  sign = n < 0 ? 1 : 0;

  i = 0;
  do {
    int j = un % b;
    s[i++] = (j < 10) ? j + '0' : j - 10 + 'a';
  } while ((un /= 10) > 0);

  if(sign) {
    s[i++] = 0;
  }

  s[i] = '\0';
  reverse(s);
}


void reverse(char s[]) {
  int len = 0;
  while(s[len] != '\0') len++;

  int half = len/2;
  len -= 1;
  int i = 0;
  char temp;

  while(i <= half) {
    temp = s[len - i];
    s[len - i] = s[i];
    s[i++] = temp;
  }
}


// E.4-1

int strindex(char s[], char t[]) {
  int i = 0;
  int j, k;
  int ret = -1;
  while(s[i++] != '\0') {
    if(s[i] == t[0]){
      for(j = i, k = 0;s[j] != '\0' && t[k] != '\0'; j++, k++);
      if(k > 0 && t[k] == '\0') ret = i;
    }
  }
  return ret;
}

