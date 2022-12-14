#include <stdlib.h>
#include <stdio.h>

#ifdef __TRUSTINSOFT_ANALYZER__
#include <limits.h>
#include <tis_builtin.h>
#endif

#include "smart_meter.h"

// Test driver

int main(void)
{
    printf("Running tests");
    current_period = OFFPEAK;
    update_totals(9, 300);
    update_totals(10, 310);
    current_period = PEAK;
    update_totals(11, 317);
    update_totals(12, 329);
#ifdef __TRUSTINSOFT_ANALYZER__
    printf("Running TIS L2 Analysis");
    // set up the inputs
    tis_make_unknown(&previous_t, sizeof(previous_t));
    current_period = tis_interval(0, NBPERIOD - 1);
    unsigned t;
    tis_make_unknown(&t, sizeof t);
    unsigned instant_pow;
    tis_make_unknown(&instant_pow, sizeof(instant_pow));

    // call the target function
    printf("Updating totals");
    update_totals(t, instant_pow);
#endif
}
