
#ifndef OBJECT_H
#define OBJECT_H

#include <assert.h>
#include <stdbool.h>
#include "linmath.h"

#define ASSERT_OBJECT(object) (assert(object))

struct s_object {
  mat4x4 local_matrix;
  mat4x4 world_matrix;

  vec4 position;
  quat rotation;
};

struct s_object *object_create();
struct s_object *object_free(struct s_object *object);

#endif
