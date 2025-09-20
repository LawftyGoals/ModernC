#include <stdio.h>
#include <float.h>
enum corvids { chough, raven, magpie, jay, corvid_num };

# define CORVID_NAME \
  (constexpr char[8][corvid_num]) { \
    [chough] = "chough", \
    [raven] = "raven", \
    [magpie] = "magpie", \
    [jay] = "jay", \
  }

enum noncovrids { pidgeon, stork, falcon, noncorvid_num }; 
# define NONCORVID_NAME \
  (char const*const[corvid_num]) { \
    [pidgeon] = "pidgeon", \
    [stork] = "stork", \
    [falcon] = "falcon", \
}


int main() {


  printf("%d\n", chough);

  for(short i = 0; i < noncorvid_num; ++i){
    printf("%s\n", NONCORVID_NAME[i]);
        }
  printf("%f\n", DBL_MAX); 

  unsigned A = 240;
  unsigned B = 287;
  unsigned short V = 0xFFFF;
  
  unsigned short As = 240;
  unsigned short Bs = 287;
  
  printf("division:%d bitdivision: %d\n", A&(~B), A-(A&B)); 
  /* ~ is not, that means not B union A.*/
  printf("V+1: %hu\n", V + 1);

  printf("A^B: %i, A-A&B+-B-A&B: %i, A+B-2*A&B: %i\n", A^B, (A-(A&B)) + (B-(A&B)), A+B-2*(A&B)); 
  printf("A|B: %i, A+B-(A&B): %i\n", A|B, A+B-(A&B));
  printf("~Bs: %hu, V-Bs: %hu, ~As: %hu, ~B:%i\n", ~Bs, V-B, ~As, ~B);
  printf("-Bs: %hu, ~Bs+1: %hu, V: %hu\n", -Bs,  ~Bs+1, V); 

  return 0;
}
