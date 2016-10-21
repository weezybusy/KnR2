/*
 * Exercise 2-6
 *
 * Write a function setbits(x, p, n, y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the other
 * bits unchanged.
 */

#include <assert.h>
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
        assert(setbits(21, 4, 3, 28) == 17);
        return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
        unsigned mask,
                 shift;

        mask = ~(~0 << n);
        shift = p + 1 - n;

        return (x & ~(mask << shift)) | ((y & mask) << shift);
}
