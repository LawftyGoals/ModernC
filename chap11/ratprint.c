#include <stdio.h>
typedef struct rat rat;
struct rat {
  bool sign;
  size_t num;
  size_t denom;
};

char const* rat_print(size_t len, char tmp[len], rat const* x);


int main(){

  char la[100];
  size_t len = 100;
  struct rat rattas = {.sign = 1, .num = 3, .denom = 4};
  rat const* ratptr = &rattas;
  printf("%s\n", rat_print(len, la, ratptr));
  
  return 0;
}


char const* rat_print(size_t len, char tmp[len], rat const* x) {

  char nume[len];
  char denome[len];

  size_t intNume= x->num;
  size_t intDenome = x->denom;

  size_t sizeNume = 0;
  size_t sizeDenome = 0;

  while(intNume != 0){
    intNume /= 10;
    ++sizeNume;
  }
  while(intDenome != 0){
    intDenome /= 10;
    ++sizeDenome;
  }
  intNume = x->num;
  intDenome = x->denom;

  nume[sizeNume] = '\0';
  denome[sizeDenome] = '\0';
  for(int i = sizeNume-1; i >= 0; --i){
    nume[i] = (intNume % 10) + '0';
    intNume /= 10;
  }
  for(int i = sizeDenome-1; i >= 0; --i){
    denome[i] = (intDenome % 10) + '0';
    intDenome /= 10;
  }
  tmp[0] = x->sign ? '+' : '-';
  for(int j = 0; j < sizeNume; ++j){
    tmp[j + 1] = nume[j];
  }
  tmp[sizeNume + 1] = '/';
  for(int k = 0; k < sizeDenome; ++k){
    tmp[k + sizeNume + 2] = denome[k];
  }

  //sprintf(tmp, "%c%ld/%ld", x->sign ? '+' : '-', x->num, x->denom);
  return tmp;
}


