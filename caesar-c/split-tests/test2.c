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
    printf("\nTest 2: Shift with a negative input\n");
    if (gen_test(str, -3)) {
        printf("\nTests successful\n\n");
        return 0;
    } else {
        printf("\nTests failed\n\n");
        return 1;
    }
}
