#include <stdio.h>
#include <math.h>


int main(){
  char hexy[] = "0xFFAA";

  int sum = 0;
  signed int i = 5;
  while(i >= 0 && hexy[i] != 'x') {
    int conv = 0;
    if(hexy[i] > '9'){
      conv = hexy[i] - 55;
      printf("%d", sum);
    } else {
      conv = hexy[i] - '0';
    }
    
    sum += conv * pow(16, 5-i);


    --i;
  }

  printf("\n%d\n", sum);


  return 0;
}


