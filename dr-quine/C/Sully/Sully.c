int i = 5;

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define EXECUTE(exec, ...) { int pid = fork(); if (pid == -1) { perror("fork"); } else if (pid == 0) { execlp(exec, __VA_ARGS__); perror(exec); exit(1); } else { waitpid(pid, NULL, 0); } }

/*
  This program will print its own source when run.
*/

static char source_filename[10];
static char executable_filename[8];

static void setup_filename();
static void setup_source_filename();
static void setup_executable_filename();

static void create_sully();
static void compile_sully();
static void execute_sully();

int main(void) {
  /*
    This program will print its own source when run.
  */
  if (i > 0) {
    setup_filename();
    create_sully();
    compile_sully();
  }
  if (i > 1) {
    execute_sully();
  }
  return 0;
}

static void setup_filename() {
  setup_source_filename();
  setup_executable_filename();
}

static void setup_source_filename() {
  strcpy(source_filename, "Sully_");
  source_filename[6] = '0' + i - 1;
  strcpy(source_filename + 7, ".c");
}

static void setup_executable_filename() {
  strcpy(executable_filename, "Sully_");
  executable_filename[6] = '0' + i - 1;
}

static void create_sully() {
  int fd = open(source_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  char source[] = "int i = %d;%c%c#include <stdio.h>%c#include <unistd.h>%c#include <fcntl.h>%c#include <string.h>%c#include <stdlib.h>%c#include <sys/wait.h>%c%c#define EXECUTE(exec, ...) { int pid = fork(); if (pid == -1) { perror(%cfork%c); } else if (pid == 0) { execlp(exec, __VA_ARGS__); perror(exec); exit(1); } else { waitpid(pid, NULL, 0); } }%c%c/*%c  This program will print its own source when run.%c*/%c%cstatic char source_filename[10];%cstatic char executable_filename[8];%c%cstatic void setup_filename();%cstatic void setup_source_filename();%cstatic void setup_executable_filename();%c%cstatic void create_sully();%cstatic void compile_sully();%cstatic void execute_sully();%c%cint main(void) {%c  /*%c    This program will print its own source when run.%c  */%c  if (i > 0) {%c    setup_filename();%c    create_sully();%c    compile_sully();%c  }%c  if (i > 1) {%c    execute_sully();%c  }%c  return 0;%c}%c%cstatic void setup_filename() {%c  setup_source_filename();%c  setup_executable_filename();%c}%c%cstatic void setup_source_filename() {%c  strcpy(source_filename, %cSully_%c);%c  source_filename[6] = '0' + i - 1;%c  strcpy(source_filename + 7, %c.c%c);%c}%c%cstatic void setup_executable_filename() {%c  strcpy(executable_filename, %cSully_%c);%c  executable_filename[6] = '0' + i - 1;%c}%c%cstatic void create_sully() {%c  int fd = open(source_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c  char source[] = %c%s%c;%c  dprintf(fd, source, i - 1, 012, 012, 012, 012, 012, 012, 012, 012, 012, 042, 042, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 042, 042, 012, 012, 042, 042, 012, 012, 012, 012, 042, 042, 012, 012, 012, 012, 012, 012, 042, source, 042, 012, 012, 012, 012, 012, 012, 042, 042, 042, 042, 042, 042, 042, 042, 042, 042, 042, 042, 012, 012, 012, 012, 012, 012, 042, 042, 012, 012, 012, 012);%c  close(fd);%c}%c%cstatic void compile_sully() {%c  EXECUTE(%ccc%c, %ccc%c, %c-Wall%c, %c-Wextra%c, %c-Werror%c, source_filename, %c-o%c, executable_filename, NULL);%c}%c%cstatic void execute_sully() {%c  char executable_path[10] = {0, };%c%c  strcpy(executable_path, %c./%c);%c  strcpy(executable_path + 2, executable_filename);%c  EXECUTE(executable_path, executable_filename, NULL);%c}%c";
  dprintf(fd, source, i - 1, 012, 012, 012, 012, 012, 012, 012, 012, 012, 042, 042, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 012, 042, 042, 012, 012, 042, 042, 012, 012, 012, 012, 042, 042, 012, 012, 012, 012, 012, 012, 042, source, 042, 012, 012, 012, 012, 012, 012, 042, 042, 042, 042, 042, 042, 042, 042, 042, 042, 042, 042, 012, 012, 012, 012, 012, 012, 042, 042, 012, 012, 012, 012);
  close(fd);
}

static void compile_sully() {
  EXECUTE("cc", "cc", "-Wall", "-Wextra", "-Werror", source_filename, "-o", executable_filename, NULL);
}

static void execute_sully() {
  char executable_path[10] = {0, };

  strcpy(executable_path, "./");
  strcpy(executable_path + 2, executable_filename);
  EXECUTE(executable_path, executable_filename, NULL);
}
