#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[argc+1]) {
	int nth = atoi(argv[1]);
	printf("%d nth\n", nth);

	double start = 0;

	for(int i = 0; i <= nth; ++i){
		printf("%d i %f start %d test\n", i, start, i%2);
			int power = i*2+1;
			double machin = (16/powl(5, power) - 4/powl(239, power));
			if(i % 2 == 0){
				printf("in modulus\n");
				start += machin;
			} else {
				start -= machin ;
			}
	
		printf("%f pi\n", start);
	}

	printf("%f\n", start);

	return EXIT_SUCCESS;

}
