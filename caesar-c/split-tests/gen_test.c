#include <stdlib.h>
#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <limits.h>
#include <tis_builtin.h>
#define MAX_BUF 38
#endif

#include "../caesar.h"

int gen_test(char *str, int shift)
{
    char *res1, *res2;
    printf("Encrypt text '%s'\n", str);
    res1 = caesar_encrypt(str, shift);
    if (!res1) return 0;
    printf("Result:      '%s'\n", res1);

    printf("Decrypt text '%s'\n", res1);
    res2 = caesar_decrypt(res1, shift);
    if (!res2) return 0;
    printf("Result:      '%s'\n", res2);

    free(res1); free(res2);
    return 1;
}
