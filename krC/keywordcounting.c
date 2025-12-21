

#define MAXBUFF 100


int getword(char *word, int lim);
char getch(void);
void ungetch(char);

int getword(char *word, int lim){

  char c, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c=getch()));

  if(c != EOF)
    *w++ = c;
  if(!isalpha(c)){
    *w = '\0';
    return c;
  }

  for( ; --lim > 0; w++){
    if(!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}

char chbuf[MAXBUF];
size_t chbufp = 0;

char getch(void){
  return chbufp > 0 ? chbuf[--chbufp] : getchar();
}

void ungetch(char c){
  if(chbufp >= MAXBUFA) printf("Too many characters for buffer chbuf");
  else chbuf[chbufp++] = c;
}

