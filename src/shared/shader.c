
#include "util.h"
#include "shader.h"

#include <assert.h>

////////////////////////////////////////////////

struct shader *shader_create() {
  struct shader *shader = MALLOC(sizeof(struct shader));

  shader->shader = -1;

  shader->shader_number = 0;

  return shader;
}

struct shader *shader_destroy(struct shader *shader) {
  ASSERT_SHADER(shader);

  assert(shader->shader_number == 0);

  return FREE(shader);
}

////////////////////////////////////////////////

struct shader_program *shader_program_create() {
  struct shader_program *shader_program = MALLOC(sizeof(struct shader_program));

  shader_program->vs = NULL;
  shader_program->fs = NULL;

  shader_program->shader_program = -1;

  shader_program->object_number = 0;

  return shader_program;
}

struct shader_program *shader_program_destroy(struct shader_program *shader_program) {
  ASSERT_SHADER_PROGRAM(shader_program);

  assert(shader_program->object_number == 0);

  return FREE(shader_program);
}

////////////////////////////////////////////////

void shader_program_add_object(struct shader_program *shader_program) {
  ASSERT_SHADER_PROGRAM(shader_program);

  shader_program->object_number += 1;
}

void shader_program_remove_object(struct shader_program *shader_program) {
  ASSERT_SHADER_PROGRAM(shader_program);

  shader_program->object_number -= 1;
}

