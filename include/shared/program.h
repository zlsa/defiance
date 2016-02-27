
#ifndef PROGRAM_H
#define PROGRAM_H

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "window.h"

#define ASSERT_PROGRAM(program) (assert(program))
#define PROGRAM_ARGS_MAX_EXTRA (32)

struct program {
  int argc;
  char **argv;

  bool help;
  
  int extra_number;
  char **extra;

  bool glfw_initialized;
  struct window *window;
};

struct program *program_create();
struct program *program_destroy(struct program *program);
void program_exit(struct program *program, int status);

void program_print_help(struct program *program);

void program_set_args(struct program *program, int argc, char *argv[]);

void program_parse_args(struct program *program);
bool program_parse_short_arg(struct program *program, char arg, char *value);
bool program_parse_short_args(struct program *program, char *args, char *value);
bool program_parse_long_arg(struct program *program, char *arg, char *value);

void program_short_arg_invalid(struct program *program, char arg);
void program_long_arg_invalid(struct program *program, char *arg);

void program_open_window(struct program *program);

#endif
