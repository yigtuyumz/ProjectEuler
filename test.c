/* #include "./srcs/ProjectEuler.h" */
#include <stdio.h>

extern unsigned long int Multiples3or5(void);
extern unsigned long int EvenFibonacciNumbers(void);
extern unsigned long int LargestPrimeFactor(void);
extern unsigned long int LargestPalindromeProduct(void);
extern unsigned long int SmallestMultiple(void);
extern unsigned long int DivisibilityStreaks(void);
extern unsigned long int _10001stPrime(void);
extern unsigned long int LargestProductinaSeries(void);
extern unsigned long int SpecialPythagoreanTriplet(void);
extern unsigned long int SummationofPrimes(void);

void
test_case(unsigned long int (*callback)(void), unsigned long int expected, const char *fname)
{
    unsigned long int val = callback();
    int result = (val == expected);

    if (result) {
        printf("[ PASS ] %s\n", fname);
    } else {
        printf("[ FAIL ] Expected: %lu, Given: %lu\n", expected, val);
    }
}

int
main(void)
{
    test_case(Multiples3or5, 233168, "Multiples3or5");
    test_case(EvenFibonacciNumbers, 4613732, "EvenFibonacciNumbers");
    test_case(LargestPrimeFactor, 6857, "LargestPrimeFactor");
    test_case(LargestPalindromeProduct, 906609, "LargestPalindromeProduct");
    test_case(SmallestMultiple, 232792560, "SmallestMultiple");
    test_case(DivisibilityStreaks, 25164150, "DivisibilityStreaks");
    test_case(_10001stPrime, 104743, "_10001stPrime");
    test_case(LargestProductinaSeries, 23514624000, "LargestProductinaSeries");
    test_case(SpecialPythagoreanTriplet, 31875000, "SpecialPythagoreanTriplet");
    test_case(SummationofPrimes, 142913828922, "SummationofPrimes");

    return (0);
}
