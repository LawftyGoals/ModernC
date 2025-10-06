#include <stdio.h>
#define MAXLINE 1000

enum looping {NO, YES};
enum looping okloop = YES;



int main() {
  int i = 0;
  char c;
  char s[MAXLINE];
  int lim = MAXLINE;
  
  int tall = 1234;
  int* tallptr = &tall;

  printf("tallptr: %d\n", 10*(*tallptr));


  /*for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)*/
  while (okloop == YES) {
    if(i >= lim-1){
      okloop = NO;
    } else if((c = getchar()) == '\n') {
      okloop = NO;
    } else if (c == EOF) {
      okloop = NO;
    } else {
      s[i] = c;
      ++i;
    }
  }

  return 0;
}
