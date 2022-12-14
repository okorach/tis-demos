#include <stdlib.h>
#include <string.h>
#include "smart_meter.h"

void update_totals(unsigned t, unsigned instant_pow)
{
    unsigned duration = t - previous_t;
    unsigned energy = instant_pow * duration;
    total = total + energy;
    switch (current_period)
    {
    case PEAK:
        // do_peak_things();
        break;
    case OFFPEAK:
        // do_offpeak_things();
        break;
    }
    total_during_period[current_period] += energy;
    previous_t = t;
}
