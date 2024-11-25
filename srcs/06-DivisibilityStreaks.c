#include "EulerExtra.h"

unsigned_nb
DivisibilityStreaks(void)
{
#ifdef NB
# undef NB
#endif
#define NB 100

    unsigned_nb step = NB;
    unsigned_nb sum_natural = 0;
    unsigned_nb sum_square = 0;

    while (step != 0) {
        sum_square += square(step);
        sum_natural += step;
        step--;
    }

    return (square(sum_natural) - sum_square);
}
