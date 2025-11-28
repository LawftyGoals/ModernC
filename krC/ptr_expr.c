#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

int stack[MAXLINE];
int stackIndex = -1;

void push(int);
int pop(void);

int main(int argc, char *argv[]) {

  int currentValue;
  
  while(--argc > 0){
    if(isdigit(currentValue = (*++argv)[0])){
      push(currentValue - '0');
    } else if (currentValue == '*'){
      push(pop() * pop());
    } else if (currentValue == '-') {
      int pop1 = pop();
      push(pop() - pop1);
    } else if (currentValue == '+') {
      push(pop() + pop());
    }
  }
  printf("%d\n", stack[0]);
  return 0;
}

int *stckptr = stack;
void push(int val){
  if(stackIndex < MAXLINE){
    *stckptr++ = val;
  //stack[++stackIndex] = val;
  }
}

int pop(){
  int returnVal = 0;
  if (stackIndex < 0) {
    returnVal = *--stckptr;
    //returnVal = stack[stackIndex--];
  } else {
    printf("No items on stack");
  }
  return returnVal;
}



