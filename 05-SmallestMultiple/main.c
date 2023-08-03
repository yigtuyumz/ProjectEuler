#include <stdio.h>

unsigned long int
task(unsigned long int step)
{
	unsigned long int nb = 2;
	unsigned long int s2 = (step + 1);

	// we are 'brutally' forcing all of the numbers [2, +inf}
	while (step >= 2) {
		if (nb % step != 0) {
			nb++;
			step = s2;
		}
		step--;
	}
	return (nb);
}

int
main(void)
{
	fprintf(stdout, "%lu\n", task(10));
	return (0);
}

