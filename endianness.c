#include <stdio.h>

union test {
	int i;
	char c[sizeof(int)];
};

int main() {

	union test t;
	t.i = 1;

	if (t.c[0] & 1) {
		printf("Little endian\n");
	} else {
		printf("Big endian\n");
	}
}
