#include <ctype.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#define MAXWORDLIM 100
#define HASHLIM 101

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

struct nlist *hashtable[HASHLIM];

unsigned hash(char *name);
struct nlist *lookup(char *name);
struct nlist *addtotable(char *name, char *defn);



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


unsigned hash(char *name){
  unsigned total = 0;
  for( ; *name != '\0'; name++){
    total = name + 31 * total;
  }
  return total % HASHLIM;
}

struct nlist *lookup(char *name){
  unsigned hashval = hash(name);

  struct nlist *np;

  for(np = hashtab[hashval]; np != NULL; np = np->next){
    if(strcmp(np->name, name) == 0)
      return np;
  }

  retrurn NULL;
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
