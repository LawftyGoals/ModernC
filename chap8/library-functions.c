#if -1 & 3 != 3
# error "This compiler does not use Two's complement"
#endif
#define TWOS_COMPLEMENT 1

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdckdint.h>

double my_strtod(char *s){
  double beforePeriod = 0.0;
  double afterPeriod = 0.0;
  unsigned idx = 0;
  double sign = 1;
  bool added = false;
  bool period = false;
  while(s[idx] != '\0'){
    if(s[idx] == ' ') continue;
    if(s[idx] == '-' && !added) {
      sign *= -1;
    } else if (s[idx] == '.'){
      period = true;
      break;
    } else if(s[idx] < 48 || s[idx] > 57) { 
      break;
    } else {
      added = true;
      beforePeriod = beforePeriod*10 + (s[idx]-'0');
    }
    ++idx;
  }
  if(period){
    int ap = 1;
    while(s[idx] != '\0'){
      if( s[idx] > 47 && s[idx] < 58) {
        afterPeriod = afterPeriod + (s[idx] - '0')*pow(0.1, ap);
        ++ap;
      }
      ++idx;
    }
  }
  printf("%lu\n", sizeof(s));
  printf("%f\n", beforePeriod + afterPeriod);
  return beforePeriod + afterPeriod;
}

void test_int_arith(){
/*stdlib*/
  auto res = div(13, 5);
  printf("abs %d, div %d rem %d\n", abs(-10), res.quot, res.rem); 

  /*stdckdint*/
  unsigned overflow = 0;              //limits.h
  bool overflowed = ckd_add(&overflow, UINT_MAX, UINT_MAX);
  printf("Overflow flag %s, result %x\n", (overflowed ? "true": "false"), overflow); 
}

int manual_puts(char const s[static 1]) {
  for(size_t i = 0; s[i]; ++i) {
    if(putchar(s[i]) == EOF) return EOF;
  }
  if(putchar('\n') == EOF) return EOF;
  return 0;
}

int stdout_puts_manually(char const s[static 1]) {
  if(fputs(s,    stdout) == EOF) return EOF;
  if(fputc('\n', stdout) == EOF) return EOF;
  return 0;
}

int main(int argc, char* argv[argc+1]) {
  printf("twos %d\n", TWOS_COMPLEMENT);
  my_strtod("-10523.0203");
  printf("%s, %d\n", argv[0], argc);
  
  test_int_arith();
  manual_puts("testing this");

  stdout_puts_manually("working on this");
  
  FILE* logfile = fopen("bob.txt", "a");
  if(!logfile){
    perror("fopen failed");
    return EXIT_FAILURE;
  }
  fputs("feeling fine today\n", logfile);

  if(!freopen("mylog.txt", "a", stdout)){
    perror("freopen failed");
    return EXIT_FAILURE;
  }
  puts("feelings are fine today");

  return EXIT_SUCCESS;
}

