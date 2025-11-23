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
/*
  int t1;

  getint(&t1);

  printf("%d\n", t1);
*/
  double t2;

  getFloat(&t2);

  printf("%f\n", t2);

  char strcat1[11] = "teddy";
  char strcat2[] = "bear";

  new_strcat(strcat1, strcat2);

  printf("new_strcat: %s\n", strcat1);

  char strncpy1[] = "boston";
  char strncpy2[7];

  new_strncpy(strncpy1, strncpy2, 3);

  printf("new_Strncpy: %s\n", strncpy2 );

  char strncat3[] = "talcum";
  char strncat4[] = "bot";

  new_strncat(strncat3, strncat4, 3);

  printf("new_strncat: %s\n", strncat3);

  int year = 2025;
  int month = 11;
  int day = 3;
  int yearday = 360;
  int pmonth = 0;
  int pday = 0;

  int doy = day_of_year(year, month, day);
  month_day(year, yearday, &pmonth, &pday);

  printf("day of year, 3.11.25: %d, month day 360.25: %d.%d\n", doy, pmonth, pday);


  return 0;
}
