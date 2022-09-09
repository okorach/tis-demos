#include <stdlib.h>
#include "caesar.hpp"

// Ciphers a buffer with a right shift specified by the user
//  buf: The buffer to encrypt
//  bufsize: The buffer size
//  offset: The shift to perform
// returns The pointer to the encrypted string

char * Caesar::encrypt(const char *buf, int bufsize) const
{
    int shift = absolute_int(offset);
    int i = 0;

    char * crypted_buffer(new char[bufsize]);
    while (buf[i])
    {
        crypted_buffer[i] = buf[i] + shift;
        i++;
    }
    crypted_buffer[i] = 0;
    return crypted_buffer;
}

// Deciphers a buffer with a right shift specified by the user
//  buf: The buffer to encrypt
//  bufsize: The buffer size
//  offset: The shift to perform
// returns The pointer to the encrypted string
char * Caesar::decrypt(const char *buf, int bufsize) const
{
    int shift = Caesar::absolute_int(offset);
    int i = 0;

    char * crypted_buffer(new char[bufsize]);
    while (buf[i])
    {
        crypted_buffer[i] = buf[i] - shift;
        i++;
    }
    crypted_buffer[i] = 0;
    return crypted_buffer;
}

int Caesar::absolute_int(int x) const
{
    int abs_x;
    if (x < 0)
        abs_x = -x;
    else
        abs_x = x;
    return abs_x;
}
