#include <stdio.h>
#include "ecl_errors.h"


/*! \fn const char* errorString(int error_code)
 *  \brief Return string representation of the \a error_code
 *  \param error_code an integer.
 *  \return a character pointer.
 */
const char* error_string(int error_code)
{
    switch(error_code)
    {
        case OK:
            return OK_STR;
        case FILE_NOT_FOUND:
            return FILE_NOT_FOUND_STR;
        case FILE_CANT_BE_OPENED:
            return FILE_CANT_BE_OPENED_STR;
        case FILE_CANT_BE_CLOSED:
            return FILE_CANT_BE_CLOSED_STR;
        case NOT_IMPLEMENTED:
            return NOT_IMPLEMENTED_STR;
		default:
			return UNKNOWN_ERROR;
		break;
	}
}