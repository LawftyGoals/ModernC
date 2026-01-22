#include <ctype.h>
#include <string.h>
#include <stdlib.h>
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

char *stralloc(char *s);

char getch(void);
void ungetch(char c);

char getword(char *word, uint16_t lim);
void printlist(void);

int main(void)
{
  char word[MAXWORDLIM];
  char lc = ' ';

  char var[MAXWORDLIM];
  char defn[MAXWORDLIM];
  struct nlist *found;

  while ((lc = getword(word, MAXWORDLIM)) != EOF)
  {
    if(lc == '#' && strcmp(word, "#define") == 0){
      getword(var, MAXWORDLIM);
      getword(defn, MAXWORDLIM);
      addtotable(var, defn);
    } else if((found = lookup(word)) != NULL)
      strcpy(word, found->defn);
    printf("%s\n", word);
  }

  printlist();

  return 0;
}
void printlist(){
   struct nlist *target;
   for(uint16_t i = 0; i < HASHLIM; i++){
     if((target = hashtable[i]) != NULL){
        printf("%s - %s\n", target->name, target->defn);
     while(target->next != NULL){
        printf("%s - %s\n", target->next->name, target->next->defn);
        target = target->next;
      }
    }
  }
}

struct nlist *addtotable(char *name, char *defn){
  unsigned hashval = hash(name);
  struct nlist *np = lookup(name);
  if(np == NULL){
    np = (struct nlist *)malloc(sizeof(*np));
    if(np == NULL || (np->name = stralloc(name)) == NULL)
      return NULL;
    np->next = hashtable[hashval];
    hashtable[hashval] = np;
  } else {
    free(np->defn);
  }
  if((np->defn = stralloc(defn)) == NULL) {
      return NULL;
  }

  return np;
}




unsigned hash(char *name){
  unsigned total = 0;
  for( ; *name != '\0'; name++){
    total = *name + 31 * total;
  }
  return total % HASHLIM;
}

struct nlist *lookup(char *name){
  unsigned hashval = hash(name);

  struct nlist *np;

  for(np = hashtable[hashval]; np != NULL; np = np->next){
    if(strcmp(np->name, name) == 0)
      return np;
  }

  return NULL;
}

char *stralloc(char *s){
  char *str = (char *)malloc(strlen(s) + 1);
  if(str != NULL)
    strcpy(str, s);
  return str;
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
