#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

	long int tstamp = time(NULL);
	srand(tstamp);
	unsigned long first_half = (unsigned long) rand();
	first_half = first_half << 32;
	unsigned long second_half = (unsigned long) rand();
	unsigned long random64bit = first_half | second_half;
	printf("%lu\n", random64bit);

	int size = sizeof(unsigned long) * 8;
	printf("%d\n", size);

	unsigned long mask = 1UL << (size - 1);

	for (int i = 0; i < size; i++) {
		printf("%u", random64bit & mask ? 1 : 0);
		random64bit = random64bit << 1;
	}
}
