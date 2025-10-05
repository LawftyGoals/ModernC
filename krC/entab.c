#include <stdio.h>

#define TABWIDTH 8

int main() {
  char c;
  int pos;
  int nb = 0;
  int nt = 0;
  for (pos = 0; (c = getchar()) != EOF; ++pos){
    if(c == ' ') {
      ++nb;
    } else {
      if(nb > 0){
        if(pos % TABWIDTH){
          for(; nb > 0; --nb){
            putchar(' ');
          }
        } else {
          putchar('\t');
          nb = 0;
        }
      }
      if(c == '\t') {
        pos += (TABWIDTH - (pos % TABWIDTH)) - 1;
      }
      putchar(c);
    }
  }


  return 0;
}

