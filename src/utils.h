#ifndef UTILS_H
#define UTILS_H



short reverse_short (char *c);

int reverse_int (char *c);

unsigned char reverse_logi (char *c);

float reverse_float (char *c);

float reverse_double (char *c);

void byte_reverse_in_place(char *byte_stream, int len);


inline void always_byte_reverse_in_place(char *byte_stream, int len);


inline void always_byte_reverse_in_place(char *byte_stream, int len)
{
    if(len == 4)
    {
        char tmp1 = byte_stream[0];
        char tmp2 = byte_stream[1];

        byte_stream[0] = byte_stream[3];
        byte_stream[3] = tmp1;
        byte_stream[1] = byte_stream[2];
        byte_stream[2] = tmp2;

        return;
    }

    if(len == 8)
    {
        char tmp1 = byte_stream[0];
        char tmp2 = byte_stream[1];
        char tmp3 = byte_stream[2];
        char tmp4 = byte_stream[3];

        byte_stream[0] = byte_stream[7];
        byte_stream[7] = tmp1;
        byte_stream[1] = byte_stream[6];
        byte_stream[6] = tmp2;
        byte_stream[2] = byte_stream[5];
        byte_stream[5] = tmp3;
        byte_stream[3] = byte_stream[4];
        byte_stream[4] = tmp4;

        return;
    }
    
    char *p1 = byte_stream;
    char *p2 = byte_stream + len - 1;

    if(len == 4)
    {
        char tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
        tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
        return;
    }

    while (p1 < p2) {
        char tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
    }
}
#endif