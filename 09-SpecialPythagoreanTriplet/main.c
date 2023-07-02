#include <stdio.h>

unsigned long int exponential(unsigned long int base, unsigned long int exp)
{
	unsigned long int r = 1;
	/*
	 * These two if statements, is for optimisation.
	 */
	if (base == 1 && exp > 0) {
		return (r);
	}
	if (base == 0 && exp > 0) {
		return (0);
	}

	while (exp-- != 0) {
		r *= base;
	}

	return (r);
}

/*
 * If condition is not met, returns 0.
 */
unsigned long int task(void)
{
	unsigned long int a = 0;
	unsigned long int b = 0;
	unsigned long int c = 0;
	while (a <= 1000) {
		b = 0;
		while (b <= 1000) {
			c = 0;
			while (c <= 1000) {
				if (((a + b + c) == 1000)
				    && ((exponential(a, 2) + exponential(b, 2))
					== exponential(c, 2)) && ((a < b)
								  && (b < c))) {
					return (a * b * c);
				}
				c++;
			}
			b++;
		}
		a++;
	}
	return (0);
}

int main(void)
{
	fprintf(stdout, "%lu\n", task());
	return (0);
}
