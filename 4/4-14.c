/*
 * Exercise 4-14
 *
 * Define a macro swap(t, x, y) that interchanges two arguments of type t.
 * (Block structure will help.)
 */

#include <stdio.h>

#define SWAP(t, x, y)       \
        do {                \
                t temp = x; \
                x = y;      \
                y = temp;   \
        } while (0)

int main(void)
{
        int x = 1;
        int y = 2;
 
        printf("x = %d, y = %d\n", x, y);
        SWAP(int, x, y);
        printf("x = %d, y = %d\n", x, y);

        return 0;
}
