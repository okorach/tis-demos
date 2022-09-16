#include <stdlib.h>
#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <limits.h>
#include <tis_builtin.h>
#endif

#include "caesar.h"

char str[] = "People of Earth, your attention please";

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

int test1(void)
{
    printf("Test 1: Shift with a positive input\n");
    int ok = gen_test(str, 7);
    printf(ok ? "Test successful\n": "Test failed\n");
    return ok;
}

int test2(void)
{
    printf("Test 2: Shift with a negative input\n");
    int ok = gen_test(str, -3);
    printf(ok ? "Test successful\n": "Test failed\n");
    return ok;
}

#ifdef __TRUSTINSOFT_ANALYZER__
int test_generalized_int(void)
{
    int any_shift;
    int ok;
    tis_make_unknown(&any_shift, sizeof(any_shift));
    printf("\nTest 3: Generalization of shift to any 64 bits signed integer\n");
    ok = gen_test(str, any_shift);
    return ok;
}

int test_generalized_string(void)
{
    int any_shift;
    int ok;
    tis_make_unknown(&any_shift, sizeof(any_shift));
    char any_str[MAX_BUF+1];
    printf("\nTest 4: Generalization of shift and generalization of string to any %d characters string\n", MAX_BUF);

    tis_make_unknown(any_str, MAX_BUF);
    any_str[MAX_BUF] = '\0';
    if (any_shift != INT_MIN) {
        ok = gen_test(any_str, any_shift);
    }
    return ok;
}
#endif

int main(void)
{
    
    int ok;
    ok = test1();
    ok = ok && test2();

#if defined LEVEL2 || defined LEVEL2_STEP2
    ok = ok && test_generalized_int();
#ifdef LEVEL2_STEP2
    ok = ok && test_generalized_string();
#endif
#endif

    if (ok) {
        printf("\nAll Tests successful\n\n");
        return 0;
    } else {
        printf("\nSome Tests failed\n\n");
        return 1;
    }
}
