#include <limits.h>
#include <stdio.h>
#include "custom-functions.h"

int main(void)
{

  int minmax = INT_MIN;
  unsigned maxmax = minmax;

  char s[50];
  itoa(minmax, s);

  int testalot = 14232;

  char s2[50];

  itob(testalot, s2, 2);

  printf("%u maxmax %d %minmax %s charsi %s testalot %d\n", maxmax, minmax, s, s2, testalot);

  char s3[] = "buddy, you ain't got what I need for sure. You just a chump, a regular two dime buffoon.";

  printf("idx of last 't': %d\n", strindex(s3, "two"));

  printf("atof: %f\n", custom_atof("      -123.4E-6"));

  //reverse_polish();

  char s4[] = "bots";
  recverse(s4);
  printf("%s\n", s4);

  char s5[4];
  itoa_rec(-10, s5);
  printf("%s\n", s5);

  int a = 6;
  int b = -7;
  
  swap(int, a, b);

  printf("a(6):%d b(-7):%d\n", a, b);

  return 0;
}
