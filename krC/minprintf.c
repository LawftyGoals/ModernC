#include <stdarg.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

#define LOCALFMT 101

void minprintf(char *, ...);

int main(void){
  printf("%5d\n", 10);
  minprintf("%5d\n", 10);
  minprintf("%s", "fudgepacket");
  return 0;
}

void minprintf(char *fmt, ...){
  va_list ap;
  char *p, *sval, *lf;
  int ival;
  double dval;
  char localFmt[LOCALFMT];
  uint16_t i;

  lf = localFmt;

  va_start(ap, fmt);
  for (p = fmt; *p; p++){
    if(*p != '%'){
      putchar(*p);
      continue;
    }
    i = 0;
    localFmt[i++] = '%';
    while(*(p+1) && !isalpha(*(p+1)))
      localFmt[i++] = *++p;
    localFmt[i++] = *(p+1);
    localFmt[i] = '\0';
    switch(*++p){
      case 'd':
        ival = va_arg(ap, int);
        printf(localFmt, ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf(localFmt, dval);
        break;
      case 's':
        sval = va_arg(ap, char *);
        printf(localFmt, sval);
        break;
      default:
        printf("%s", lf);
        break;
    }
  }
  va_end(ap);
}



