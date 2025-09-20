#include <stdio.h>
#include <stdlib.h>

enum corvids: short {cough, raven, magpie, jay, corvid_num};
#define CORVID_NAME /**/ \
(char const*const [corvid_num]) { \
  [cough] = "cough", \
  [raven] = "raven", \
  [magpie] = "magpie", \
  [jay] = "jay", \
}

int main() {
  

  signed long long sll = -1;
  signed long long sll2 = 9223372036854775807;

  printf("%lld\n%lld\n", sll, sll2+1);


  unsigned int ui = 0xffff'ffff;
  unsigned int hui = 0x8000'0000;
  unsigned int mhui = -0x8000'0000;
  printf("%u ui, %u hui, %u mhui\n", ui, hui, mhui);

  enum bib: short {test1, test2, test3, test4};
  char const*const test[] = {[test1]="test", [test2]="test2", [test3]="test3"};
  /*test[2] = "test4"; will not run because of the const qualifier in line above*/
  for(short i = 0; i < test4; ++i) {
                                  printf("%s\n", test[i]);
  }

  typedef enum bib biib;
  biib tiib = test1;
  biib tib = 6;
  printf("biib1 %hu, tib2=%hu\n", tiib, tib);
  
  for( unsigned i = 0; i < corvid_num; ++i) {
    printf("Corvid %u is the %s\n", i, CORVID_NAME[i]);
  }
  return EXIT_SUCCESS; 

}

