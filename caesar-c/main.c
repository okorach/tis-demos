#include <stdlib.h>
#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

#include "caesar.h"

void gen_test(char *str, int shift)
{
    char *res1, *res2;

    printf("Encrypt text '%s'\n", str);
    res1 = caesar_encrypt(str, shift);
    if (!res1) return;
    printf("Result:      '%s'\n", res1);

    printf("Decrypt text '%s'\n", res1);
    res2 = caesar_decrypt(res1, shift);
    if (!res2) return;
    printf("Result:      '%s'\n", res2);

    free(res1);
    free(res2);
}

int main(void)
{
    char str[] = "People of Earth, your attention please";

    printf("Test 1: Shift with a negative input\n");
    gen_test(str, -3);
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(str, 7);

#ifdef __TRUSTINSOFT_ANALYZER__
#ifdef LEVEL2
    int any_offset;
    tis_make_unknown(&any_offset, sizeof(any_offset));
    gen_test(str, any_offset);
#endif
#endif

    return 0;
}
