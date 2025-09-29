#include <stdio.h>
#include <stdlib.h>

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

void printarr(size_t len, double* thearr){
  for(size_t i = 0; i < len; i++) {
      printf("dub%ld: %f, ", i, *(thearr + i));
  } printf("\n");
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

  return EXIT_SUCCESS;
}
