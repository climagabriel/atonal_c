#include <stdio.h>

int main() {

	unsigned long long int a = 1L;

	printf ("%.326lf\n", *(double*)&a);
}
