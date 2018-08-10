#include "nav.h"
#include <unistd.h>

int get_file_descriptor(char* filepath, int* descriptor)
{
    if(access(filepath, F_OK) == -1)
    {
        return FILE_NOT_FOUND;
    }
        
    return NOT_IMPLEMENTED;
}