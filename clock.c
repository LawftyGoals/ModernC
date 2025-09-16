#include <time.h>
#include <stdio.h>


int main() {
				clock_t ct = clock();
				time_t tt = time(0);

				printf("clock: %ld\ntime: %ld\n", ct, tt);
				}

