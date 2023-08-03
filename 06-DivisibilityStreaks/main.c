#include <stdio.h>

#ifndef FIRST_N
#define FIRST_N 100
#endif

unsigned long int
square(unsigned long int nb)
{
	return (nb * nb);
}

unsigned long int
task(unsigned long int step)
{
	unsigned long int sum_natural = 0;
	unsigned long int sum_square = 0;

	while (step != 0) {
		sum_square += square(step);
		sum_natural += step;
		step--;
	}
	return (square(sum_natural) - sum_square);
}

int
main(void)
{
	fprintf(stdout, "%lu\n", task(FIRST_N));
	return (0);
}

