#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <caesar.hpp>

void gen_test(std::string str, int user_shift)
{
    Caesar<char> caesar(user_shift);

    std::cout << "Encrypt text: '" << str << "'\n";
    std::shared_ptr<char> res1 = caesar.encrypt(str.c_str(), str.size() + 1);
    std::cout << "Result:       '" << res1 << "'\n";
    std::cout << "Decrypt text: '" << res1 << "'\n";
    std::shared_ptr<char> res2 = caesar.decrypt(res1.get(), str.size() + 1);
    std::cout << "Result:       '" << res2 << "'\n";
}

int main(void)
{
    char orig_str[] = "People of Earth, your attention please";

    printf("Test 1: Shift with a negative input\n");
    gen_test(orig_str, -3);
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(orig_str, 7);

    return 0;
}
