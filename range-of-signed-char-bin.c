#include <stdio.h>

int main() {

	signed char c = 0x00;
	for (int i = 0; i < 257; i++) {

		char mask = 1;
		printf("%d ", c);
		for (int l = 0; l < 8; l++) {
			printf("%d", c & mask ? 1 : 0);
			mask <<= 1; //assumes Little Endian architecture
		}
		printf("\n");
		c++;
	}
}

