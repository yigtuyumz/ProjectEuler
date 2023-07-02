#include <stdio.h>

#ifndef NB
#define NB 4000000
#endif

unsigned long int task(unsigned long int limit)
{
	unsigned long int iter = 1;
	unsigned long int iter2 = 2;
	unsigned long int temp;
	unsigned long int total = 0;

	while (iter < limit) {
		if (iter2 % 2 == 0) {
			total += iter2;
		}
		temp = iter;
		iter = iter2;
		iter2 += temp;
	}
	return (total);
}

int main(void)
{
	unsigned long int ans = task(NB);
	printf("%lu\n", ans);
	return (0);
}
