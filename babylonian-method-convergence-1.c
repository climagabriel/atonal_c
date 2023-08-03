#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// original inspiration: http://www.azillionmonkeys.com/qed/sqroot.html
// you do have to link it against the math library
// gcc babylonian-method-convergence.c -o binbabylonian-method-convergence -lm && ./binbabylonian-method-convergence
//
// TODO: step until you reach the float precision limit

int main() {

	time_t t = time(NULL);
	srandom((unsigned int)t);

	float radicand = (float)(random() % 1000); // (0..1000).6
	printf("radicand: %f\n", radicand);

	float estimate = (float)random(); // ridicilously wrong estimate
	printf("estimate: %f\n", estimate);

	int step = 1;

	float epsi = 0.000001;
	float error = (estimate * estimate) - radicand;

	for (; error > epsi; step++) {
		estimate = (estimate + radicand/estimate) / 2;
		error = (estimate * estimate) - radicand;
		printf("%f ", error);
	}
	printf("\n\n Convergred in %d steps", step);
}
