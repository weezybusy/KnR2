/*
 * Exercise 5-1
 *
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the input.
 */

#include <stdio.h>
#include <ctype.h>

int getint(int *);

int main(void)
{
        int i;

        if (getint(&i))
                printf("%d\n", i);

        return 0;
}

int getch(void);
void ungetch(int);

int getint(int *pn)
{
        /* Get next integer from input into *pn. */

        int c;
        int sign;

        while (isspace(c = getch()))
                continue;

        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                printf("%c is not a number or sign\n", c);
                ungetch(c);
                return 0;
        }

        sign = (c == '-') ? -1 : 1;

        if (c == '+' || c == '-') {
                c = getch();
                if (!isdigit(c)) {
                        /* push both character back on input */
                        ungetch((sign == 1) ? '+' : '-');
                        ungetch(c);
                        return 0;
                }
        }

        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');

        *pn *= sign;

        if (c != EOF)
                ungetch(c);

        return c;
}

#define BUFSIZE 128

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
        /* Get character from the standard input. */

        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        /* Push character back on input. */

        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}
