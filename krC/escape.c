
#include <stdio.h>

void reverse_escape(char line[], char target[]);

void escape(char line[], char target[]);

int main() {

  char test[] = "This \t is a test\nof great importance";
  char target[200];
  char target2[200];

  escape(test, target);
  reverse_escape(target, target2);

  printf("%s\n%s\n", target, target2);

  return 0;
}



void escape(char s[], char t[]) {

  int i;
  int j = 0;

  for(i = 0; s[i] != '\0'; i++) {

    switch(s[i]) {
      case '\t':
        t[i + j] = '\\';
        ++j;
        t[i + j] = 't';
        break;
      case '\n':
        t[i + j] = '\\';
        ++j;
        t[i + j] = 'n';
        break;
      default:
        t[i + j] = s[i];
        break;
    }

  }

  t[i + j] = '\0';

}

void reverse_escape(char s[], char t[]) {
  int i;
  signed j = 0;

  for( i = 0; s[i + j] != '\0'; i++) {
    if(s[i + j] == '\\'){
      ++j;
      switch(s[i + j]) {
        case 'n':
          t[i] = '\n';
          break;
        case 't':
          t[i] = '\t';
          break;
        default:
          --j;
          break;
      } 
    } else {
        t[i] = s[i + j];
    }
  }
  t[i] = '\0';
}





