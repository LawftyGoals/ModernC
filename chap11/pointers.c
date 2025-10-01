#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>

struct buffy {
  char name[16];
  uint8_t age;
};

typedef struct buffy buffy;

void double_swap(double *p0, double *p1, double *p2) {
  auto tmp = *p0;
  *p0 = *p1;
  *p1 = *p2;
  *p2 = tmp;
}
//                            also works with const a[]
double sum_double_arr(size_t len, double const* a) {
  double ret = 0.0;
  for ( size_t i = 0; i < len; i++) {
    ret += *(a+i);
  }
  return ret;
}


double sum_doub_arr2(size_t len, double const* a) {
  double ret = 0.0;
  for (double const* p = a; p < a+len; ++p) {
    ret += *p;
  }
  return ret;
}

double sum_dub_arr3(size_t len, double const* a) {
  double ret = 0.0;
  for(double const*const aStop = a+len; a < aStop; ++a) {
    ret += *a; 
  }
  return ret;
}

double sum_reverse_arr(size_t len, double const* a) {
  double ret = 0.0;
  double const* p = a + len-1;
  do {
    ret += *p;
    --p;
  } while (p >= a);
  return ret;
}

void printarr(size_t len, double* thearr){
  for(size_t i = 0; i < len; i++) {
      printf("dub%ld: %f, ", i, *(thearr + i));
  } printf("\n");
}

double memory_arr(size_t len, double const* a) {
  double ret = 0.0;
  for(size_t i = 0; i < len; i++){
    ret += *(a+i);
  }
  return ret;
}

double memory_arr2(size_t len, double const* a) {
  double ret= 0.0;
  for(double const* p = a; p < (a + len); ++p){
    ret += *p;
  }
  return ret;
}

double sum4(size_t len, double const* a){
  double ret = 0.0;
  double const* p = a+len-1;
  do {
    if (isinf(*p)) {
      fprintf(stderr, "element %tu of array at %p is infinite\n",
          p-a,
          (void*)a);
      return *p;
    }
    ret += *p;
    --p;
  } while (p >= a);
  return ret;
}


int main(int argc, char *argv[argc+1]){

  double d0 = 9.0;
  double d1 = 3.0;
  double d2 = 6.0;

  double_swap(&d0, &d1, &d2);

  printf("d0: %f, d1: %f, d2: %f\n", d0, d1, d2);


  constexpr size_t arr_len= 5;
  double dub_arr[arr_len] ={ 1.0, 2.0, 3.0, 4.0, 5.0 };

  printf("sumdubarr: %f\n", sum_double_arr(arr_len, dub_arr));
  printf("sumdubarr2: %f\n", sum_doub_arr2(arr_len, dub_arr));
  printf("sumdubarr3: %f\n", sum_dub_arr3(arr_len, dub_arr));

  printarr(arr_len, dub_arr);
  printarr(3, &dub_arr[1]);

  printf("sumreversearr: %f\n", sum_reverse_arr(arr_len, dub_arr));
  
  printf("memarr: %f\n", memory_arr(arr_len, dub_arr));
  printf("memarr2: %f\n", memory_arr2(arr_len, dub_arr));
  printf("sum4: %f\n", sum4(arr_len, dub_arr));

  double A[4] = { 0.0, 1.0, 2.0, -3.0};
  double* p = &A[1];
  double* q = &A[3];
  //assert(p-q == -2);

  char boi[] = "boiiii";

  ptrdiff_t diffptr = *p-*q;
  printf("point cons: %f, %p, sum: %ld, %s\n", *p, (void*)q, diffptr, boi);

  char name[] = "Beenjamin";
  char const* nameptr = nullptr;
  nameptr = name;

  size_t testint = 123;
  size_t const* testintptr = nullptr;
  testintptr = &testint;

  printf("name: %s, int: %ld\n", nameptr, *testintptr);

  buffy buffy1 = { .name = "buffy", .age = 18 };

  struct buffy const* buffyptr = &buffy1;

  printf("pointer to buffys->name: %s, pointer to buffys->age: %u\n", buffyptr->name, buffyptr->age);

  return EXIT_SUCCESS;
}
