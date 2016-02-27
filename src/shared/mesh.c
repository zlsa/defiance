
#include "util.h"
#include "mesh.h"

#include <assert.h>

////////////////////////////////////////////////

struct mesh *mesh_create() {
  struct mesh *mesh = MALLOC(sizeof(struct mesh));

  mesh->vertices = NULL;
  mesh->vertex_buffer_object = NULL;

  return mesh;
}

struct mesh *mesh_destroy(struct mesh *mesh) {
  ASSERT_MESH(mesh);

  return FREE(mesh);
}

