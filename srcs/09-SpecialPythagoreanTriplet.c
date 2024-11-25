#include "EulerExtra.h"

/*
 * If condition is not met, returns 0.
 */
unsigned_nb
SpecialPythagoreanTriplet(void)
{
    unsigned_nb a = 0;
    unsigned_nb b = 0;
    unsigned_nb c = 0;

    while (a <= 1000) {
        b = 0;
        while (b <= 1000) {
            c = 0;
            while (c <= 1000) {
                if (((a + b + c) == 1000)
                    && ((square(a) + square(b))
                        == square(c)) && ((a < b)
                                          && (b < c))) {
                    return (a * b * c);
                }
                c++;
            }
            b++;
        }
        a++;
    }

    return (0);
}
