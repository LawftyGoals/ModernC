#include "custom-functions.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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
  int type;
  double op2, op1;

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
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s1);
        break;
    }
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
  if (!isDigit && c != '.' && c != '-') return c;

  i = 0;
  if(c == '-') while(isdigit(s[++i] = c = getch()));

  if (isDigit) while(isdigit(s[++i] = c = getch()));

  if(c == '.') while(isdigit(s[++i] = c = getch()));

  s[i] = '\0';
  if(c != EOF) ungetch(c);
  
  return NUMBER;
}

char buf[MAXOP];
int bufp = 0;
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if(bufp >= MAXOP) printf("ungetch: too many characters \n");
  else buf[bufp++] = c;
}

