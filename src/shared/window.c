
#include "util.h"
#include "window.h"

#include <assert.h>

bool window_init() {
  glewExperimental = GL_TRUE;
  return glfwInit() && glewInit();
}

bool window_terminate() {
  glfwTerminate();
}

////////////////////////////////////////////////

struct s_window *window_create() {
  struct s_window *window = MALLOC(sizeof(struct s_window));

  window->width = 640;
  window->height = 480;
  window->title = "Defiance Client";

  window->window = NULL;
  window->open = false;

  return window;
}

struct s_window *window_free(struct s_window *window) {
  ASSERT_WINDOW(window);

  return FREE(window);
}

////////////////////////////////////////////////

bool window_open(struct s_window *window) {
  ASSERT_WINDOW(window);

  assert(!window->open);

  window->window = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);

  if(window->window) {
    glfwMakeContextCurrent(window->window);
    window->open = true;
    glClearColor(0.0, 1.0, 0.0, 1.0);
  }

  return window->window;
}

////////////////////////////////////////////////

bool window_should_close(struct s_window *window) {
  ASSERT_WINDOW(window);

  assert(window->open);
  
  return glfwWindowShouldClose(window->window);
}

////////////////////////////////////////////////

void window_pre_tick(struct s_window *window) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void window_post_tick(struct s_window *window) {
  glfwSwapBuffers(window->window);
  glfwPollEvents();
}
