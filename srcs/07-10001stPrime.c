#include "EulerExtra.h"

unsigned_nb
_10001stPrime(void)
{
#ifdef NB
# undef NB
#endif
#define NB 10001

    unsigned_nb nth = NB;
    unsigned_nb actual_number = 1;

    while (nth != 0) {
        actual_number++;
        if (is_prime(actual_number)) {
            nth--;
        }
    }

    return (actual_number);
}
