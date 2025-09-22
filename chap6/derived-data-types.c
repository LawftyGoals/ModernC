
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <time.h>

void swap_double(double a[static 2]) {
  /* the array passed in is worked on, not copied*/
  auto tmp = a[0];
  a[0] = a[1];
  a[1] = tmp;

}

int custom_strcmp(char s[], int s_len, char c[], int c_len){

  return s_len > c_len ? memcmp(s, c, c_len) : memcmp(s, c, s_len);
}

struct timespec timespec_diff(struct timespec t_1, struct timespec t_2){
  struct timespec t = { .tv_sec = t_2.tv_sec - t_1.tv_sec, .tv_nsec = t_2.tv_nsec - t_1.tv_nsec };

  return t;
}




int main( int argc, char* argv[argc+1] ) {
  double A[2] = {1.0, 2.0, };
  swap_double(A);


  struct timespec t1 = { .tv_sec = 100, .tv_nsec = 1000, };

  clock_gettime(CLOCK_REALTIME, &t1);


  printf("A[0]: %g, A[1]: %g\n", A[0], A[1]);

  char jay0[] = "jay";
  char jay1[] = {"jay"};
  char jay2[] = {'j','a','y',0};  
  char jay3[4] = {'j', 'a', 'y'}; 
  char jay4[3] = {'j', 'a', 'y'};/*will return jayjay*/
  char jay5[3] = {"jay"}; /*will return jayjayjay*/

  printf("%s\n%s\n%s\n%s\n%s\n%s\n", jay0, jay1, jay2, jay3, jay4, jay5); 



  size_t const len = strlen(argv[0]);

  char name[len+1] = {};
  
  memcpy(name, argv[0], len);
  if(!strcmp(name,argv[0])) {
    printf("program name \"%s\" successfully copied\n", name);
  } else {
    printf("copying %s lead to different string %s\n", argv[0], name);
  }

  char exr[] = "exr1 test is test";
  char exr1[] = "exr1 test is not test";
  printf("%p\n", memchr(exr, 'e', 4));
  printf("len through calc: %ld\n", (sizeof exr)/(sizeof exr[0]));
  printf("strcmp: %d\n", strcmp(exr, exr1));


  printf("%d\n", custom_strcmp(exr, (sizeof exr)/(sizeof exr[0]), exr1, (sizeof exr1)/ (sizeof exr1[0])));
    
  struct timespec t2 = { .tv_sec = 200, .tv_nsec = 6000, };

  clock_gettime(CLOCK_REALTIME, &t2);

  struct timespec td = timespec_diff(t1, t2);

  printf("sec: %lu, nsec: %lu\n", td.tv_sec, td.tv_nsec);

  struct rass1 {
    unsigned char thechar;
    unsigned theunsigned;
    unsigned long long thelonglong;
  };

  struct rass2 {
    unsigned char thechar;
    unsigned long long thelonglong;
    unsigned theunsigned;
  };


  struct rass3 {
    unsigned theunsigned;
    unsigned char thechar;
    unsigned long long thelonglong;
  };


  struct rass4 {
    unsigned theunsigned;
    unsigned long long thelonglong;
    unsigned char thechar;
  };


  struct rass5 {
    unsigned long long thelonglong;
    unsigned char thechar;
    unsigned theunsigned;
  };
  typedef struct rass6 rass6;
  struct rass6 {
    unsigned long long thelonglong;
    unsigned theunsigned;
    unsigned char thechar;
  };
  struct rass1 r1 = {.thechar = 0, .theunsigned = 0, .thelonglong = 0};
  struct rass2 r2 = {.thechar = 0, .theunsigned = 0, .thelonglong = 0};
  struct rass3 r3 = {.thechar = 0, .theunsigned = 0, .thelonglong = 0};
  struct rass4 r4 = {.thechar = 0, .theunsigned = 0, .thelonglong = 0};
  struct rass5 r5 = {.thechar = 0, .theunsigned = 0, .thelonglong = 0};
  rass6 r6 = {.thechar = 0, .theunsigned = 0, .thelonglong = 0};
  
  printf("rass1: %lu\n, rass2: %lu\n, rass3: %lu\n, rass4: %lu\n, rass5: %lu\n, rass6: %lu\n", sizeof(r1), sizeof(r2), sizeof(r3), sizeof(r4), sizeof(r5), sizeof(r6)); 

  return 0;
}
