#include "EulerExtra.h"

unsigned_nb
SummationofPrimes(void)
{
#undef NB
#define NB 2000000

    unsigned_nb counter = 1;
    unsigned_nb nb = 2;

    while (counter <= NB) {
        if (is_prime(counter)) {
            nb += counter;
        }
        counter += 2;
    }

    return (nb);
}
