
#include "program.h"

struct s_program *program;

int main(int argc, char *argv[]) {
  program = program_create();
  
  program_set_args(program, argc, argv);
  program_parse_args(program);

  if(program->help) {
    program_print_help(program);
    program = program_free(program);
    return 0;
  }

  return 0;
}
