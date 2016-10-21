/*
 * Exercise 2-7
 *
 * Write a function invert(x, p, n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
 * others unchanged.
 */

#include <assert.h>
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
        unsigned x;
        int p, n;

        x = 7;
        p = 2;
        n = 2;

        assert(invert(x, p, n) == 1);

        return 0;
}

unsigned invert(unsigned x, int p, int n)
{
        unsigned mask,
                 shift;

        mask = ~(~0 << n);
        shift = p + 1 - n;

        return x ^ (mask << shift);
}
