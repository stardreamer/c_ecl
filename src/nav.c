#include "nav.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_file_descriptor(char* filepath, int* descriptor)
{
    if(access(filepath, F_OK) == -1)
    {
        return FILE_NOT_FOUND;
    }

    int fd = open(filepath, O_RDONLY);

    if(fd == -1)
    {
        return FILE_CANT_BE_OPENED;
    }
    
    *descriptor = fd;
    return OK;
}