
#include "util.h"

static void* util_malloc(size_t n, unsigned long line) {
  void* p = malloc(n);
  
  if(!p) {
    fprintf(stderr, "[%s:%ul] Out of memory(%ul bytes)\n", __FILE__, line, (unsigned long)n);
    exit(EXIT_FAILURE);
  }
  
  return p;
}
