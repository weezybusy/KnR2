/*
 * Exercise 4-8
 *
 * Suppose that there will never be more than one character of pushback.
 * Modify getch and ungetch accordingly.
 */

#include <stdio.h>
#include <ctype.h>

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

int buf = EOF; /* buffer for ungetch() */

int getch(void)
{
        /* get a (possibly pushed back) character */

        int tmp;

        if (buf != EOF) {
                tmp = buf;
                buf = EOF;
        } else
                tmp = getchar();
        return tmp;
}

void ungetch(int c)  
{
        /* push character back on input */

        if (buf != EOF)
                puts("ungetch: no space left.");
        else
                buf = c;
}
