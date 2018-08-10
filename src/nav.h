#ifndef NAV_H
#define NAV_H

#include "ecl_errors.h"


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

#endif
