#include <stdio.h>
#include <math.h>
#include <string.h>
size_t fib(size_t n) [[__unsequenced__]] {
  if(n<3) return 1;
  else return fib(n-1) + fib(n-2);
}


size_t fibCacheRec(size_t n, size_t cache[static n]) {
  if(!cache[n-1]) {
    cache[n-1] = fibCacheRec(n-1, cache) + fibCacheRec(n-2, cache);
  }
  return cache[n-1];
}

size_t fibCache(size_t n) {
  if(n+1 <= 3) return 1;
#if __STDC__VERSION__ > 202311L
  printf("new version");
  size_t cache[n] = {};
#else
  size_t cache[n]; memset(cache, 0, n*sizeof(*cache));
#endif
  cache[0] = 1; cache[1] = 1;
  return fibCacheRec(n, cache);
}

void fib2rec(size_t n, size_t buf[static 2]) [[__unsequenced__]] {
  if(n>2) {
    size_t res = buf[0] + buf[1];
    buf[1] = buf [0];
    buf[0] = res;
    fib2rec(n-1, buf);
  }
}

size_t fib2(size_t n) [[__unsequenced__]] {
  size_t res[2] = {1, 1};
  fib2rec(n, res);
  return res[0];
}

int main(int argc, char* argv[argc+1]){

  float fibbo = (1+sqrt(5))/2;

  unsigned n = 50;

  float Fn = pow(fibbo, (double) n)/sqrt(5);

  printf("fibbo: %f, Fn = %f\n", fibbo, Fn);
  /*printf("%lu fib of %u\n", fib(n), n); 
*/

  size_t n2 = 100;
  printf("%lu fib of %lu\n", fibCache(n2), n2);
  printf("%lu fib of %lu\n", fib2(n2), n2);
  return 0;
}

