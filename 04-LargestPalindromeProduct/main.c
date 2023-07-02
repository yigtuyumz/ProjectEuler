#include <stdio.h>
#include <stdlib.h>		// malloc

unsigned long int my_strlen(char *c)
{
	unsigned long int len = 0;
	while (*(c + len++)) ;

	return (--len);
}

unsigned long int my_div(int len)
{
	unsigned long int res = 1;

	while (len != 1) {
		res *= 10;
		len--;
	}

	return (res);
}

int nbr_len(unsigned long int nb)
{
	unsigned int res = 1;

	while (nb > 9) {
		nb /= 10;
		res++;
	}

	return (res);
}

char *ultoa(unsigned long int nb)
{
	char *result;
	int len = nbr_len(nb);
	int len2 = len;

	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == NULL) {
		return (NULL);
	}

	int iter = 0;
	while (iter < len2) {
		result[iter] = ((nb / my_div(len)) % 10) + 48;
		len--;
		iter++;
	}
	result[iter] = '\0';
	return (result);
}

int is_palindrome(char *nb)
{
	unsigned long int f = 0;
	unsigned long int l = my_strlen(nb) - 1;
	unsigned long int iter = 0;
	while (*(nb + (f + iter)) == *(nb + (l - iter)) && (++iter != l)) ;
	return (iter == l);
}

/*
 * We're just forcing here...
 * I am sure that after some calculations, mult is always lesser than the
 * biggest value.
 */
unsigned long int task(void)
{
	int nb1 = 999;
	int nb2 = 999;
	unsigned long int mult;
	unsigned int biggest = 0;
	while (nb1 >= 100) {
		nb2 = 999;
		while (nb2 >= 100) {
			mult = nb1 * nb2;
			if (is_palindrome(ultoa(mult))) {
				if (mult > biggest) {
					biggest = mult;
				}
			}
			nb2--;
		}
		nb1--;
	}
	return (biggest);
}

int main(void)
{
	printf("%lu\n", task());
	return (0);
}
