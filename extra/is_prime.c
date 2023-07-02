/*
 * applying 6k+-1 theorem.
 */
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
