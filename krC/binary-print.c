

#include <stdio.h>

void binary_print(size_t val, char result[], size_t result_size);

void binary_print(size_t val, char result[], size_t result_size){
  size_t bits = sizeof(val)*8;
  char reverse[bits];
  size_t size;
  size_t locval = val;


  if(val == 0) {
    size_t i = 0;
    while(i < bits) {
      result[i] = 0;
      ++i;
    }
    result[i] = '\0';
  }
  else {
    size_t i = 0;
    while(i < bits) {
      reverse[i] = locval & 1 ? '1' : '0';
      locval = locval >> 1;
      ++i;
    }
    size_t j;
    for(j = i; j > 0; --j) {
      result[i-j] = reverse[j-1];
    }
    result[i] = '\0';
  }
}


int main() {

  char s[200];
  
  binary_print(50501230201031501, s, 200);

  printf("%s\n", s);

  return 0;
}
    
  


