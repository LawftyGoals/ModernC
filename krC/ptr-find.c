#include <stdio.h>
#include <string.h>

#include "custom-functions.c"

#define MAXLINE 1000

int main(int argc, char *argv[]) {

  char line[MAXLINE];
  //char c;
  
  int found = 0;
  //int lineno = 0;
  bool except = false, number = false;

  printf("e: %s n: %s\n", except ? "true": "false", number ? "true": "false");
  if (argc != 2) printf("Usage: find pattern\n");
  else {
    while (getline(line, MAXLINE) > 0) {
      if(strstr(line, argv[1]) != NULL) {
        printf("%s", line);
        found++;
      }
    }
  }
  return found;
}


