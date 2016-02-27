
#ifndef SHADER_H
#define SHADER_H

#include <assert.h>
#include <stdbool.h>
#define GLEW_STATIC
#include <GL/glew.h>

#define ASSERT_SHADER(shader) (assert(shader))
#define ASSERT_SHADER_PROGRAM(shader) (assert(shader))

struct shader {
  GLuint shader;
  
  int shader_number;
};

struct shader_program {
  struct shader *fs;
  struct shader *vs;
  
  GLuint shader_program;
  
  int object_number;
};

struct shader *shader_create();
struct shader *shader_destroy(struct shader *shader);

struct shader_program *shader_program_create();
struct shader_program *shader_program_destroy(struct shader_program *shader);

void shader_program_add_object(struct shader_program *shader_program);
void shader_program_remove_object(struct shader_program *shader_program);

#endif
