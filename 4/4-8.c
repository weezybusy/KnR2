/*
 * Exercise 4-8
 *
 * Suppose that there will never be more than one character of pushback.
 * Modify getch and ungetch accordingly.
 */

#include <stdio.h>

int getch(void);
void ungetch(int);

int main(void)
{
        /* test for new getch() and ungetch() */

        int c;

        c = getch();
        putchar(c);
        ungetch(c);
        c = getch();
        putchar(c);
        c = getch();
        if (c == '\n')
                puts("n");

        return 0;
}

#define EMPTY -2

int buf = EMPTY; /* buffer for ungetch() */

int getch(void)
{
        /* getch: get a (possibly pushed back) character */

        int tmp;

        if (buf != EMPTY) {
                tmp = buf;
                buf = EMPTY;
        } else
                tmp = getchar();
        return tmp;
}

void ungetch(int c)  
{
        /* ungetch: push character back on input */

        if (buf != EMPTY)
                puts("ungetch: no space left.");
        else
                buf = c;
}
