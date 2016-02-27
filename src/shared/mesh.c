
#include "util.h"
#include "mesh.h"

#include <assert.h>

////////////////////////////////////////////////

struct mesh *mesh_create() {
  struct mesh *mesh = MALLOC(sizeof(struct mesh));

  mesh->vertex_array_object = -1;
  mesh->vertex_buffer_object = -1;

  mesh->object_number = 0;

  return mesh;
}

struct mesh *mesh_destroy(struct mesh *mesh) {
  ASSERT_MESH(mesh);

  assert(mesh->object_number == 0);

  return FREE(mesh);
}

////////////////////////////////////////////////

void mesh_add_object(struct mesh *mesh) {
  ASSERT_MESH(mesh);

  mesh->object_number += 1;
}

void mesh_remove_object(struct mesh *mesh) {
  ASSERT_MESH(mesh);

  mesh->object_number -= 1;
}

////////////////////////////////////////////////

bool mesh_set_vertices(struct mesh *mesh, float *vertices) {
  ASSERT_MESH(mesh);

  GLuint i;
  if(mesh->vertex_buffer_object == -1) {
    glGenBuffers(1, &mesh->vertex_buffer_object);
  }

  if(mesh->vertex_array_object == -1) {
    glGenVertexArrays(1, &mesh->vertex_array_object);
  }

  glBindVertexArray(mesh->vertex_array_object);
  glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer_object);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  return true;
}

////////////////////////////////////////////////

bool mesh_set_vertices_triangle(struct mesh *mesh) {
  ASSERT_MESH(mesh);

  float vertices[] = {
    0.0f,  0.5f,
    0.5f, -0.5f,
    -0.5f, -0.5f
  };

  return mesh_set_vertices(mesh, vertices);
}

////////////////////////////////////////////////

void mesh_draw(struct mesh *mesh, struct object *object) {
  ASSERT_MESH(mesh);
  ASSERT_OBJECT(object);

  glBindVertexArray(mesh->vertex_array_object);
  glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer_object);

  glDrawArrays(GL_TRIANGLES, 0, 3);
}
