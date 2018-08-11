#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include <stdlib.h>

int safe_malloc(size_t size, void** a_p);
int safe_realloc(size_t new_size, void** a_p);

#endif