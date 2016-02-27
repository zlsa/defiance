
#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

#define MALLOC(size) util_malloc(size, __LINE__)
#define FREE(ptr) util_free(ptr, __LINE__)

#define LOG_DEBUG   (0)
#define LOG_INFO    (1)
#define LOG_NOTICE  (2)
#define LOG_WARNING (3)
#define LOG_ERROR   (4)

int util_log(int level, const char *format, ...);

void* util_malloc(size_t size, unsigned long line);
void* util_free(void *ptr, unsigned long line);
  
#endif
