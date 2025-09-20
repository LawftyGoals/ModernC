#include <stdio.h>
#include <string.h>


void swap_double(double a[static 2]) {
  /* the array passed in is worked on, not copied*/
  auto tmp = a[0];
  a[0] = a[1];
  a[1] = tmp;

}

int custom_strcmp(char s[], int s_len, char c[], int c_len){

  return s_len > c_len ? memcmp(s, c, c_len) : memcmp(s, c, s_len);
}




int main( int argc, char* argv[argc+1] ) {
  double A[2] = {1.0, 2.0, };
  swap_double(A);

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
  return 0;
}
