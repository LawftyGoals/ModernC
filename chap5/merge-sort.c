#include <stdio.h>
#include <stdlib.h>



int main (int argc, char* argv[argc+1]) {
	int start[] = {78, 56, 36, 12, 67, 3, 6, 2342, 236};

	int rec(int list[sizeof(start)]) {
		for(int i = 0; i < sizeof(list); i++){
			printf("%d", list[i]);
		}
		return EXIT_SUCCESS;
	}
	
	rec(start);

	return EXIT_SUCCESS;

}
