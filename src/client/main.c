
#include "util.h"
#include "program.h"
#include "window.h"

#include "mesh.h"
#include "object.h"

struct object *object;
struct mesh *mesh;

void main_loop(struct program *program) {
  while(!window_should_close(program->window)) {
    window_pre_tick(program->window);
    
    mesh_draw(mesh, object);
    
    window_post_tick(program->window);
  }
  
}

int main(int argc, char *argv[]) {
  struct program *program = program_create();
  
  program_set_args(program, argc, argv);
  program_parse_args(program);

  if(program->help) {
    program_print_help(program);
    program_destroy(program);
    return 0;
  }

  program_open_window(program);

  object = object_create();
  mesh = mesh_create();

  object_set_mesh(object, mesh);

  mesh_set_vertices_triangle(mesh);

  main_loop(program);

  return 0;
}
