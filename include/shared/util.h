
#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <stdio.h>

#define MALLOC(n) util_malloc(n, __LINE__)

static void* util_malloc(size_t n, unsigned long line);
  
#endif
