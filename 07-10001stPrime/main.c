#include <stdio.h>

#ifndef NTH_PRIME
#define NTH_PRIME 10001
#endif

unsigned long int is_prime(unsigned long int number)
{
	if (number <= 1) {
		return (0);
	}
	if (number <= 3) {
		return (1);
	}
	if (number % 2 == 0 || number % 3 == 0) {
		return (0);
	}
	for (unsigned long int i = 5; i * i <= number; i += 6) {
		if (number % i == 0 || number % (i + 2) == 0) {
			return (0);
		}
	}
	return (1);
}

unsigned long int task(unsigned long int nth)
{
	unsigned long int actual_number = 1;
	while (nth != 0) {
		actual_number++;
		if (is_prime(actual_number)) {
			nth--;
		}
	}

	return (actual_number);
}

int main(void)
{
	printf("%lu", task(NTH_PRIME));
	return (0);
}
