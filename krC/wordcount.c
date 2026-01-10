#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>


#define MAXCHARBUFF 100
#define MAXWORDSIZE 100
#define STOPWORDCOUNT 125

char *binarywordsearch(char *word, char **list, uint16_t lim);

char getch(void);
void ungetch(char);
char getword(char *, uint16_t);


char *stopwords[STOPWORDCOUNT] = {"a", "about", "above", "after", "again", "against", "all", "am", "an", "and", "any", "are", "as", "at", "be", "because", "been", "before", "being", "below", "between", "both", "but", "by", "can", "did", "do", "does", "doing", "don", "down", "during", "each", "few", "for", "from", "further", "had", "has", "have", "having", "he", "her", "here", "hers", "herself", "him", "himself", "his", "how", "i", "if", "in", "into", "is", "it", "its", "itself", "just", "me", "more", "most", "my", "myself", "no", "nor", "not", "now", "of", "off", "on", "once", "only", "or", "other", "our", "ours", "ourselves", "out", "over", "own", "same", "she", "should", "so", "some", "such", "than", "that", "the", "their", "theirs", "them", "themselves", "then", "there", "these", "they", "this", "those", "through", "to", "too", "under", "until", "up", "very", "was", "we", "were", "what", "when", "where", "which", "while", "who", "whom", "why", "will", "with", "you", "your", "yours", "yourself", "yourselves"};



int main(int argc, char *argv[]){

  char word[MAXWORDSIZE];
  char wordchar;

  while((wordchar = getword(word, MAXWORDSIZE)) != EOF){
      if(!binarywordsearch(word, stopwords, STOPWORDCOUNT-1))
        printf("%s\n", word);
  }

  return 0;
}



char *binarywordsearch(char *word, char**list, uint16_t lim){
  char **start = list;
  char **end = list + lim;
  char **mid;

  int cond;

  while(start < end){
    mid = start + (end - start)/2;
    if((cond = strcmp(word, *mid)) < 0)
      end = mid;
    else if(cond > 0)
      start = mid + 1;
    else
      return *mid;
  }
  
  return nullptr;
}

char charbuff[MAXCHARBUFF];
int charbuffidx = 0;

char getch(void){
  return charbuffidx ? charbuff[--charbuffidx] : getchar();
}

void ungetch(char c){
  if(charbuffidx >= MAXCHARBUFF) printf("Char buffer too small.");
  else 
    charbuff[charbuffidx++] = c;
}

char getword(char *tw, uint16_t lim){
  char c;
  char *lw = tw;
  uint16_t idx = 0;

  while(isspace(c = getch()) && !isalpha(c) && c != EOF);

  if(c == EOF){
    return c;
  }

  if(isalpha(c)){
    *lw++ = c;
    while(idx < lim && (isalpha(*lw = getch()) || *lw == '-')){
      if(*lw == '-' && isalpha(c = getch())){
        *++lw = c;
      }
      lw++;
      idx++;
    }

    *lw = '\0';
  }

  return *tw;
}




