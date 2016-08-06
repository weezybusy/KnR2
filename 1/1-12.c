/*
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

#define IN  1
#define OUT 0

int main(void)
{
        int c,
            state;

        state = IN;
        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\n' || c == '\t') {
                        if (state == OUT) {
                                putchar('\n');
                                state = IN;
                        }
                } else {
                        putchar(c);
                        state = OUT;
                }
        }

        return 0;
}
