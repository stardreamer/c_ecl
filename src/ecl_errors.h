#ifndef ECL_ERROR_H
#define ECL_ERROR_H

#define OK 0
#define FILE_NOT_FOUND -1
#define NOT_IMPLEMENTED -2
#define FILE_CANT_BE_OPENED -3
#define FILE_CANT_BE_CLOSED -4
#define MALLOC_FAILURE -5
#define REALLOC_FAILURE -6
#define DATA_END -7

#define OK_STR "No Error!"
#define FILE_NOT_FOUND_STR "File not found!"
#define FILE_CANT_BE_OPENED_STR "File can't be opened!"
#define FILE_CANT_BE_CLOSED_STR "File can't be closed!"
#define MALLOC_FAILURE_STR "Malloc failure!"
#define REALLOC_FAILURE_STR "Realloc failure!"
#define NOT_IMPLEMENTED_STR "This functionality has not yet been developed!"
#define DATA_END_STR "End of data!"
#define UNKNOWN_ERROR "Unknown error occured!"

/*! \fn const char* error_string(int error_code)
 *  \brief Return string representation of the \a error_code
 *  \param error_code an integer.
 *  \return a character pointer.
 */
const char* error_string(int error_code);

#endif