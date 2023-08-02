#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// you do have to link it against the math library
// gcc babylonian-method-convergence.c -o binbabylonian-method-convergence -lm && ./binbabylonian-method-convergence

int main() {

	time_t t = time(NULL);
	srandom((unsigned int)t);

	int radicand = (int)(random() % 1000); // (0..1000)
	printf("radicand: %d\n", radicand);

	long estimate = random();
	printf("estimate: %ld\n\n", estimate);


	int step = 1;

	int check = (int) floor(sqrt(radicand));

	for (; estimate != check; step++) {
		estimate = (estimate + radicand/estimate) / 2;
		printf("%ld ", estimate);
	}
	printf("\n\n Convergred in %d steps", step);
}
