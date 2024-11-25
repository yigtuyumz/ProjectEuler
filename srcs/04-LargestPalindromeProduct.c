#include "EulerExtra.h"

/*
 * We're just forcing in here...
 */
unsigned_nb
LargestPalindromeProduct(void)
{
    signed_nb nb1 = 999;
    signed_nb nb2 = 999;
    unsigned_nb mult;
    unsigned_nb biggest = 0;

    while (nb1 >= 100) {
        nb2 = 999;
        while (nb2 >= 100) {
            mult = nb1 * nb2;
            if (is_palindrome(ultoa(mult))) {
                /*
                 * In here, algorithm can be optimised.
                 * But we're dealing numbers with 3 digits.
                 * So the runtime of this program will not be affected too much.
                 */
                if (mult > biggest) {
                    biggest = mult;
                }
            }
            nb2--;
        }
        nb1--;
    }
    return (biggest);
}
