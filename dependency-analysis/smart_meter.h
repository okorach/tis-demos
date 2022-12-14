#ifndef SMART_METER_H
#define SMART_METER_H

enum period
{
    PEAK,
    OFFPEAK,
    NBPERIOD
} current_period;

unsigned total;
unsigned total_during_period[NBPERIOD];
unsigned previous_t;

/* Ciphers the input string using the provided shift */
void update_totals(unsigned t, unsigned instant_pow);

#endif