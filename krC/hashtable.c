#define HASHSIZE 101

struct nlist {
  struct nlinst *next;
  char *name;
  char *defn;
}

static struct nlinst *hastab[HASHSIZE];


unsigned hash(char *s);
struct nlist *lookup(char *s);
char *stralloc(char *);

unsigned hash(char *s){
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++){
    hashval = *s + 31 * hashval;
  }
  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
  struct nlist *np;

  for(np = hashtab[hash(s)]; np != NULL; np = np-next){
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






