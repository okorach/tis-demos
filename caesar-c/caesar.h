#ifndef CAESAR_H
#define CAESAR_H

/* Ciphers the input string using the provided shift */

char *caesar_encrypt(char *str, int shift);

/* Deciphers the input ciphered string using the provided shift */

char *caesar_decrypt(char *str, int shift);
#endif