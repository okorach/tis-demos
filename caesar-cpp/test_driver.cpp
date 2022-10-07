#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

#include "caesar.hpp"
#define MAX_BUF 38

const std::string str = "People of Earth, your attention please";

int gen_test(const std::string & str, int user_shift)
{
    std::cout << "Encrypt text: '" << str << "'\n";
    std::string res1 = Caesar::encrypt(str, user_shift);
    std::cout << "Result:       '" << res1 << "'\n";
    std::cout << "Decrypt text: '" << res1 << "'\n";
    std::string res2 = Caesar::decrypt(res1, user_shift);
    std::cout << "Result:       '" << res2 << "'\n";
    return res2 == str;
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

#if __TRUSTINSOFT_ANALYZER__
int test_generalized_int(void)
{
    long any_shift;
    int ok;
#ifdef EXCLUDE_INT_MIN
    any_shift = tis_long_interval(INT_MIN + 1, INT_MAX);
#else
    tis_make_unknown((char *)&any_shift, sizeof(any_shift));
#endif
    printf("\nTest 3: Generalization of shift to any 64 bits signed integer [%ld - %ld]\n", LONG_MIN, LONG_MAX);
    ok = gen_test(str, any_shift);
    return ok;
}

int test_generalized_string(void)
{
    long any_shift;
#ifdef EXCLUDE_INT_MIN
    any_shift = tis_long_interval(LONG_MIN + 1, LONG_MAX);
#else
    tis_make_unknown((char *)&any_shift, sizeof(any_shift));
#endif
    char any_str[MAX_BUF+1];
    printf("\nTest 4: Generalization of shift and generalization of string to any %d characters string\n", MAX_BUF);

    tis_make_unknown(any_str, MAX_BUF);
    any_str[MAX_BUF] = '\0';
    return gen_test(any_str, any_shift);
}
#endif

int main(void)
{
    std::string str = "People of Earth, your attention please";
    int ok;
    ok = test1();
    ok = ok && test2();
#ifdef __TRUSTINSOFT_ANALYZER__
#ifdef LEVEL2
    ok = ok && test_generalized_int();
    ok = ok && test_generalized_string();
#endif
#endif

    if (ok) {
        std::cout << "Tests successful\n";
        return 0;
    } else {
        std::cout << "Tests failed\n";
        return 1;
    }
}
