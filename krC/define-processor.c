#include <ctype.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#define MAXWORDLIM 100

char getch(void);
void ungetch(char c);

char getword(char *word, uint16_t lim);

int main(void)
{
  char word[MAXWORDLIM];
  char lc = ' ';

  while ((lc = getword(word, MAXWORDLIM)) != EOF)
  {
    printf("%s\n", word);
  }

  return 0;
}

char getword(char *word, uint16_t lim)
{
  char c;
  char *localword = word;

  while (isspace(c = getch()) || (!isalpha(c) && c != '#' && c != '\n' && c != EOF))
    ;

  if (c == '\n')
  {
    *localword++ = '\n';
    *localword = '\0';
    return c;
  }
  if (c == EOF)
  {
    *localword = '\0';
    return c;
  }

  if (isalpha(c) || c == '#')
  {
    *localword++ = c;
    while ((*localword = getch()) == '_' || isalnum(*localword))
    {
      localword++;
    }
  }

  *localword = '\0';

  return c;
}

char charbuff[MAXWORDLIM];
uint16_t charidx = 0;

char getch(void)
{
  return charidx ? charbuff[--charidx] : getchar();
}

void ungetch(char c)
{
  if (charidx >= MAXWORDLIM)
    printf("failed to add to buffer: buffer size exceeded");
  else
    charbuff[charidx++] = c;
}
