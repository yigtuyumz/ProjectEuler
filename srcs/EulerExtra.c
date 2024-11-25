#include "ProjectEuler.h"

/*
 * applying 6k+-1 theorem.
 */
unsigned_nb
is_prime(unsigned_nb number)
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

    for (unsigned_nb i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return (0);
        }
    }

    return (1);
}

unsigned_nb
my_strlen(const char *c)
{
    unsigned_nb len = 0;

    while (*(c + len++));

    return (--len);
}

unsigned_nb
pow_ten(signed_nb len)
{
    unsigned_nb res = 1;

    while (len >= 1) {
        res *= 10;
        len--;
    }
    return (res);
}

signed_nb
digitcount(unsigned_nb nb)
{
    signed_nb res = 1;

    while (nb > 9) {
        nb /= 10;
        res++;
    }

    return (res);
}

/*
 * What i have done.. :((((
 * Previously, i allocated memory (without free'ing it!!!)
 * for the stringified number value...
 * Who cares dynamic memory for this project??
 * Now it is for free, using a static char pointer...
 * 
 * What a shame!
 */
char *
ultoa(unsigned_nb nb)
{
    static char result[21] = { 0 };     /* clean previously inserted values */
    signed_nb len = digitcount(nb);
    signed_nb len2 = len;
    signed_nb iter = 0;

    while (iter < len2) {
        result[iter++] = ((nb / pow_ten(--len)) % 10) + 48;
    }

    return (result);
}

signed_nb
is_palindrome(const char *nb)
{
    unsigned_nb f = 0;
    unsigned_nb l = my_strlen(nb) - 1;
    unsigned_nb iter = 0;

    // NOLINTBEGIN clang-analyzer-core.UndefinedBinaryOperatorResult
    /*
     * This loop is running for static values.
     */
    while (*(nb + (f + iter)) == *(nb + (l - iter)) && (++iter != l));
    // NOLINTEND clang-analyzer-core.UndefinedBinaryOperatorResult
    return (iter == l);
}

unsigned_nb
square(unsigned_nb nb)
{
    return (nb * nb);
}

unsigned_nb
chartodigit(const char *c)
{
    return (*c - 48);
}

unsigned_nb
exponential(unsigned_nb base, unsigned_nb exp)
{
    unsigned_nb r = 1;

    /* These two if statements are for optimization. */
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
