#include <stdio.h>
#include <stdlib.h>

int main() {
	

	signed long long sll = -1;
	signed long long sll2 = 9223372036854775808;

	printf("%lld\n%lld\n", sll, sll2+1);

	return EXIT_SUCCESS; 

}

