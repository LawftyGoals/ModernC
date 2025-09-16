#include <stdio.h>
#include <stdlib.h>

int main() {
	

	signed long long sll = -1;
	signed long long sll2 = 9223372036854775807;

	printf("%lld\n%lld\n", sll, sll2+1);


	unsigned int ui = 0xffff'ffff;
	unsigned int hui = 0x8000'0000;
	unsigned int mhui = -0x8000'0000;
	printf("%u ui, %u hui, %u mhui\n", ui, hui, mhui);

	return EXIT_SUCCESS; 

}

