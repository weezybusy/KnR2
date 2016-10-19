/*
 * Exercise 1-9
 *
 * Write a program to copy its input to its output, replacing
 * each string of one or more blanks by a single blank.
 */

#include <stdio.h>

int main(void)
{
        int c,
            blank;

        blank = 0;
        while ((c = getchar()) != EOF) {
                if (c == ' ') {
                        if (blank == 0) {
                                putchar(c);
                                blank = 1;
                        }
                } else {
                        putchar(c);
                        blank = 0;
                }
        }

        return 0;
}
