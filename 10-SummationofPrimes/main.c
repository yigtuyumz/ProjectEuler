#include <stdio.h>
#include <pthread.h>

#ifndef TWO_MILLION
#define TWO_MILLION 2000000
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

unsigned long int task(unsigned long int limit)
{
	unsigned long int counter = 1;
	unsigned long int nb = 2;
	while (counter <= limit) {
		if (is_prime(counter)) {
			nb += counter;
		}
		counter += 2;
	}
	return (nb);
}

int main(void)
{
	printf("%lu\n", task(TWO_MILLION));
	return (0);
}
