#include<stdio.h>
#include<stdlib.h>
#include "utils.h"

#define is_bigendian() ((*(char*)&end_check) == 0)

const int end_check = 1;

short reverse_short(char *c) 
{
    short s;
    char *p = (char *)&s;

    if (is_bigendian())
    {
        p[0] = c[0];
        p[1] = c[1];
    } 
    else
    {
        p[0] = c[1];
        p[1] = c[0];
    }

    return s;
}

int reverse_int(char *c) 
{
    int i;
    char *p = (char *)&i;

    if (is_bigendian())
    {
        p[0] = c[0];
        p[1] = c[1];
        p[2] = c[2];
        p[3] = c[3];
    }
    else
    {
        p[0] = c[3];
        p[1] = c[2];
        p[2] = c[1];
        p[3] = c[0];
    }

    return i;
}

unsigned char reverse_logi(char *c) 
{
    int i = reverse_int(c);
    return i == 0;
}

float reverse_float(char *c) 
{
    float f;
    char *p = (char *)&f;

    if (is_bigendian())
    {
        p[0] = c[0];
        p[1] = c[1];
        p[2] = c[2];
        p[3] = c[3];
    }
    else
    {
        p[0] = c[3];
        p[1] = c[2];
        p[2] = c[1];
        p[3] = c[0];
    }

    return f;
}

float reverse_double(char *c) 
{
    double d;
    char *p = (char *)&d;

    if (is_bigendian())
    {
        p[0] = c[0];
        p[1] = c[1];
        p[2] = c[2];
        p[3] = c[3];
        p[4] = c[4];
        p[5] = c[5];
        p[6] = c[6];
        p[7] = c[7];
    }
    else
    {
        p[0] = c[7];
        p[1] = c[6];
        p[2] = c[5];
        p[3] = c[4];
        p[4] = c[3];
        p[5] = c[2];
        p[6] = c[1];
        p[7] = c[0];
    }

    return d;
}

void byte_reverse_in_place(char *byte_stream, int len)
{
    if (is_bigendian())
    {
        return;
    }

    char *p1 = byte_stream;
    char *p2 = byte_stream + len - 1;

    while (p1 < p2) {
        char tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
    }
}