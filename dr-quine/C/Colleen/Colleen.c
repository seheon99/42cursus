#include <stdio.h>

/*
  This program will print its own source when run.
*/

static void print_source(void) {
  char source[] = "#include <stdio.h>%c%c/*%c  This program will print its own source when run.%c*/%c%cstatic void print_source(void) {%c  char source[] = %c%s%c;%c  printf(source, 10, 10, 10, 10, 10, 10, 10, 34, source, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);%c}%c%cint main(void) {%c  /*%c    This program will print its own source when run.%c  */%c  print_source();%c  return (0);%c}%c";
  printf(source, 10, 10, 10, 10, 10, 10, 10, 34, source, 34, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
}

int main(void) {
  /*
    This program will print its own source when run.
  */
  print_source();
  return (0);
}
