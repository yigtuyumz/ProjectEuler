#include "ProjectEuler.h"

unsigned_nb
Multiples3or5(void)
{
#ifdef NB
# undef NB
#endif
#define NB 1000

    unsigned_nb total = 0;
    unsigned_nb iter = 1;

    while (iter < NB) {
        if (iter % 5 == 0 || iter % 3 == 0) {
            total += iter;
        }
        iter++;
    }

    return (total);
}
