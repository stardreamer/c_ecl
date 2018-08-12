#ifndef NAV_H
#define NAV_H

#include <sys/types.h>
#include "ecl_errors.h"
#include "utils.h"

#define HEADER_ARRAY_INIT {0, 256, NULL}
#define DATA_LAYOUT_INIT {0, 0, 0, 0}

typedef struct DataLayout 
{
    off_t start_pos; 
    off_t end_pos;
    unsigned int elements_number;
    unsigned int type_size;
} DataLayout;

typedef struct Header 
{ 
    char* keyword; 
    char* type;
    DataLayout layout;
} Header;

typedef struct HeaderArray
{
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

int read_data_by_layout(int descriptor, DataLayout layout, char** byte_array);

int read_data_chunk(int descriptor, DataLayout layout, char** chunk_byte_array);
#endif
