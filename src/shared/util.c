
#include "util.h"

int util_log(int level, const char *format, ...) {
  va_list args;
  va_start(args, format);

  fputs("[ INFO ] ", stdout);
  vprintf(format, args);
  fputc('\n', stdout);

  va_end(args);
}

void* util_malloc(size_t size, unsigned long line) {
  void* p = malloc(size);
  
  if(!p) {
    fprintf(stderr, "[%s:%ul] Out of memory(%ul bytes)\n", __FILE__, line, (unsigned long) size);
    exit(EXIT_FAILURE);
  }
  
  return p;
}

void* util_free(void *ptr, unsigned long line) {
  
  if(!ptr) {
    fprintf(stderr, "[%s:%ul] FREE() called on null pointer!\n", __FILE__, line);
    exit(EXIT_FAILURE);
  }

  free(ptr);
  
  return NULL;
}
