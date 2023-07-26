# Project Euler

- Folders are named as `ProblemID-ProblemName`.
- Problems written in the `task.md` file. (Which is located in the problem folder.)
- All output files were named as `ans`. Therefore, in .gitignore file I ignore them.

- This project uses only C language.

I. Definitions
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
III. Coding Style
```bash
# I am using indent. Indent is a powerful code refactoring tool for C/C++ language.
# In this project, I preferred Linux style. I created an alias for ease of using.
alias indent='indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce
-ci4 -cli0 -d0 -di1 -nfc1 -i8 -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw
-ncs -nsc -sob -nfca -cp33 -ss -ts8 -il1'
```
[Visit](https://www.gnu.org/software/indent/manual/indent/Common-styles.html) for more styles.


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

```bash
# List all c files.
ls */*.c | awk '{print $1}'
```
