#include <stdlib.h>
#include <stdio.h>

#include "gen_test.h"
#ifdef __TRUSTINSOFT_ANALYZER__
#include <tis_builtin.h>
#endif

int main(void)
{
    char str[] = "People of Earth, your attention please";
    int ok;
    int any_shift;
    tis_make_unknown(&any_shift, sizeof(any_shift));
    printf("\nTest 3: Generalization of shift to any 64 bits signed integer\n");
    ok = gen_test(str, any_shift);

    if (ok) {
        printf("\nTests successful\n\n");
        return 0;
    } else {
        printf("\nTests failed\n\n");
        return 1;
    }
}
