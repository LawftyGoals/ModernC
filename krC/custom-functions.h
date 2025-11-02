#ifndef CUSTOM_ITOA_H_
#define CUSTOM_ITOA_H_
#define MAXOP 100
#define NUMBER '0'

int strindex(char *, char *);

void itob(int, char *, int);

void itoa(int n, char s[]);

void reverse(char s[]);

double custom_atof(char *);

int getop(char[]);
void push(double);
double pop(void);
void clear(void);

int reverse_polish(void);

int getch(void);
void ungetch(int);


#endif
