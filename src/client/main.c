
#include "util.h"
#include "program.h"
#include "window.h"

void main_loop(struct s_program *program) {
  while(!window_should_close(program->window)) {
    window_pre_tick(program->window);
    
    window_post_tick(program->window);
  }
  
}

int main(int argc, char *argv[]) {
  struct s_program *program = program_create();
  
  program_set_args(program, argc, argv);
  program_parse_args(program);

  if(program->help) {
    program_print_help(program);
    program_destroy(program);
    return 0;
  }

  program_open_window(program);

  main_loop(program);

  return 0;
}
