#include "build/temp/_test_ecl_errors.c"
#include "ecl_errors.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_error_string( void )

{

    if ((strcmp(error_string(0), "No Error!") == 0)) {} else {UnityFail( ((("OK error code was not handled correctly!"))), (UNITY_UINT)((UNITY_UINT)(15)));};

    if ((strcmp(error_string(-1), "File not found!") == 0)) {} else {UnityFail( ((("FILE_NOT_FOUND_STR error code was not handled correctly!"))), (UNITY_UINT)((UNITY_UINT)(16)));};

    if ((strcmp(error_string(999), "Unknown error occured!") == 0)) {} else {UnityFail( ((("FILE_NOT_FOUND_STR error code was not handled correctly!"))), (UNITY_UINT)((UNITY_UINT)(17)));};

}
