#ifndef NAV_H
#define NAV_H

#include "ecl_errors.h"


/*! \fn int get_file_descriptor(char* filepath, int* descriptor)
 *  \brief Sets the file \a descriptor.
 *  \param filepath an pointer to char array.
 *  \param descriptor an pointer to descriptor.
 *  \return error code.
 */
int get_file_descriptor(char* filepath, int* descriptor);

#endif
