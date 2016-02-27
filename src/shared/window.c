
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

struct window *window_create() {
  struct window *window = MALLOC(sizeof(struct window));

  window->width = 640;
  window->height = 480;
  window->title = "Defiance Client";

  window->window = NULL;
  window->open = false;

  return window;
}

struct window *window_destroy(struct window *window) {
  ASSERT_WINDOW(window);

  return FREE(window);
}

////////////////////////////////////////////////

bool window_open(struct window *window) {
  ASSERT_WINDOW(window);

  assert(!window->open);

  window->window = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);

  if(window->window) {
    glfwMakeContextCurrent(window->window);
    window->open = true;
    glClearColor(0.0, 0.0, 0.5, 1.0);
  }

  return window->window;
}

////////////////////////////////////////////////

bool window_should_close(struct window *window) {
  ASSERT_WINDOW(window);

  assert(window->open);
  
  return glfwWindowShouldClose(window->window);
}

////////////////////////////////////////////////

void window_pre_tick(struct window *window) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void window_post_tick(struct window *window) {
  glfwSwapBuffers(window->window);
  glfwPollEvents();
}
