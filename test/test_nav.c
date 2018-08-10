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

void test_smoke_nav( void )
{
    char message[1024];
    int error_code = get_file_descriptor(NULL, NULL);

    sprintf(message, "Smoke test for get_file_descriptor has failed! Expected: (%s) but was (%s)", error_string(OK), error_string(error_code));
    TEST_ASSERT_MESSAGE(error_code == OK, message);
}