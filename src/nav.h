#ifndef NAV_H
#define NAV_H

#include <sys/types.h>
#include "ecl_errors.h"
#include "utils.h"

#define HEADER_ARRAY_INIT {0, 256, NULL}

typedef struct Header { 
    off_t start_data_pos; 
    off_t end_data_pos;
    char* keyword; 
    char* type;
    unsigned int elements_number;

} Header;

typedef struct HeaderArray{
    int length; 
    int capacity;
	Header* headers; 
} HeaderArray;

/*! \fn int get_file_descriptor(char* filepath, int* descriptor)
 *  \brief Gets the file \a descriptor.
 *  \param filepath an pointer to char array.
 *  \param descriptor an pointer to descriptor.
 *  \return error code.
 */
int get_file_descriptor(char* filepath, int* descriptor);

/*! \fn int close_file_descriptor(int descriptor)
 *  \brief Closes the file \a descriptor.
 *  \param descriptor descriptor to be closed.
 *  \return error code.
 */
int close_file_descriptor(int descriptor);

int skip_data(int descriptor);

int skip_chunk(int descriptor, off_t* pos);

int print_header(Header header);

unsigned int type_to_size(char* type);

int get_headers(int descriptor, HeaderArray* header_array);

int read_header(int descriptor, Header* header, off_t* cur_position);

int skip_data_bytes(int descriptor, off_t total_bytes, int* skipped_chunks, off_t* cur_position);

#endif
