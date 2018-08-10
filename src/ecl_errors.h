#ifndef ECL_ERROR_H
#define ECL_ERROR_H

#define OK 0
#define FILE_NOT_FOUND -1
#define NOT_IMPLEMENTED -2
#define FILE_CANT_BE_OPENED -3

#define OK_STR "No Error!"
#define FILE_NOT_FOUND_STR "File not found!"
#define FILE_CANT_BE_OPENED_STR "File can't be opened!"
#define NOT_IMPLEMENTED_STR "This functionality has not yet been developed!"
#define UNKNOWN_ERROR "Unknown error occured!"

/*! \fn const char* error_string(int error_code)
 *  \brief Return string representation of the \a error_code
 *  \param error_code an integer.
 *  \return a character pointer.
 */
const char* error_string(int error_code);

#endif