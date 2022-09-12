#include <stdlib.h>
#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <limits.h>
#include <tis_builtin.h>
#define MAX_BUF 38
#endif

#include "caesar.h"

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

int main(void)
{
    char str[] = "People of Earth, your attention please";
    int ok1, ok2;
    printf("Test 1: Shift with a positive input\n");
    ok1 = gen_test(str, 7);
    printf("\nTest 2: Shift with a negative input\n");
    ok2 = gen_test(str, -3);

#if defined LEVEL2 || defined LEVEL2_STEP2
    int any_shift;
    tis_make_unknown(&any_shift, sizeof(any_shift));
#ifndef LEVEL2_STEP2
    printf("\nTest 3: Generalization of shift to any 64 bits signed integer\n");
    gen_test(str, any_shift);
#else
    char any_str[MAX_BUF+1];
    printf("\nTest 4: Generalization of shift and generalization of string to any %d characters string\n", MAX_BUF);
    any_str[MAX_BUF] = '\0';
    if (any_shift != INT_MIN) {
        gen_test(any_str, any_shift);
    }
#endif
#endif

    if (ok1 && ok2) {
        printf("\nTests successful\n\n");
        return 0;
    } else {
        printf("\nTests failed\n\n");
        return 1;
    }
}
