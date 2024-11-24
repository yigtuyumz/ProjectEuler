# Project Euler

- Folders are named as `ProblemID-ProblemName`.
- Each problem is written in the `task.md` file. (Which is located in the same folder.)
- All output files have the same name as the folder name.

- This project uses only C language.

## Build
This project uses CMake 3.10 (or above). Run `./build.sh` file to build all problems in the project.

## Definitions
```c
#ifndef GIVEN_NUMBER
#define GIVEN_NUMBER value
#endif
```
## Data Types
```c
// In general, we must deal with big numbers.
unsigned long int unsigned_nb;
long int signed_nb;
```
## Coding Style
I am using _[customized](https://gist.github.com/yigtuyumz/bf5d7313ed5d92a85d8615a2781066dd)_ GNU Indent settings for the code style in this project.
Refer to the [documentation](https://www.gnu.org/software/indent/manual/indent/Common-styles.html) for more styles.

## Notes

```bash
# get task content from terminal.
PROJECT_ID=0
curl "https://projecteuler.net/minimal=${PROJECT_ID}" | sed 's/<[^>]*>//g' > task.md
```

```bash
# List all source files.
ls */*.c | awk '{print $1}'
```
