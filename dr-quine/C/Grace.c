#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define SOURCE "#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c#define SOURCE %c%s%c%c#define PRINT(x, ...) { int fd = open(%cGrace_kid.c%c, O_WRONLY | O_CREAT | O_TRUNC, 0644); dprintf(fd, x, __VA_ARGS__); close(fd); }%c#define MAIN int main(void) { PRINT(SOURCE, 10, 10, 10, 34, SOURCE, 34, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10) return (0); }%c%c/*%c  This program will print its own source when run.%c*/%c%cMAIN%c"
#define PRINT(x, ...) { int fd = open("Grace_kid.c", O_WRONLY | O_CREAT | O_TRUNC, 0644); dprintf(fd, x, __VA_ARGS__); close(fd); }
#define MAIN int main(void) { PRINT(SOURCE, 10, 10, 10, 34, SOURCE, 34, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10, 10) return (0); }

/*
  This program will print its own source when run.
*/

MAIN
