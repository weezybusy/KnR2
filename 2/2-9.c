/*
 * Exercise 2-9
 *
 * In a two's complement number system, x &= (x - 1) deletes the rightmost
 * 1-bit in x. Explain why. Use this observation to write a faster version of
 * bitcount.
 */

#include <assert.h>
#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
        assert(bitcount(0) == 0);
        assert(bitcount(2) == 1);
        assert(bitcount(5) == 2);
        assert(bitcount(7) == 3);

        return 0;
}

int bitcount(unsigned x)
{
        int b;

        for (b = 0; x != 0; x &= (x - 1))
                ++b;
        return b;
}
