#include <stdlib.h>
#include "memory_utils.h"
#include "ecl_errors.h"

int safe_malloc(size_t size, void** a_p)
{
    *a_p = malloc(size);
    if(a_p == NULL)
        return MALLOC_FAILURE;
    return OK;
}

int safe_realloc(size_t new_size, void** a_p)
{
    void* tmp = realloc(*a_p, new_size);
    if(tmp == NULL)
        return REALLOC_FAILURE;
    *a_p = tmp;
    return OK;
}