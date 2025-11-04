#include <stdio.h>

char lower(char c);
void toLower(char line[]);

int main() {

  char line[] = "THIS IS A BIG MESSAGE";
  
  toLower(line);

  printf("%s\n", line); 

  return 0;
}

char lower(char c){
    return c > '@' && c < '[' ? c += 'a' - 'A' : c;

}

void toLower(char s[]) {
  unsigned i;
  for(i = 0; s[i] != '\0'; ++i) {
    s[i] = lower(s[i]);
  }
}
