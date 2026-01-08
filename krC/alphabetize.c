#include <stddef.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXCHARBUFF 1000
#define MAXINPLIM 1000
#define MAXWORD 100
#define DEFAULTGROUPER 2

char getch(void);
void ungetch(char);
int getword(char *s, int lim);
char *mallocword(char *);
int binsearch(char **, size_t, char *);
char *binsearchp(char **, size_t, char *);

struct variablekey *keymalloc(void);
struct variablekey *addnode(char *, struct variablekey *);

void printtree(struct variablekey *);
void printvertical(struct variablekey *);

struct variablekey
{
  char *word;
  size_t count;
  struct variablekey *left;
  struct variablekey *right;
  struct variablekey *up;
  struct variablekey *down;
};

uint16_t grouper = DEFAULTGROUPER;

size_t LIST_LEN = 7;
char *DATA_TYPES[] = {"bool", "char", "double", "float", "int", "long", "short"};

int main(int argc, char *argv[])
{
  // char *words[MAXINPLIM];
  // char *variables[MAXINPLIM];
  char word[MAXINPLIM];
  struct variablekey *rootkey = NULL;
  char fl;
  int i = 0;

  char *wordli;
  bool isvariable = false;

  if(argc > 1 && isdigit(*argv[1])){
    printf("%s\n", argv[1]);
    grouper = atoi(argv[1]);
  }

  while ((fl = getword(word, MAXINPLIM)) != EOF)
  {
    // printf("%d\n", binsearch(DATA_TYPES, LIST_LEN-1, word));
    if ((wordli = binsearchp(DATA_TYPES, LIST_LEN - 1, word)) != NULL)
    {
      isvariable = true;
    }
    if (isvariable && wordli == NULL)
    {
      rootkey = addnode(word, rootkey);
      isvariable = false;
    }
    i++;
  }
  printtree(rootkey);

  return 0;
}

void printtree(struct variablekey *rootkey)
{
  if (rootkey != NULL)
  {
    printtree(rootkey->left);
    if(rootkey->count >= grouper)printvertical(rootkey);
    printtree(rootkey->right);
  }
}

void printvertical(struct variablekey *rootkey){
  if(rootkey != NULL){
    printvertical(rootkey->down);
    printf("%s\n", rootkey->word);
    printvertical(rootkey->up);
  }
}
    

struct variablekey *addnode(char *s, struct variablekey *p)
{
  int cond;
  int vertcond;
  if (p == NULL)
  {
    p = keymalloc();
    p->word = mallocword(s);
    p->count = 1;
    p->up = p->down = p->left = p->right = NULL;
  }
  else if ((cond = strncmp(s, p->word, grouper)) == 0)
  {
    if((vertcond = strcmp(s, p->word)) != 0){
      printf("add - %s\n", s);

      if(vertcond > 0) {
        p->up = addnode(s, p->up);
      } else if (vertcond < 0) {
        p->down = addnode(s, p->down);
      }

      p->count++;
    }
  }
  else if (cond < 0)
  {
    p->left = addnode(s, p->left);
  }
  else
  {
    p->right = addnode(s, p->right);
  }
  return p;
}

struct variablekey *keymalloc()
{
  return (struct variablekey *)malloc(sizeof(struct variablekey));
}

char *mallocword(char *word)
{
  char *pword = (char *)malloc(strlen(word) + 1);

  if (pword != NULL)
    strcpy(pword, word);

  return pword;
}

char *binsearchp(char *list[], size_t listlen, char *word)
{
  char **start = list;
  char **end = list + listlen;
  char **mid;
  int cond;

  while (start < end)
  {
    mid = start + (end - start) / 2;
    if ((cond = strcmp(word, *mid)) < 0)
      end = mid;
    else if (cond > 0)
      start = mid + 1;
    else
      return *mid;
  }

  return NULL;
}

// listlen = length of list - 1
int binsearch(char *list[], size_t listlen, char *word)
{
  size_t start = 0;
  size_t end = listlen;
  size_t mid;
  int cond;

  while (start <= end)
  {
    mid = (start + end) / 2;
    if ((cond = strcmp(word, list[mid])) < 0)
    {
      end = mid - 1;
    }
    else if (cond > 0)
    {
      start = mid + 1;
    }
    else
      return mid;
  }

  return -1;
}

char charbuf[MAXCHARBUFF];
size_t charbufp = 0;

char getch(void)
{
  return charbufp > 0 ? charbuf[--charbufp] : getchar();
}

void ungetch(char c)
{
  if (charbufp >= MAXCHARBUFF)
    printf("getch char buffer limit reached");
  else
    charbuf[charbufp++] = c;
}

int getword(char *s, int lim)
{
  char c;

  char *sp = s;

  while (isspace(c = getch()))
    ;

  if (c != EOF)
    *sp++ = c;
  if (!isalpha(c) && c != '_' && c != '#')
  {
    *sp = '\0';
    return c;
  }

  for (; --lim > 0; sp++)
  {
    if ((*sp = getch()) == '_' && isalpha(c = getch()))
      ungetch(c);
    else if (!isalnum(*sp))
    {
      ungetch(*sp);
      break;
    }
  }
  *sp = '\0';

  return s[0];
}
