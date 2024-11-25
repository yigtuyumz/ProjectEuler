#include "ProjectEuler.h"

unsigned_nb
SmallestMultiple(void)
{
#ifdef NB
# undef NB
#endif
#define NB 20

    unsigned_nb step = NB;
    unsigned_nb nb = 2;
    unsigned_nb s2 = (step + 1);

    /* we are 'brutally' forcing all of the numbers [2, +inf} */
    while (step >= 2) {
        if (nb % step != 0) {
            nb++;
            step = s2;
        }

        step--;
    }

    return (nb);
}
