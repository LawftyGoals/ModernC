#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};
enum {YES, NO};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int prevtoken;

void errormsg(char *);
int getnexttoken(void);

void error(char *);
void dclpath(void);
void undclpath(void);


int main(int argc, char *argv[]){

  if(argc == 1)
    dclpath();
  else if(argc == 2 && *argv[1] == '-'){
    char nextrule = *++argv[1];
    if(nextrule == 'u')
      undclpath();
    if(nextrule == 'd')
      dclpath();
  } else
    error("unrecognized arguments on initialization");


  return 0;
}


void dclpath(void){
  while(gettoken() != EOF){
    strcpy(datatype, token);
    out[0] = '\0';
    dcl();
    if(tokentype != '\n')
      printf("syntax error\n");
    printf("%s: %s %s\n", name, out, datatype);
  }
}

void undclpath(void){
  int type;
  char temp[2000];
  int nexttype;

  while(gettoken() != EOF){
    strcpy(out, token);
    while((type = gettoken()) != '\n'){
      if(type == PARENS || type == BRACKETS)
        strcat(out, token);
      else if(type == '*'){
        if((nexttype = getnexttoken()) == PARENS || nexttype == BRACKETS){
          sprintf(temp, "(*%s)", out);
        }
        else
          sprintf(temp, "*%s", out);
        strcpy(out, temp);
      } else if(type == NAME){
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      } else
        printf("invalid input at %s\n", token);
    }
    printf("%s\n", out);
  }
}

int getch(void);
void ungetch(int);

char buf[MAXTOKEN];
int bufp = 0;

int getch(void){
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if (bufp >= MAXTOKEN)
    error("ungetch: more characters than allocated buffer");
  else
    buf[bufp++] = c;
}


int gettoken(void){
  int c;
  char *p = token;

  if(prevtoken == YES){
    prevtoken = NO;
    return tokentype;
  }

  while ((c = getch()) == ' ' || c == '\t');
  
  if(c == '(') {
    if((c = getch()) == ')'){
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if(c == '['){
    for(*p++ = c; (*p++ = getch()) != ']'; );

    *p = '\0';
    return tokentype = BRACKETS;
  } else if( isalpha(c)){
    for(*p++ = c; isalnum(c = getch()); )
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else
    return tokentype = c;
}

int getnexttoken(void){
  int type;

  type = gettoken();
  prevtoken = YES;
  return type;
}

void dcl(void){
  int ns;
  for(ns = 0; gettoken() == '*'; )
    ns++;
  dirdcl();
  while(ns-- > 0)
    strcat(out, " pointer to");
}

void dirdcl(void){
  int type;
  if(tokentype == '('){
    dcl();
    if(tokentype != ')')
      errormsg("error: missing ')'");
  } else if (tokentype == NAME)
    strcpy(name, token);
  else
    errormsg("error: expected name or (dcl)");
  while((type=gettoken()) == PARENS || type == BRACKETS)
    if(type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}


void errormsg(char *s){
  printf("%s\n", s);
  prevtoken = YES;
}
  


void error(char *s){
  printf("%s\n", s);
  exit(1);
}
