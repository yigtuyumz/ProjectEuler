#include <stdio.h>

#ifndef NB
#define NB 1000
#endif

unsigned int task(int limit)
{
	unsigned int total = 0;
	for (int i = 1; i < limit; i++) {
		if (i % 5 == 0 || i % 3 == 0) {
			total += i;
		}
	}
	return (total);
}

int main(void)
{
	unsigned int ans = task(NB);
	printf("%u\n", ans);
	return (0);
}
