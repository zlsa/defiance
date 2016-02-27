
#ifndef MESH_H
#define MESH_H

#include <assert.h>
#include <stdbool.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include "object.h"

struct object;

#define ASSERT_MESH(mesh) (assert(mesh))

struct mesh {
  GLuint vertex_array_object;
  GLuint vertex_buffer_object;
  
  int object_number;
};

struct mesh *mesh_create();
struct mesh *mesh_destroy(struct mesh *mesh);

void mesh_add_object(struct mesh *mesh);
void mesh_remove_object(struct mesh *mesh);

bool mesh_set_vertices(struct mesh *mesh, float *vertices);
bool mesh_set_vertices_triangle(struct mesh *mesh);

void mesh_draw(struct mesh *mesh, struct object *object);

#endif
