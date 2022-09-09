#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

#include "caesar.hpp"

void gen_test(std::string str, int user_shift)
{
    Caesar caesar(user_shift);

    std::cout << "Encrypt text: '" << str << "'\n";
    char * res1 = caesar.encrypt(str.c_str(), str.size() + 1);
    std::cout << "Result:       '" << res1 << "'\n";
    std::cout << "Decrypt text: '" << res1 << "'\n";
    char * res2 = caesar.decrypt(res1, str.size() + 1);
    std::cout << "Result:       '" << res2 << "'\n";
}

int main(void)
{
    std::string str = "People of Earth, your attention please";

    printf("Test 1: Shift with a negative input\n");
    gen_test(str, -3);
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(str, 7);

#ifdef __TRUSTINSOFT_ANALYZER__
    int any_shift;
    tis_make_unknown((char *)&any_shift, sizeof(any_shift));
    gen_test(str, any_shift);
#endif

    return 0;
}
