#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h> 
#include <stdio.h> 
#include "nav.h"
#include "memory_utils.h"


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

int skip_data_bytes(int descriptor, off_t total_bytes, int* skipped_chunks, off_t* cur_position)
{
    *skipped_chunks = 0;
    off_t read_bytes = 0;
    while(read_bytes < total_bytes)
    {
        off_t start_position = lseek(descriptor, 0, SEEK_CUR);
        off_t end_position;
        skip_chunk(descriptor, &end_position);
        *cur_position = end_position;
        off_t jump_size = end_position - start_position;
        read_bytes += jump_size - 8;

        *skipped_chunks += 1;
    }

    return OK;
}

int skip_chunk(int descriptor, off_t* end_position)
{
    char next_pos_bytes[4];
    read(descriptor, next_pos_bytes, 4);

    int next_pos = reverse_int(next_pos_bytes);
    *end_position = lseek(descriptor, next_pos + 4, SEEK_CUR);

    return OK;
}

int print_header(Header header)
{
    printf("%s|%d|%s|%u|%ld|%ld\n", header.keyword, header.layout.elements_number, header.type,header.layout.type_size, header.layout.start_pos, header.layout.end_pos);
    return OK;
}

unsigned int type_to_size(char* type)
{
    if(type[0] == 'I' || type[0] == 'i')
        return 4;
    if(type[0] == 'R' || type[0] == 'r')
        return 4;
    if(type[0] == 'L' || type[0] == 'l')
        return 4;
    if(type[0] == 'C' || type[0] == 'c')
    {
        if(type[1] == '0')
        {
            return 10*(type[2]-'0') + (type[3] - '0');
        }

        return 8;
    }
        
    if(type[0] == 'D' || type[0] == 'd')
        return 8;
    if(type[0] == 'M' || type[0] == 'm')
        return 0;
    return 0;
}

int read_data_chunk(int descriptor, DataLayout layout, char** chunk_byte_array)
{
    int error_code = safe_malloc(layout.elements_number*layout.type_size, (void**)chunk_byte_array);
    if(error_code != OK)
        return MALLOC_FAILURE;
    
    
    off_t cur_pos = lseek(descriptor, 0, SEEK_CUR);

    if(cur_pos == layout.end_pos)
    {
        return DATA_END;
    }

    char next_pos_bytes[4];
    read(descriptor, next_pos_bytes, 4);
    int next_bytes_num = reverse_int(next_pos_bytes);

    read(descriptor, *chunk_byte_array, next_bytes_num);

    return OK;
}