# Project Euler

- Folders were named as \``ProblemID-ProblemName`\`.
- Problems written in the \``task.md`\` file. (Which is located in the problem folder.)
- All output files were named as \``ans`\`. Therefore, in .gitignore file I ignore them.

- This project uses only C language.
- I. Definitions
```c
#ifndef GIVEN_NUMBER
#define GIVEN_NUMBER value
#endif
```
II. Data types
```c
// In general, we must deal with big numbers.
unsigned long int unsigned_nb;
long int signed_nb;
```

## Notes
```bash
# clears all compiled files. (must be ran under main directory)
rm */ans
```

```bash
# compile source code.
gcc main.c -o ans
```

```bash
# get task content from terminal.
PROJECT_ID=0
curl "https://projecteuler.net/minimal=${PROJECT_ID}" | sed 's/<[^>]*>//g' > task.md
```
