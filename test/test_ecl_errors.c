#include <string.h>
#include "unity.h"
#include "ecl_errors.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_error_string( void )
{
    TEST_ASSERT_MESSAGE(strcmp(error_string(OK), OK_STR) == 0, "OK error code was not handled correctly!");
    TEST_ASSERT_MESSAGE(strcmp(error_string(FILE_NOT_FOUND), FILE_NOT_FOUND_STR) == 0, "FILE_NOT_FOUND_STR error code was not handled correctly!");
    TEST_ASSERT_MESSAGE(strcmp(error_string(999), UNKNOWN_ERROR) == 0, "FILE_NOT_FOUND_STR error code was not handled correctly!");
}