
#include "program.h"

struct s_program *program;

int main(int argc, char *argv[]) {
  program = program_create();
  
  program_set_args(program, argc, argv);

  return(0);
}
