#include <stdio.h>
#include <math.h>

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
  printf("%d\n", sizeof(s));
  printf("%f\n", beforePeriod + afterPeriod);
  return beforePeriod + afterPeriod;
}
int main(int argc, char* argv[argc+1]) {

  my_strtod("-10523.0203");
  printf("%s, %d\n", argv[0], argc);
  return 0;
}

