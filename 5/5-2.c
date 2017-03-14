/*
 * Exercise 5-2
 *
 * Write getfloat, the floating-point analog of getint. What type does
 * getfloat return as its function value?
 */

#include <stdio.h>
#include <ctype.h>

int getfloat(float *f);

int main(void)
{
        float f;

        if (getfloat(&f))
                printf("%g\n", f);

        return 0;
}

int getch(void);
void ungetch(int);

int getfloat(float *pf)
{
        /* Get next float from input into *pf. */

        int c;
        int sign;

        while (isspace(c = getch()))
                continue;

        if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
                printf("%c is not a number or sign\n", c);
                ungetch(c);
                return 0;
        }

        sign = (c == '-') ? -1 : 1;

        if (c == '+' || c == '-') {
                c = getch();
                if (!isdigit(c)) {
                        /* push both characters back on input */
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
