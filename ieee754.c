#include <stdio.h>

void ftob(double f) {

	unsigned long int *ptr = (unsigned long int *)&f;


	unsigned long int mask = 1L << 63;

	for (int i = 0; i < 64; i++) {
		printf("%d", ( *ptr & mask ? 1 : 0));
		mask >>= 1;

		if (i == 0 || i == 11) { printf(" "); } // IEEE 754
	}
}

int main() {


	for (double f = 0.0; f <= 16.0; f += 1.0) {
		printf("%6.1f ", f);
		ftob(f);
		printf("\n");
	}
}
