#include "ProjectEuler.h"

unsigned_nb
EvenFibonacciNumbers(void)
{
#undef NB
#define NB 4000000

    unsigned_nb temp;
    unsigned_nb iter = 1;
    unsigned_nb iter2 = 2;
    unsigned_nb total = 0;

    while (iter < NB) {
        if (iter2 % 2 == 0) {
            total += iter2;
        }

        temp = iter;
        iter = iter2;
        iter2 += temp;
    }

    return (total);
}
