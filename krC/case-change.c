#include <stdio.h>

#define MAXINPUT 1000

struct {
  unsigned is_upper : 1;
} flags;

char toLower(char c);
char toUpper(char c);

char getInput(char *c, int lim, char(char));

int main(int argc, char *argv[]) {
  char inputs[MAXINPUT], c;
  flags.is_upper = 0;

  if (argc > 1) {
    if (*argv[1] == 'u') {
      flags.is_upper = 1;
    }
  }

  while ((c = getInput(inputs, MAXINPUT,
                       (flags.is_upper ? toUpper : toLower))) != EOF) {
    printf("%s\n", inputs);
  }

  return 0;
}

char getInput(char *s, int lim, char caser(char c)) {
  char c;
  int i = 0;

  while (i < lim && ((c = getchar()) != EOF && c != '\n')) {
    *s++ = caser(c);
    i++;
  }
  *s = '\0';

  return c;
}

char toLower(char c) { return c >= 'A' && c <= 'Z' ? c + 32 : c; }

char toUpper(char c) { return c >= 'a' && c <= 'z' ? c - 32 : c; }
