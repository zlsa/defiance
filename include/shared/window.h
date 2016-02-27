
#ifndef WINDOW_H
#define WINDOW_H

#include <assert.h>
#include <stdbool.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define ASSERT_WINDOW(window) (assert(window))

struct s_window {
  int width;
  int height;
  char *title;
  
  GLFWwindow* window;
  bool open;
};

bool window_init();
bool window_terminate();

struct s_window *window_create();
struct s_window *window_free(struct s_window *window);

bool window_open(struct s_window *window);

bool window_should_close(struct s_window *window);
void window_pre_tick(struct s_window *window);
void window_post_tick(struct s_window *window);

#endif
