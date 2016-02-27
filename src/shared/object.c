
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

  return object;
}

struct object *object_destroy(struct object *object) {
  ASSERT_OBJECT(object);

  return FREE(object);
}

