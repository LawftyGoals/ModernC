#include <limits.h>
#include <stdio.h>
#include "custom-functions.h"



int main (void) {

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

  reverse_polish();

  return 0;
}
