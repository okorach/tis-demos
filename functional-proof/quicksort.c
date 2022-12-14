#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "quicksort.h"

/*@ requires \valid(a);
    requires \valid(b);
    ensures *a == \old(*b);
    ensures *b == \old(*a);
    assigns *a,*b;      */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*@ requires \valid(t +(leftmost..rightmost));
    requires 0 <= leftmost < INT_MAX;
    requires 0 <= rightmost < INT_MAX;
    decreases (rightmost - leftmost);
    assigns *(t+(leftmost..rightmost)); */
void quickSort(int *t, int leftmost, int rightmost)
{
    if (leftmost >= rightmost)
    {
        return;
    }
    int pivot = t[rightmost];
    int counter = leftmost;

    /*@ loop assigns i, counter, *(t+(leftmost..rightmost));
        loop invariant 0 <= leftmost <= i <= rightmost + 1;
        loop invariant 0 <= leftmost <= counter <= i;
        loop invariant \forall int i; leftmost <= i < counter ==> t[i] <= pivot;
        loop variant rightmost - i;  */
    for (int i = leftmost; i <= rightmost; i++)
    {
        if (t[i] <= pivot)
        {
            /*@assert \valid(&t[counter]);*/
            /*@assert \valid(&t[i]);*/
            swap(&t[counter], &t[i]);
            counter++;
        }
    }
    quickSort(t, leftmost, counter - 2);
    if (counter < INT_MAX)
        quickSort(t, counter, rightmost);
}
