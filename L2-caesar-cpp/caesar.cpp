#include <stdlib.h>
#include <caesar.hpp>

// Ciphers a buffer with a right shift specified by the user
//  buf: The buffer to encrypt
//  bufsize: The buffer size
//  offset: The shift to perform
// returns The pointer to the encrypted string

template <class T>
std::shared_ptr<T> Caesar<T>::encrypt(const T *buf, int bufsize) const
{
    int shift = absolute_int(offset);
    int i = 0;

    std::shared_ptr<T> crypted_buffer(new T[bufsize], [](T *i)
                                      { delete[] i; });
    while (buf[i])
    {
        auto s = (crypted_buffer.get());
        s[i] = buf[i] + (T)shift;
        i++;
    }
    crypted_buffer.get()[i] = 0;
    return crypted_buffer;
}

// Deciphers a buffer with a right shift specified by the user
//  buf: The buffer to encrypt
//  bufsize: The buffer size
//  offset: The shift to perform
// returns The pointer to the encrypted string
template <class T>
std::shared_ptr<T> Caesar<T>::decrypt(const T *buf, int bufsize) const
{
    int shift = Caesar<T>::absolute_int(offset);
    int i = 0;

    std::shared_ptr<T> crypted_buffer(new T[bufsize], [](T *i)
                                      { delete[] i; });
    while (buf[i])
    {
        auto s = (crypted_buffer.get());
        s[i] = buf[i] - (T)shift;
        i++;
    }
    crypted_buffer.get()[i] = 0;
    return crypted_buffer;
}

template <class T>
int Caesar<T>::absolute_int(int x) const
{
    int abs_x;
    if (x < 0)
        abs_x = -x;
    else
        abs_x = x;
    return abs_x;
}
