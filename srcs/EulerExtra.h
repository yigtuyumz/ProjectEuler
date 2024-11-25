#ifndef EULER_EXTRA
# define EULER_EXTRA

# include "ProjectEuler.h"

/*
 * Gets a digit from using the ASCII table.
 */
unsigned_nb chartodigit(const char *c);

/*
 * Returns the digit count of a number. (maximum 20 due to 64 bit value limit)
 */
signed_nb digitcount(unsigned_nb nb);

/*
 * Calculates (base^exp) value.
*/
unsigned_nb exponential(unsigned_nb base, unsigned_nb exp);

/*
 * Checks a value is palindrome or not.
 * If it is, returns 1,
 * otherwise returns 0.
 */
signed_nb is_palindrome(const char *nb);

/*
 * applies 6k+-1 theorem.
 */
unsigned_nb is_prime(unsigned_nb number);

/*
 * Returns the count of characters in a string.
 */
unsigned_nb my_strlen(const char *c);

/*
 * Returns 10 ^ len
 */
unsigned_nb pow_ten(signed_nb len);

/*
 * Returns the square of a positive integer.
 */
unsigned_nb square(unsigned_nb nb);

/*
 * Converts an unsigned_nb to the string.
 */
char *ultoa(unsigned_nb nb);

#endif /* ! EULER_EXTRA */
