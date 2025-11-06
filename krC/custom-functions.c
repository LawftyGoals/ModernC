#include "custom-functions.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void itoa(int n, char s[]){
  int i, sign;
  unsigned un = (unsigned) n;
  if((sign=n) < 0) n = -n;

  i = 0;
  do {
    s[i++] = un % 10 + '0';
  } while((un /= 10) > 0);
  
  if(sign < 0) s[i++] = '-';
  s[i] = '\0';
  reverse(s);
 
}

void itob(int n, char s[], int b) {
  int i, sign;
  unsigned un = (unsigned) n;
  sign = n < 0 ? 1 : 0;

  i = 0;
  do {
    int j = un % b;
    s[i++] = (j < 10) ? j + '0' : j - 10 + 'a';
  } while ((un /= 10) > 0);

  if(sign) {
    s[i++] = 0;
  }

  s[i] = '\0';
  reverse(s);
}


void reverse(char s[]) {
  int len = 0;
  while(s[len] != '\0') len++;

  int half = len/2;
  len -= 1;
  int i = 0;
  char temp;

  while(i <= half) {
    temp = s[len - i];
    s[len - i] = s[i];
    s[i++] = temp;
  }
}


// E.4-1

int strindex(char s[], char t[]) {
  int i = 0;
  int j, k;
  int ret = -1;
  while(s[i++] != '\0') {
    if(s[i] == t[0]){
      for(j = i, k = 0;s[j] != '\0' && t[k] != '\0'; j++, k++);
      if(k > 0 && t[k] == '\0') ret = i;
    }
  }
  return ret;
}

double custom_atof(char s[]){
  double val, power;
  int i, sign;
  for(i = 0; isspace(s[i]); i++) ;
  sign = (s[i] == '-') ? -1 : 1;
  
  if(s[i] == '+' || s[i] == '-') {
    i++;
  }
  
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if(s[i] == '.') {
    i++;
  }

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }


  val =  sign * val / power;
  
  if(s[i] == 'e' || s[i] == 'E') {
    i++;
    int esign = s[i] == '-' ? 1 : 0;
    if(s[i] == '-' || s[i] == '+') {
      i++;
    }

    int exp = 0;
    while(isdigit(s[i])) {
      exp = (exp * 10) + (s[i] - '0');
      i++;
    }

    if(esign){
      while (exp-- > 0){
        val /= 10;
      }
    }
    else {
      while(exp-- > 0) {
        val *= 10;
      }
    }
  }


  return val;
}



int reverse_polish(void) {
  char s1[MAXOP];
  int type, varType = 0;
  double op2, op1;
  double variables[26];
  for(int i = 0; i < 26; i++) variables[i] = 0.0;

  while((type = getop(s1)) != EOF) {
    
    switch(type) {
      case NUMBER:
        push(atof(s1));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 !=0.0) push(pop() / op2);
        else printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        if(op2 != 0.0) push((unsigned)pop() % (unsigned)op2);
        else printf("error: modulo by zero\n");
        break;
      case '?': //Print top element of stack
        op2 = pop();
        printf("\t%.8g\n", op2);
        push(op2);
        break;
      case 'd': // duplicate top stack element
        op2 = pop();
        push(op2);
        push(op2);
        break;
      case 's': // swap top elements on stack
        op1 = pop();
        op2 = pop();
        push(op1);
        push(op2);
        break;
      case 'c': // clears the stack.
        clear();
        break;
      case NAME:
        mathfunc(s1);
        break;
      case '=':
        pop();
        if(varType >= 'A' && varType <= 'Z') variables[varType - 'A'] = pop();
        else printf("error: no variable name\n");
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        if(type >= 'A' && type <= 'Z') push(variables[type - 'A']);
        else printf("error: unknown command %s\n", s1);
        break;
    }
    varType = type;
  }
  return 0;
}

int sp = 0;
double val[MAXOP];

void push(double f) {
  if(sp < MAXOP) val[sp++] = f;
  else printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
  if(sp>0) return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void clear(){
  for(int i = 0; i <= sp; i++) val[i] = 0;
  sp = 0;
}

int getop(char s[]) {
  int i;
  char c;
  while ((s[0] = c = getch()) == ' ' || c == '\t');

  s[1] = '\0';
  int isDigit = isdigit(c);

  i = 0;
  if(islower(c)){
    while(islower(s[++i] = c = getch()));

    s[i] = '\0';
    if(c != EOF) ungetch(c);

    if(strlen(s) > 1) return NAME;

    else return c;
 }

  if (!isDigit && c != '.' && c != '-') return c;

  if(c == '-') while(isdigit(s[++i] = c = getch()));

  if (isDigit) while(isdigit(s[++i] = c = getch()));

  if(c == '.') while(isdigit(s[++i] = c = getch()));

  s[i] = '\0';
  if(c != EOF) ungetch(c);
  
  return NUMBER;
}

char line[MAXOP];


/*
int buf[MAXOP];
int bufp = 0;
*/
int buffered = 0;
/*
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}
*/
int getch(void){
  int c;
  if(buffered != 0){
    c = buffered;
    buffered = 0;
  } else c = getchar();
  return c;
}

void ungetch(int c){
  if(buffered != 0) printf("Error: Too many chars on buffer");
  else buffered = c;
}
/*
void ungetch(int c) {
  if(bufp >= MAXOP) printf("ungetch: too many characters \n");
  else buf[bufp++] = c;
}*/

void ungets(char s[]){
  size_t len = strlen(s);
  while(len > 0) ungetch(s[--len]);
}

void mathfunc(char s[]){
  double op2;
  double op1;
  if(strcmp(s, "sin") == 0) {
    push(sin(pop()));
  } else if (strcmp(s, "cos") == 0) {
    push(cos(pop()));
  } else if (strcmp(s, "exp") == 0) {
    push(exp(pop()));
  } else if(strcmp(s, "pow") == 0) {
    op2 = pop();
    op1 = pop();
    push(pow(op1, op2));
  } else {
    printf("error: %s not supported.\n", s);
  }

}


int getline(char[], int);
/*
int getopwgetline(char s[]){
  int sizedline, i;
  char c;
  if(line[lineIndex] == '\0'){
    if((sizedline = getline(line, MAXOP)) < 1) return EOF;
    else lineIndex = 0;
  }

  while((s[0] = c = line[lineIndex++]) == ' ' || c == '\t');

  s[1] = '\0';
  bool isDigit = isdigit(c);
  if(!isDigit && c != '.') return c;
  i = 0;
  
  if(isDigit) while(isdigit(s[++i] = c = line[lineIndex++]));


  if(c == '.') while(isdigit(s[++i] = c = line[lineIndex++]));

  s[i] = '\0';
  lineIndex--;

  return NUMBER;
}
*/

int getline(char s[], int lim) {
  char c;
  int i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++){
    s[i] = c;
  }
  if(c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  
  return i;
}

size_t recurser(char[], size_t);

void recverse(char s[]) {

  recurser(s, 0);
}

size_t recurser(char s[], size_t i) {
  char c = s[i];
  if(c == '\0') return i - 1;
  
  size_t end = recurser(s, i+1);

  s[end - i] = c;
  
  return end;
}


void itoa_rec(signed n, char s[]){
  static size_t i;
  if (n / 10){
    itoa_rec(n / 10, s);
  } else{
    i = 0;
    if(n < 0){
      s[i++] = '-';
    }
  }
  s[i++] = abs(n) % 10 + '0';
  s[i] = '\0';
}



