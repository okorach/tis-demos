#include <stdlib.h>
#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <limits.h>
#include <tis_builtin.h>
#define MAX_BUF 38
#endif

#include "gen_test.h"

int main(void)
{
    char str[] = "People of Earth, your attention please";
    int ok;
    printf("Test 1: Shift with a positive input\n");
    ok = gen_test(str, 7);

    if (ok) {
        printf("\nTests successful\n\n");
        return 0;
    } else {
        printf("\nTests failed\n\n");
        return 1;
    }
}
