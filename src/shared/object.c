
#include "util.h"
#include "object.h"

#include <assert.h>

////////////////////////////////////////////////

struct object *object_create() {
  struct object *object = MALLOC(sizeof(struct object));

  mat4x4_identity(object->local_matrix);
  mat4x4_identity(object->world_matrix);
  
  vec4_reset(object->position);
  quat_identity(object->rotation);

  object->parent = NULL;

  object->children_length = 0;
  object->children = NULL;

  object->mesh = NULL;

  return object;
}

struct object *object_destroy(struct object *object) {
  ASSERT_OBJECT(object);

  return FREE(object);
}

////////////////////////////////////////////////

void object_set_mesh(struct object *object, struct mesh *mesh) {
  ASSERT_OBJECT(object);

  assert(!object->mesh);

  object->mesh = mesh;

  mesh_add_object(mesh);
}

