#include <stdio.h>
#include <stdint.h>
#include <limits.h>


enum corvid {magpie, raven, jay, chough, corvid_num};
#define FLOCK_MAGPIE  (1U << magpie)
#define FLOCK_RAVEN   (1U << raven)
#define FLOCK_JAY     (1U << jay)
#define FLOCK_CHOUGH  (1U << chough)
#define FLOCK_EMPTY   0U
#define FLOCK_FULL    ((1U << corvid_num)-1)

int main() {
unsigned flock = FLOCK_EMPTY;

constexpr unsigned _BitInt(3) max3u = -1wbu;

if(true) flock |= FLOCK_JAY;

if(flock&FLOCK_JAY) printf("should print jay: %u\n", flock);

if(flock&FLOCK_CHOUGH) printf("should not print chough: %u\n", flock);

printf("testing bitshift 4>>2: %u\n", (unsigned)4>>2);

printf("_BitInt(3) = -1 test: %u\n", max3u);

unsigned short As = 0b00000000'10000000;
printf("test signed: %hd\n", (signed short)As<<8);

unsigned A =240; 
printf("A + ~A = %u: %u\n", UINT_MAX, (A+~A));

printf("A + ~A = -1: %i\n", A + ~A);
printf("A + (~A + 1) == 0: %u\n", A+(~A+1));
int min = INT_MIN;
int max = INT_MAX;

printf("INT_MIN + INT_MAX: %d\n", min+max);

signed short SS = 0b10000000'00000000;

printf("0b10000000'000000000 (only signed bit active) -32768: %hd\n", SS);

printf("0b11000000'000000000 -16384: %hd\n", 0b11000000'00000000);


printf("0b01111111'111111111 32767: %hd\n", 0b01111111'11111111);
printf("0b11111111'111111111 -1: %hd\n", 0b11111111'11111111);

printf("0b01000000'000000000 << 1: %hd\n", 0b01000000'00000000<<1);
  uint32_t n = 78;
  int64_t big = (-UINT64_C(1))>>1;
  printf("n is %w32u, and big is %w64d\n", n, big);

  return 0;
}
