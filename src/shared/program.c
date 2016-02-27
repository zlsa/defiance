
#include "util.h"
#include "program.h"

#include <string.h>

struct s_program *program_create() {
  struct s_program *program = MALLOC(sizeof(struct s_program));

  program->argc = 0;
  program->argv = NULL;

  program->help = false;
  program->extra = NULL;
  program->extra_number = 0;

  return program;
}

struct s_program *program_free(struct s_program *program) {
  ASSERT_PROGRAM(program);

  while(program->extra_number) {
    program->extra[program->extra_number--] = FREE(program->extra[program->extra_number--]);
  }

  return FREE(program);
}

void program_print_help(struct s_program *program) {
  printf("Usage: %s [OPTIONS]\n", program->argv[0]);
  printf("Options:\n");
  printf(" -h --help              Display this help\n");
}

// ARGS

void program_set_args(struct s_program *program, int argc, char *argv[]) {
  ASSERT_PROGRAM(program);

  program->argc = argc;
  program->argv = argv;
}

void program_parse_args(struct s_program *program) {
  ASSERT_PROGRAM(program);

  if(program->extra) {
    util_log(0, "program_parse_args() has already been called! Returning.");
    return;
  }

  int argc = program->argc;
  char **argv = program->argv;

  int i, arg_len, next_len;
  int next_used;
  char *arg;
  char *next;

  program->extra = MALLOC(sizeof(char *) * PROGRAM_ARGS_MAX_EXTRA);

  for(i=1; i<argc; i++) {
    next = NULL;
      
    arg = argv[i];
    arg_len = strlen(arg);

    next_used = false;
    
    if(i < (argc-1)) {
      next = argv[i+1];
      next_len = strlen(next);
      if(next_len >= 2 && next[0] == '-')
        next = NULL;
    }
    
    if(arg_len >= 2 && arg[0] == '-' && arg[1] != '-') {
      next_used = program_parse_short_args(program, arg, next);
    } else if(arg_len >= 3 && arg[0] == '-' && arg[1] == '-') {
      next_used = program_parse_long_arg(program, arg+2, next);
    } else {
      // use next as a temporary variable
      next = MALLOC(arg_len+1);
      strncpy(next, arg, arg_len+1);
      program->extra[program->extra_number] = next;
    }

    if(next_used) {
      i++;
    }

  }

}

bool program_parse_short_arg(struct s_program *program, char arg, char *value) {
  ASSERT_PROGRAM(program);

  switch(arg) {
  case 'h':
    program->help = true;
    break;
  }

  return false;
}

bool program_parse_short_args(struct s_program *program, char *args, char *value) {
  ASSERT_PROGRAM(program);

  int i=0;
  char c;

  while(c=args[++i]) {
    if(args[i+1] == '\0')
      return program_parse_short_arg(program, c, value);
    program_parse_short_arg(program, c, NULL);
  }

  return false;
  
}

bool program_parse_long_arg(struct s_program *program, char *arg, char *value) {
  ASSERT_PROGRAM(program);

  int arg_len = strlen(arg);

  if(strncmp(arg, "help", arg_len) == 0) {
    program->help = true;
  }

  return false;
}
