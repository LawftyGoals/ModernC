#include <stdio.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
int getline(char[], int);

char line[MAXOP]; 
size_t lineIndex = 0;

int getop(char s[]){
  int sizedline, i;
  char c;
  if(line[lineIndex] == '\0'){
    if((sizedline = getline(line, MAXOP)) < 1) return EOF;
    else lineIndex = 0;
  }

  while((s[0] = c = line[lineIndex++]) == ' ' || c == '\t');

  s[1] = '\0';
  bool isDigit = isdigit(c);
  if(!isDigit && c != '.') return c;
  i = 0;
  
  if(isDigit) while(isdigit(s[++i] = c = line[lineIndex++]));


  if(c == '.') while(isdigit(s[++i] = c = line[lineIndex++]));

  s[i] = '\0';
  lineIndex--;

  return NUMBER;
}

int main(void) {
  char s1[MAXOP];
  char t = getop(s1);

  printf("%s %c\n", s1, t);


  return 0;
}

int getline(char s[], int lim) {
  char c;
  int i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++){
    s[i] = c;
  }
  if(c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  
  return i;
}
