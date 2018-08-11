#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "nav.h"
#include "memory_utils.h"

int get_headers(int descriptor, HeaderArray* header_array)
{
    HeaderArray har = HEADER_ARRAY_INIT;
    *header_array = har;
    off_t end_position = lseek(descriptor, 0, SEEK_END);
    lseek(descriptor, 0, SEEK_SET);

    int err_code = safe_malloc(header_array->capacity*sizeof(Header), (void**)&(header_array->headers));
    if(err_code != 0)
        return err_code;

    Header header;
    off_t cur_position = lseek(descriptor, 0, SEEK_CUR);
 
    while(cur_position != end_position)
    {        
        read_header(descriptor, &header, &cur_position);

        if(header_array->length == header_array->capacity - 1)
        {
            header_array->capacity *= 2;
            err_code = safe_realloc(header_array->capacity*sizeof(Header), (void**)&(header_array->headers));
            if(err_code != 0)
                return err_code;
        }
        
        header_array->headers[header_array->length] = header;
        header_array->length += 1;
        if(cur_position == end_position)
            break;
        int chunks_skipped;
        header_array->headers[header_array->length-1].start_data_pos = cur_position;
        skip_data_bytes(descriptor, header.elements_number*type_to_size(header.type), &chunks_skipped, &cur_position);
        header_array->headers[header_array->length-1].end_data_pos = cur_position;

    }

    err_code = safe_realloc(header_array->length*sizeof(Header), (void**)&(header_array->headers));
    if(err_code != 0)
        return err_code;
    header_array->capacity = header_array ->length;

    return OK;
}

int read_header(int descriptor, Header* header, off_t* cur_position)
{

    lseek(descriptor, 4, SEEK_CUR);
    header->keyword = (char*) malloc(9);
    read(descriptor, header->keyword, 8);
    header->keyword[8] = '\0';
    char element_number_bytes[4];
    read(descriptor, element_number_bytes, 4);
    header->elements_number = reverse_int(element_number_bytes);
    header->type = (char*) malloc(5);
    read(descriptor, header->type, 4);
    header->type[4] = '\0';
    *cur_position = lseek(descriptor, 4, SEEK_CUR);
    return OK;
}

