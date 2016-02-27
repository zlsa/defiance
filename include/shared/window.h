
#ifndef WINDOW_H
#define WINDOW_H

#include <assert.h>
#include <stdbool.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define ASSERT_WINDOW(window) (assert(window))

struct window {
  int width;
  int height;
  char *title;
  
  GLFWwindow* window;
  bool open;
};

bool window_init();
bool window_terminate();

struct window *window_create();
struct window *window_destroy(struct window *window);

bool window_open(struct window *window);

bool window_should_close(struct window *window);
void window_pre_tick(struct window *window);
void window_post_tick(struct window *window);

#endif
