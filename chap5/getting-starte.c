#include <stdlib.h>
#include <stdio.h>
#include <tgmath.h> /*standard macro fabs */
/*#include <stdbool.h>  is needed on older C versions than 23 */
/*[[maybe_unused]] is a c23 attribute that will not work on the previous cs*/
int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
	double A[5] = {
		[0] = 9.0,
	       	[1] = 1.9,
		[4] = 3.E+25,
		[3] = .00007
	};
	bool bol = true;
	size_t i = 0;
	for (size_t j = i; j < 5; j++){

		printf("element %zu is %g, \tits square is %g\n", j, A[j], A[j] *A[j]);

	}

	int max_iterations = 15;
	double a = 3.0;
	double s = 10.0;
	double x = 0.5;
	for (size_t i = 0; i < max_iterations; ++i){
		if(bol && x > 1.0){
			x = 1.0 /x;
			continue;
		}
		double prod = a*x;
		if (fabs(1.0 - prod) < s){
			break;
		}
		x *= (2.0 - prod);
		printf("test %f", x);
	}


	return EXIT_SUCCESS;
}
