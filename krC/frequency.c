#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDLEN 100

char getch(void);
void ungetch(char);
char getword(char *, uint16_t);

struct wordnode {
  char *word;
  uint16_t count;
  struct wordnode *left;
  struct wordnode *right;
};

char *wordalloc(char *word);
struct wordnode *wnalloc(void);

struct wordnode *addwordnode(struct wordnode *node, char *word, size_t *wordcount);

void treeprint(struct wordnode *node);
void treetoarray(struct wordnode *node, struct wordnode *nodes[]);

void myqsort(int v[], int left, int right);
void myswap(int v[], int i, int j);

int main(void) {
  char word[MAXWORDLEN];
  char fc;
  struct wordnode *root = nullptr;
  size_t wordcount = 0;

  while ((fc = getword(word, MAXWORDLEN)) != EOF) {
    root = addwordnode(root, word, &wordcount);
  }
  printf("%lu\n", wordcount);

  treeprint(root);

  return 0;
}


void printbycount(struct wordnode *node, size_t wordcount){
  struct wordnode *wordlist[wordcount];

  size_t idx = 0;
  addToArray(node, wordlist, idx);

  myqsort(wordlist, 0, wordcount-1);
  for(size_t i = 0; i < wordcount; i++){
    printf("%d - %s\n", wordlist[i]->count, wordlist[i]->word);
  }
}

void addToArray(struct wordnode *node, struct wordnode *wordlist[], size_t *idx){
  if(node != nullptr){
    addToArray(node->left, wordList, idx);
    (*idx)++;
    wordList[idx] = node;
    addToArray(node->right, wordList, idx);
  }
}
  


void treeprint(struct wordnode *node) {
  if (node != nullptr) {
    treeprint(node->left);
    printf("%d - %s\n", node->count, node->word);
    treeprint(node->right);
  }
}

struct wordnode *addwordnode(struct wordnode *node, char *word, size_t *wordcount) {
  int cond;
  if (node == nullptr) {
    node = wnalloc();
    node->word = wordalloc(word);
    node->count = 1;
    node->left = nullptr;
    node->right = nullptr;
    (*wordcount)++;
  } else if ((cond = strcmp(word, node->word)) < 0) {
    node->left = addwordnode(node->left, word, wordcount);
  } else if (cond > 0) {
    node->right = addwordnode(node->right, word, wordcount);
  } else {
    node->count++;
  }
  return node;
}

char *wordalloc(char *word) {
  char *wa = (char *)malloc(strlen(word) + 1);
  if (wa != nullptr)
    strcpy(wa, word);
  return wa;
}

struct wordnode *wnalloc(void) {
  return (struct wordnode *)malloc(sizeof(struct wordnode));
}

char charBuff[MAXWORDLEN];
uint16_t charBuffIdx = 0;

char getch() { return charBuffIdx ? charBuff[--charBuffIdx] : getchar(); }

void ungetch(char c) {
  if (charBuffIdx >= MAXWORDLEN)
    printf("too many characters for buffer.");
  else
    charBuff[charBuffIdx++] = c;
}

char getword(char *word, uint16_t lim) {
  char c;
  char *lw = word;

  while (isspace(c = getch()) && !isalpha(c) && c != EOF)
    ;

  if (c == EOF) {
    return EOF;
  }

  if (isalpha(c)) {
    *lw++ = c;
    while ((*lw = getch()) && isalpha(*lw))
      lw++;
    ungetch(*lw);
    *lw = '\0';
  }

  return *word;
}


void myqsort(int v[], int left, int right){
  int i, last;

  if(left >= right)
    return;
  myswap(v, left, (left + right)/2);
  last = left;
  for(i = left + 1; i <= right; i++){
    if(v[i] < v[left])
      myswap(v, ++last, i);
  }
  myswap(v, left, last);
  myqsort(v, left, last-1);
  myqsort(v, last+1, right);
}

void myswap(int v[], int i, int j){
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
