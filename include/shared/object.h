
#ifndef OBJECT_H
#define OBJECT_H

#include <assert.h>
#include "mesh.h"
#include "linmath.h"

#define ASSERT_OBJECT(object) (assert(object))

struct object {
  mat4x4 local_matrix;
  mat4x4 world_matrix;

  vec4 position;
  quat rotation;

  struct object *parent;
  
  int children_length;
  struct object **children;

  struct mesh *mesh;
};

struct object *object_create();
struct object *object_destroy(struct object *object);

void object_set_mesh(struct object *object, struct mesh *mesh);

#endif
