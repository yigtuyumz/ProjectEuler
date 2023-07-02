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
