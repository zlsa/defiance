
#include "util.h"
#include "object.h"

#include <assert.h>

////////////////////////////////////////////////

struct s_object *object_create() {
  struct s_object *object = MALLOC(sizeof(struct s_object));

  mat4x4_identity(object->local_matrix);
  mat4x4_identity(object->world_matrix);
  
  vec4_reset(object->position);
  quat_identity(object->rotation);

  return object;
}

struct s_object *object_free(struct s_object *object) {
  ASSERT_OBJECT(object);

  return FREE(object);
}

