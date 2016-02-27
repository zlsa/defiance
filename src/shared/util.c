
#include "util.h"

int util_log(int level, const char *format, ...) {
  va_list args;
  va_start(args, format);

  FILE *stream = stdout;

  switch(level) {
  case LOG_DEBUG:
    fputs(KMAG "- ", stream);
    break;
  case LOG_INFO:
    fputs(KGRN ": " RESET, stream);
    break;
  case LOG_NOTICE:
    fputs(KBLU "! " RESET , stream);
    break;
  case LOG_WARNING:
    fputs(KYEL "! " RESET, stream);
    break;
  case LOG_ERROR:
    stream = stderr;
    fputs(KRED "! ", stream);
    break;
  }
  vfprintf(stream, format, args);
  
  fputs("\n" RESET, stream);

  va_end(args);
}

void* util_malloc(size_t size, unsigned long line) {
  void* p = malloc(size);
  
  if(!p) {
    util_log(LOG_ERROR, "%s: %ul out of memory (%ul bytes)", __FILE__, line, (unsigned long) size);
    abort();
  }
  
  return p;
}

void* util_free(void *ptr, unsigned long line) {
  
  if(!ptr) {
    util_log(LOG_ERROR, "%s: %ul FREE() called on null pointer", __FILE__, line);
    abort();
  }

  free(ptr);
  
  return NULL;
}
