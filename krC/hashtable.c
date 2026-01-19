#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101


struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

static struct nlist *hashtab[HASHSIZE];


unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char* name, char *defn);
char *stralloc(char *);

void undef(char *name);
void zeroList();
void printlist();

int main(void){
  zeroList();
  install("shoulder", "testing");
  printlist();
  undef("shoulder");
  printlist();

  return 0;
}

void printlist(){
  struct nlist *target;
  for(uint16_t i = 0; i < HASHSIZE; i++){
    if((target = hashtab[i]) != NULL){
      printf("%s\n", target->name);
      while(target->next != NULL){
        printf("%s\n", target->next->name);
        target = target->next;
      }
    }
  }
}

void zeroList(){
  for(uint16_t i = 0; i < HASHSIZE; i++){
    hashtab[i] = NULL;
  }
}

unsigned hash(char *s){
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++){
    hashval = *s + 31 * hashval;
  }
  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
  struct nlist *np;

  for((np = hashtab[hash(s)]); np != NULL; (np = np->next)){
    if(strcmp(s, np->name) == 0)
      return np;
  }
  return NULL;
}

char *stralloc(char *c){
  char *p = (char *)malloc(strlen(c) + 1);

  if(p != NULL)
    strcpy(p, c);
  return p;
}


struct nlist *install(char *name, char *defn){
  struct nlist *np;
  unsigned hashval;

  if((np = lookup(name)) == NULL) {
    np = (struct nlist *)malloc(sizeof(*np));
    if(np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else
    free((void*) np->defn);
  if((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

void undef(char *name){
  struct nlist *np;
  struct nlist *prevnp = NULL;

  unsigned hashval = hash(name);

  for((np = hashtab[hashval]); np != NULL; np = np->next){
    if(strcmp(np->name, name) == 0){
      free(np->name);
      free(np->defn);

      if(prevnp == NULL){
        hashtab[hashval] = np->next;
      } else {
        prevnp->next = np->next;
      }

      free(np);

      return;
    }
    prevnp = np;
  }

  /*

  if(np != NULL){
    free(np->name);
    free(np->defn);
    
    if(np->next != NULL){
      nextnp = np->next;

      np->name = nextnp->name;
      np->defn = nextnp->defn;
      np->next = nextnp->next;

      free(nextnp);
    } else {
      free(np);

    }
  }*/
}
    




