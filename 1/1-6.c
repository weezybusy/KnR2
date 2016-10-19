/*
 * Exercise 1-6
 *
 * Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

int main(void)
{
        /* on Ctrl+D prints 0, otherwise 1 */
        printf("%d\n", getchar() != EOF);
        return 0;
}
