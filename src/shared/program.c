
#include "util.h"
#include "program.h"

struct s_program *program_create() {
  struct s_program *program = MALLOC(sizeof(struct s_program));

  return program;
}

void program_set_args(struct s_program *program, int argc, char *argv[]) {
  ASSERT_PROGRAM(program);

  program->argc = argc;
  program->argv = argv;
}
