#include <stddef.h>
#ifndef CUSTOM_ITOA_H_
#define CUSTOM_ITOA_H_
#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
#define MAXLINES 5000
#define MAXSTOR 5000
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
void new_strncpy(char *, char *, size_t);
void new_strncat(char *, char *, size_t);

int getline(char *, int);
int readlines(char *lineptr[],char *linestor, int nlines);
void writelines(char *lineptr[], int nlines);

void qsorts(char *lineptr[], int left, int right);

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);


#endif
