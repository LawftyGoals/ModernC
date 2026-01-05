#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXCHARBUFF 1000
#define MAXINPLIM 1000
#define MAXWORD 100

char getch(void);
void ungetch(char);
int getword(char *s, int lim);
char *mallocword(char *);
int binsearch(char**, size_t, char*);
char *binsearchp(char**, size_t, char*);

struct variablekey { char *word; size_t count; struct variablekey *left; struct variablekey *right;};


size_t LIST_LEN = 7;
char *DATA_TYPES[] = { "bool", "char", "double", "float", "int", "long", "short" };

int main(void) {
  //char *words[MAXINPLIM];
  char *variables[MAXINPLIM];
  //char word[MAXINPLIM];
  struct variablkey rootkey;
  char fl;
  int i = 0;


  struct variablekey rootnode;

  char *wordli;

  while((fl = getword(word, MAXINPLIM)) != EOF){
    //printf("%d\n", binsearch(DATA_TYPES, LIST_LEN-1, word));
    if((wordli = binsearchp(DATA_TYPES, LIST_LEN-1, word)) != NULL){
      printf("%s\n", wordli);
      while((fl = getword(word, MAXINPLIM)) != EOF && (wordli = binsearchp(DATA_TYPES, LIST_LEN-1, word)) != NULL);
      
    }
    i++;
  }

  return 0;
}

struct variablekey *addNode(char *s, struct variablekey *p){
  int cond;
  if(p == NULL){
    p = keyalloc();
    p->word = mallocword(s);
    p->count = 1;
    p->left = p-right = NULL;
  } else if ((cond = strcmp(s, p->word)) == 0) {
    p-count++;
  } else if (cond < 0) {
    p->left = addtree(p->left, s);
  } else {
    p->right = addtree(p->right, s);
  }
  return p;
}

char* mallocword(char *word){
  char *pword = (char *) malloc(strlen(word) + 1);

  if(pword != NULL)
    strcpy(pword, word);
  
  return pword;
}

char *binsearchp(char* list[], size_t listlen, char *word){
  char **start = list;
  char **end = list + listlen;
  char **mid;
  int cond;

  while(start <= end){
    mid = start + (end - start) / 2;
    if((cond = strcmp(word, *mid)) < 0)
      end = mid;
    else if(cond > 0)
      start = mid + 1;
    else
      return *mid;
  }

  return NULL;
}


//listlen = length of list - 1
int binsearch(char *list[], size_t listlen, char *word){
  size_t start = 0;
  size_t end = listlen;
  size_t mid;
  int cond;

  while(start <= end){
    mid = (start + end) / 2;
    if((cond = strcmp(word, list[mid])) < 0){
      end = mid - 1;
    } else if(cond > 0) {
      start = mid + 1;
    } else
      return mid;
  }

  return -1;
}
 




char charbuf[MAXCHARBUFF];
size_t charbufp = 0;

char getch(void){
  return charbufp > 0 ? charbuf[--charbufp] : getchar();
}

void ungetch(char c){
  if(charbufp >= MAXCHARBUFF) printf("getch char buffer limit reached");
  else charbuf[charbufp++] = c;
}


int getword(char *s, int lim){
  char c;
  
  char *sp = s;

  while(isspace(c = getch()))
    ;

  if(c != EOF)
    *sp++ = c;
  if(!isalpha(c) && c != '_' && c != '#') {
    *sp = '\0';
    return c;
  }


  for( ; --lim > 0; sp++) {
    if((*sp = getch()) == '_' && isalpha(c = getch()))
      ungetch(c);
    else if(!isalnum(*sp)) {
      ungetch(*sp);
      break;
    }
  }
  *sp = '\0';

  return s[0];
}

