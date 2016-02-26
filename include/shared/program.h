
#ifndef PROGRAM_H
#define PROGRAM_H

#include <assert.h>

#define ASSERT_PROGRAM(program) (assert(program))

struct s_program {
  int argc;
  char **argv;
};

struct s_program *program_create();
void program_set_args(struct s_program *program, int argc, char *argv[]);

#endif
