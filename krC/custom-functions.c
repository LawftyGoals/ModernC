#include "custom-functions.h"
#include <stdio.h>
#include <ctype.h>

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

double atof(char s[]){
  double val, power;
  int i, sign;
  for(i = 0; isspace(s[i]); i++) ;
  sign = (s[i] == '-') ? -1 : 1;
  
  if(s[i] == '+' || s[i] == '-') {
    i++;
  }
  
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if(s[i] == '.') {
    i++;
  }

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }


  val =  sign * val / power;
  
  if(s[i] == 'e' || s[i] == 'E') {
    i++;
    int esign = s[i] == '-' ? 1 : 0;
    if(s[i] == '-' || s[i] == '+') {
      i++;
    }

    int exp = 0;
    while(isdigit(s[i])) {
      exp = (exp * 10) + (s[i] - '0');
      i++;
    }

    if(esign){
      while (exp-- > 0){
        val /= 10;
      }
    }
    else {
      while(exp-- > 0) {
        val *= 10;
      }
    }
  }


  return val;
}

