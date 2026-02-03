#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>


#define LOCALFMT 101

void minscanf(char *fmt, ...);

int main(void){
  int dec = 0;
  scanf("%d", &dec);
  printf("%d\n", dec);
  printf("%s\n", '\0' ? "tru" : "false");

  minscanf("%d", &dec);
  printf("%d\n", dec);
  return 0;
}



void minscanf(char *fmt, ...){
  va_list ap;
  int *ival;
  float *fval;
  char *sval;
  char *p = fmt;
  int i = 0;

  char localfmt[LOCALFMT];
  
  va_start(ap,fmt);

  for(; *p; p++){
    if(*p != '%'){
      localfmt[i++] = *p;
    } else {
      localfmt[i++] = '%';
      while(*(p+1) && !isalpha(*(p+1)))
        localfmt[i++] = *++p;
      localfmt[i++] = *(p+1);
      localfmt[i] = '\0';
      switch(*++p){
        case 'd':
          ival = va_arg(ap, int *);
          scanf(localfmt, ival);
          break;
        case 'f':
          fval = va_arg(ap, float *);
          scanf(localfmt, fval);
          break;
        case 's':
          sval = va_arg(ap, char *);
          scanf(localfmt, sval);
          break;
        default:
          scanf(localfmt);
          break;
      }
      i=0;
    }
  }
}
  


