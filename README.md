# Project Euler

[ProjectEuler](https://projecteuler.net/) is a platform designed to improve programming skills through mathematical challenges. The problems range in difficulty, starting with easier ones and progressing to much more complex problems that require deeper problem-solving and programming expertise.

As the creators of Project Euler stated, the first 10 questions are publicly available and can be shared freely. However, sharing the questions beyond the first 10 is not appropriate for the following reasons:
- **Ethics**: Without effort, people should not be rewarded. The true reward comes from *hard work* and *discipline*.
- **Spoils**: *Improvement* and *thinking* should never stop, unless one cheats. It is pointless to acquire solutions from external sources or by circumventing the problem-solving process.
- **Use your brain**: Challenge yourself. The real growth happens through problem-solving, not shortcuts.

# Structure
- This project is implemented in **C language**.
- The `./srcs` folder contains the source code files that implement the Project Euler solutions. These are used to create the dynamic library. (libProjectEuler.so)
- The `./tasks` folder contains the problem descriptions. These problem descriptions are directly fetched from the Project Euler website using a script.
```bash
i=1;while [ ${i} -le 10 ]; do curl "https://projecteuler.net/minimal=${i}" | sed 's/<[^>]*>//g' > ./tasks/${i}.md; done; unset i
```

### To build the library:
Before building, ensure you have `gcc` installed. To build the project:

```bash
make all        # Compiles all source code and creates the dynamic library in the current directory
make clean      # Cleans object files and the ./out directory to prepare for a fresh build
make re         # Rebuilds the project (equivalent to "make clean && make all")
```

# Coding Style
This project uses customized GNU Indent settings for consistent code style. You can find the settings used in this project in the following [gist](https://gist.github.com/yigtuyumz/bf5d7313ed5d92a85d8615a2781066dd).

To use this coding style, you can install **GNU Indent** and configure it by following the instructions provided in the [GNU Indent manual](https://www.gnu.org/software/indent/manual/indent.html).

# Using the LibProjectEuler
An example of a program compiled with this library might look like this:
```c
// File: test.c

#include <stdio.h>
// #include "./srcs/ProjectEuler.h"

// indirectly including LibProjectEuler symbols
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

int
main(void)
{
    // You can replace SummationofPrimes() with any other function from the library
    printf("%lu\n", SummationofPrimes());

    return (0);
}
```
To link and compile:
```bash
gcc test.c -L<libProjectEuler.so file location> -lProjectEuler -Wl,-rpath=<libProjectEuler.so file location> -o test
```
