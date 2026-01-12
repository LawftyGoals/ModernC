#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define MAXCHARBUFF 100
#define MAXWORDSIZE 100
#define STOPWORDCOUNT 125
#define MAXLINENRS 100

char *binarywordsearch(char *word, char **list, uint16_t lim);

char getch(void);
void ungetch(char);
char getword(char *, uint16_t);
char *stralloc(char *);

struct linenode
{
  uint16_t linenr;
  struct linenode *nextlinenr;
};

struct wordnode
{
  char *word;
  int count;
  struct linenode *linenr;
  struct wordnode *left;
  struct wordnode *right;
};

struct wordnode *nodealloc(void);
struct wordnode *addnode(char *, struct wordnode *);
void treeprint(struct wordnode *);

struct linenode *linenralloc(uint16_t);
void addlinenode(struct linenode *ln, uint16_t);
void linenrprint(struct linenode *);

char *stopwords[STOPWORDCOUNT] = {"a", "about", "above", "after", "again", "against", "all", "am", "an", "and", "any", "are", "as", "at", "be", "because", "been", "before", "being", "below", "between", "both", "but", "by", "can", "did", "do", "does", "doing", "don", "down", "during", "each", "few", "for", "from", "further", "had", "has", "have", "having", "he", "her", "here", "hers", "herself", "him", "himself", "his", "how", "i", "if", "in", "into", "is", "it", "its", "itself", "just", "me", "more", "most", "my", "myself", "no", "nor", "not", "now", "of", "off", "on", "once", "only", "or", "other", "our", "ours", "ourselves", "out", "over", "own", "same", "she", "should", "so", "some", "such", "than", "that", "the", "their", "theirs", "them", "themselves", "then", "there", "these", "they", "this", "those", "through", "to", "too", "under", "until", "up", "very", "was", "we", "were", "what", "when", "where", "which", "while", "who", "whom", "why", "will", "with", "you", "your", "yours", "yourself", "yourselves"};

uint16_t globallinenr = 1;

int main(int argc, char *argv[])
{

  char word[MAXWORDSIZE];
  char wordchar;
  struct wordnode *root = nullptr;

  while ((wordchar = getword(word, MAXWORDSIZE)) != EOF)
  {
    if(wordchar == '\n')
      globallinenr++;
    else if (!binarywordsearch(word, stopwords, STOPWORDCOUNT - 1))
      root = addnode(word, root);
  }

  treeprint(root);

  return 0;
}

void treeprint(struct wordnode *node)
{
  if (node != nullptr)
  {
    treeprint(node->left);
    printf("%-45s", node->word);
    linenrprint(node->linenr);
    treeprint(node->right);
  }
}

void linenrprint(struct linenode *root)
{
  struct linenode *ln = root;
  while (ln->nextlinenr != nullptr)
  {
    printf("%d, ", ln->linenr);
    ln = ln->nextlinenr;
  }
  printf("%d\n", ln->linenr);
}

struct wordnode *addnode(char *w, struct wordnode *startnode)
{

  int cond;

  if (startnode == nullptr)
  {
    startnode = nodealloc();
    startnode->word = stralloc(w);
    startnode->count = 1;
    startnode->linenr = linenralloc(globallinenr);
    startnode->left = nullptr;
    startnode->right = nullptr;
  }
  else if ((cond = strcmp(startnode->word, w)) < 0)
    startnode->right = addnode(w, startnode->right);

  else if (cond > 0)
    startnode->left = addnode(w, startnode->left);
  else
  {
    startnode->count++;
    addlinenode(startnode->linenr, globallinenr);
  }

  return startnode;
}

void addlinenode(struct linenode *ln, uint16_t linenr)
{
  if (ln->linenr != linenr)
  {
    if (ln->nextlinenr == nullptr)
    {
      ln->nextlinenr = linenralloc(linenr);
    }
    else
    {
      addlinenode(ln->nextlinenr, linenr);
    }
  }
}

char *stralloc(char *s)
{
  uint16_t size = strlen(s);
  char *dest = (char *)malloc(size + 1);
  if (dest != nullptr)
    strcpy(dest, s);
  return dest;
}

struct linenode *linenralloc(uint16_t linenr)
{

  struct linenode *ln = (struct linenode *)malloc(sizeof(struct linenode));
  ln->linenr = linenr;
  ln->nextlinenr = nullptr;
  return ln;
}

struct wordnode *nodealloc(void)
{
  return (struct wordnode *)malloc(sizeof(struct wordnode));
}

char *binarywordsearch(char *word, char **list, uint16_t lim)
{
  char **start = list;
  char **end = list + lim;
  char **mid;

  int cond;

  while (start < end)
  {
    mid = start + (end - start) / 2;
    if ((cond = strcmp(word, *mid)) < 0)
      end = mid;
    else if (cond > 0)
      start = mid + 1;
    else
      return *mid;
  }

  return nullptr;
}

char charbuff[MAXCHARBUFF];
int charbuffidx = 0;

char getch(void)
{
  return charbuffidx ? charbuff[--charbuffidx] : getchar();
}

void ungetch(char c)
{
  if (charbuffidx >= MAXCHARBUFF)
    printf("Char buffer too small.");
  else
    charbuff[charbuffidx++] = c;
}

char getword(char *tw, uint16_t lim)
{
  char c;
  char *lw = tw;
  uint16_t idx = 0;

  while (isspace(c = getch()) && !isalpha(c) && c != EOF && c != '\n')
    ;

  if (c == '\n')
  {
    *lw = c;
    *++lw = '\0';
    return c;
  }

  if (c == EOF)
  {
    return c;
  }

  if (isalpha(c))
  {
    *lw++ = c;
    while (idx < lim && (isalpha(*lw = getch()) || *lw == '-'))
    {
      if (*lw == '-' && isalpha(c = getch()))
      {
        *++lw = c;
      }
      lw++;
      idx++;
    }

    if (*lw == '\n')
      ungetch('\n');

    *lw = '\0';
  }

  return *tw;
}
