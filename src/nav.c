#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "nav.h"

/*! \fn int get_file_descriptor(char* filepath, int* descriptor)
 *  \brief Gets the file \a descriptor.
 *  \param filepath an pointer to char array.
 *  \param descriptor an pointer to descriptor.
 *  \return error code.
 */
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

/*! \fn int close_file_descriptor(int descriptor)
 *  \brief Closes the file \a descriptor.
 *  \param descriptor descriptor to be closed.
 *  \return error code.
 */
int close_file_descriptor(int descriptor)
{
    if (close(descriptor) == -1) {
        return FILE_CANT_BE_CLOSED;
    }

    return OK;
}