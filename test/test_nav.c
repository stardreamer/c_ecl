#include <stdio.h>
#include "unity.h"
#include "nav.h"
#include "ecl_errors.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_smoke_get_file_descriptor( void )
{
    char message[1024];
    int descriptor;
    int error_code = get_file_descriptor("test/data/example.egrid", &descriptor);

    sprintf(message, "Smoke test for get_file_descriptor has failed! Expected: (%s) but was (%s)", error_string(OK), error_string(error_code));
    TEST_ASSERT_MESSAGE(error_code == OK && descriptor > 0, message);
}

void test_smoke_close_file_descriptor( void )
{
    char message[1024];
    int descriptor;
    get_file_descriptor("test/data/example.egrid", &descriptor);

    int error_code = close_file_descriptor(descriptor);

    sprintf(message, "Smoke test for close_file_descriptor has failed! Expected: (%s) but was (%s)", error_string(OK), error_string(error_code));
    TEST_ASSERT_MESSAGE(error_code == OK , message);
}

void test_should_return_filenotfound_on_nonexisting_file()
{
    char message[1024];
    int error_code = get_file_descriptor("/nonexistingroot/nonexistingfile", NULL);

    sprintf(message, "Unit test for get_file_descriptor has failed! Expected: (%s) but was (%s)", error_string(FILE_NOT_FOUND), error_string(error_code));
    TEST_ASSERT_MESSAGE(error_code == FILE_NOT_FOUND, message);
}

void test_should_return_filecantbeclosed_on_bad_descriptor()
{
    char message[1024];
    int error_code = close_file_descriptor(-1);

    sprintf(message, "Unit test for close_file_descriptor has failed! Expected: (%s) but was (%s)", error_string(FILE_CANT_BE_CLOSED), error_string(error_code));
    TEST_ASSERT_MESSAGE(error_code == FILE_CANT_BE_CLOSED, message);
}

void test_read_header()
{
    char message[1024];
    int descriptor;
    get_file_descriptor("test/data/example.egrid", &descriptor);

    HeaderArray arre;
    
    get_headers(descriptor, &arre);

    print_header(arre.headers[0]);

    int error_code = close_file_descriptor(descriptor);

}