#include "ProjectEuler.h"

unsigned_nb
LargestPrimeFactor(void)
{
#ifdef NB
# undef NB
#endif
#define NB 600851475143

    unsigned_nb factor = 0;
    unsigned_nb nb = NB;

    while (nb != 1) {
        factor = 2;             /* smallest prime factor */
        while (nb % factor != 0) {
            factor++;
        }

        nb /= factor;
    }

    return (factor);
}
