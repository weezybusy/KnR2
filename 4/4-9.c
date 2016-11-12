/*
 * Exercise 4-9
 *
 * Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
 * what their properties ought to be if an EOF is pushed back, then implement
 * your design.
 */

#include <stdio.h>

int getch(void);
void ungetch(int);

int main(void)
{
        /* test for getch() and ungetch() */

        int c;

        ungetch(EOF);
        while ((c = getch()) != EOF)
                putchar(c);

        return 0;
}

#define BUFSIZE 100

/* changed buf type to int so we can properly handle EOF */
int buf[BUFSIZE]; /* buffer for ungetch() */
int bufp = 0;     /* next free position in buf */

int getch(void)
{
        /* getch: get a (possibly pushed back) character */

        return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        /* ungetch: push character back on input */

        if(bufp >= BUFSIZE)
                printf("error: no space left\n");
        else
                buf[bufp++] = c;
}
