/*
 * Exercise 2-8
 *
 * Write a function rightrot(x, n) that returns the value of the integer x
 * rotated to the right by n bit positions.
 */

#include <assert.h>
#include <limits.h>
#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
        assert(rightrot(24, 3) == 3);
        assert(rightrot(1, 16) == 65536);
        return 0;
}

unsigned rightrot(unsigned x, int n)
{
        unsigned mask,
                 rotbits;

        mask = ~(~0 << n);
        rotbits = x & mask;

        return ((x >> n) | (rotbits << (sizeof(x) * CHAR_BIT - n)));
}
