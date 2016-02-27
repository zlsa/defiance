
#ifndef PROGRAM_H
#define PROGRAM_H

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "window.h"

#define ASSERT_PROGRAM(program) (assert(program))
#define PROGRAM_ARGS_MAX_EXTRA (32)

struct s_program {
  int argc;
  char **argv;

  bool help;
  
  int extra_number;
  char **extra;

  bool glfw_initialized;
  struct s_window *window;
};

struct s_program *program_create();
struct s_program *program_destroy(struct s_program *program);
void program_exit(struct s_program *program, int status);

void program_print_help(struct s_program *program);

void program_set_args(struct s_program *program, int argc, char *argv[]);

void program_parse_args(struct s_program *program);
bool program_parse_short_arg(struct s_program *program, char arg, char *value);
bool program_parse_short_args(struct s_program *program, char *args, char *value);
bool program_parse_long_arg(struct s_program *program, char *arg, char *value);

void program_short_arg_invalid(struct s_program *program, char arg);
void program_long_arg_invalid(struct s_program *program, char *arg);

void program_open_window(struct s_program *program);

#endif
