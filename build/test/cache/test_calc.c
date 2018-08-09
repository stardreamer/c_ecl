#include "build/temp/_test_calc.c"
#include "calc.h"
#include "unity.h"
void setUp(void)

{

}

void tearDown(void)

{

}

void test_add( void )

{

    int result = 0;

    result = calc_add(2,2);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(13), UNITY_DISPLAY_STYLE_INT);

}
