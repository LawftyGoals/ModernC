#ifndef CUSTOM_ITOA_H_
#define CUSTOM_ITOA_H_
#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
#define swap(t, x, y) { \
  t z = x; \
  x = y; \
  y = z; }

int strindex(char *, char *);

void itob(int, char *, int);

void itoa(int n, char s[]);

void reverse(char s[]);
void recverse(char[]);

double custom_atof(char *);

int getop(char[]);
void push(double);
double pop(void);
void clear(void);

int reverse_polish(void);

int getch(void);
void ungetch(int);


void mathfunc(char[]);

void itoa_rec(signed, char[]);

int getint(int *);
int getFloat(double *);

void new_strcat(char *, char *);

#endif
