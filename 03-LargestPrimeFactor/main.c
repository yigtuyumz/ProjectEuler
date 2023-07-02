#include <stdio.h>

#ifndef NB
#define NB 600851475143
#endif

unsigned long int task(unsigned long int nb)
{
	unsigned long int factor;
	while (nb != 1) {
		factor = 2;	// smallest prime factor
		while (nb % factor != 0) {
			factor++;
		}
		nb /= factor;
	}

	return (factor);
}

int main(void)
{
	unsigned long int ans = task(NB);
	printf("%lu\n", ans);
	return (0);
}
