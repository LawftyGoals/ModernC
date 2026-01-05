#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define MAXLEN 1000
#define NKEYS (sizeof keytab / sizeof (struct key))
 
struct key {
  char *word;
  int count;
} keytab[] = {
  {"#define", 0}, {"#elif", 0}, {"#else", 0}, 
  {"#endif", 0}, {"#error", 0}, {"#if", 0}, {"#ifdef", 0}, 
  {"#ifndef", 0}, {"#include", 0}, {"#line", 0}, {"#pragma", 0}, 
  {"#undef", 0 }, {"_Alignas", 0}, {"_Alignof", 0}, 
  {"_Atomic", 0}, {"_Bool", 0}, {"_Complex", 0}, {"_Generic", 0}, 
  {"_Imaginary", 0}, {"_Noreturn", 0}, {"_Static_assert", 0}, 
  {"_Thread_local", 0}, {"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0}, 
  {"const", 0}, {"continue", 0}, {"default", 0}, {"do", 0}, 
  {"double", 0}, {"else", 0}, {"enum", 0}, {"extern", 0}, 
  {"float", 0}, {"for", 0}, {"goto", 0}, {"if", 0}, 
  {"inline", 0}, {"int", 0}, {"long", 0}, {"register", 0},  
  {"restrict", 0}, {"return", 0}, {"short", 0}, {"signed", 0}, 
  {"sizeof", 0}, {"static", 0}, {"struct", 0}, {"switch", 0}, 
  {"typedef", 0}, {"union", 0}, {"unsigned", 0}, {"void", 0}, 
  {"volatile", 0}, {"while", 0}
};


int binsearch(char*, struct key *, int);

int getword(char *, int);
char getch(void);
void ungetch(char);

int main(void){
  int n;
  char word[MAXWORD];

  while(getword(word, MAXWORD) != EOF){
    if(isalpha(word[0]) || word[0] == '#' || word[0] == '_')
      if((n = binsearch(word, keytab, NKEYS)) >= 0)
        keytab[n].count++;
  }
  for(n = 0; n < NKEYS; n++){
    if(keytab[n].count > 0)
      printf("%4d %s\n", keytab[n].count, keytab[n].word);
  }
  return 0;
}

int binsearch(char *word, struct key tab[], int n){
  int cond;
  size_t low, high, mid;

  low = 0;
  high = n - 1;
  while(low <= high){
    mid = (low + high) / 2;
    if((cond = strcmp(word, tab[mid].word)) < 0){
      high = mid - 1;
    }
    else if(cond > 0){
      low = mid + 1;
    }
    else return mid;
  }
  return -1;
}

int getword(char *word, int lim){
  char c;
  char *w = word;

  while(isspace(c = getch()));

  if(c == '/' && (c = getch()) == '/'){
    while((c = getch()) != '\0' && c != '\n');
  }

  if(c != EOF) *w++ = c;

  if(isalpha(c) || c == '_' || c == '#'){
    for( ; --lim > 0; w++){
      if(!isalnum(*w = getch())){
        ungetch(*w);
        break;
      }
    }
  } else {
    *w = '\0';
    return c;
  }
  /*

  if(!isalpha(c)){
    *w = '\0';
    return c;
  }

  for( ; --lim > 0; w++){
    if(!isalnum(*w = getch())){
      ungetch(*w);
      break;
    }
  }
  */
  *w = '\0';
  
  return word[0];
}

char charbuf[MAXLEN];
size_t charbufp = 0;

char getch(void){
  return charbufp > 0 ? charbuf[--charbufp] : getchar();
}

void ungetch(char c){
  if(charbufp >= MAXLEN) printf("NOT ENOUGH SPACE IN CHARBUFF");
  else charbuf[charbufp++] = c;
}




