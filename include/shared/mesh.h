
#ifndef MESH_H
#define MESH_H

#include <assert.h>
#define GLEW_STATIC
#include <GL/glew.h>

#define ASSERT_MESH(mesh) (assert(mesh))

struct mesh {
  GLfloat **vertices;
  
  GLuint vertex_array_object;
  GLuint vertex_buffer_object;
};

struct mesh *mesh_create();
struct mesh *mesh_destroy(struct mesh *mesh);

#endif
