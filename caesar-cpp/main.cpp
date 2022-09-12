#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

#include "caesar.hpp"

int gen_test(std::string str, int user_shift)
{
    std::cout << "Encrypt text: '" << str << "'\n";
    std::string res1 = Caesar::encrypt(str, user_shift);
    std::cout << "Result:       '" << res1 << "'\n";
    std::cout << "Decrypt text: '" << res1 << "'\n";
    std::string res2 = Caesar::decrypt(res1, user_shift);
    std::cout << "Result:       '" << res2 << "'\n";
    return res2 == str;
}

int main(void)
{
    std::string str = "People of Earth, your attention please";

    std::cout << "Test 1: Shift with a positive input" << std::endl;
    int ok1 = gen_test(str, 7);
    std::cout << std::endl << "Test 2: Shift with a negative input" << std::endl;
    int ok2 = gen_test(str, -3);

#ifdef __TRUSTINSOFT_ANALYZER__
#ifdef LEVEL2
    int any_shift;
    tis_make_unknown(&any_shift, sizeof(any_shift));
    gen_test(str, any_shift);
#endif
#endif
    if (ok1 && ok2) {
        std::cout << "Tests successful\n";
        return 0;
    } else {
        std::cout << "Tests failed\n";
        return 1;
    }
}
