/*
 * Exercise 5-6.
 *
 * Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing. Good possibilities include
 * getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters
 * 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUMBER  0

int getop(char *s)
{
        int getch(void);
        void ungetch(int c);

        int c;

        while ((*s = c = getch()) == ' ' || c == '\t')
                continue;
        *++s = '\0';
        if (!isdigit(c) && c != '.')
                return c;
        if (isdigit(c))
                while (isdigit(*++s = c = getch()))
                        continue;
        if (c == '.')
                while (isdigit(*++s = c = getch()))
                        continue;
        *s = '\0';
        if (c != EOF)
                ungetch(c);

        return NUMBER;
}

#define BUFSIZE 128

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZE)
                fprintf(stderr, "ungetch: too many characters.\n");
        else
                buf[bufp++] = c;
}

int strindex(char *s, char *t)
{
        char *p1;
        char *p2;
        char *p3;

        if (s == NULL || t == NULL)
                return -2;

        for (p1 = s; *p1; ++p1) {
                for (p2 = p1, p3 = t; *p3 && *p2 == *p3; ++p2, ++p3)
                        continue;
                if ((p3 - t) > 0 && *p3 == '\0')
                        return p1 - s;
        }

        return -1;
}

void itoa(char *s, int n)
{
        void reverse(char *s);
        char *temp;
        int sign;

        sign = 0;
        if (n < 0) {
                sign = 1;
                n = -n;
        }

        temp = s;
        while (n) {
                *temp++ = '0' + n % 10;
                n /= 10;
        }

        if (sign)
                *temp++ = '-';

        *temp = '\0';

        reverse(s);
}

void reverse(char *s)
{
        char *start;
        char *end;
        char temp;

        if (s == NULL)
                return;

        start = end = s;

        while (*end)
                ++end;
        --end;

        while (end - start >= 0) {
                temp = *start;
                *start++ = *end;
                *end-- = temp;
        }
}

int atoi(char *s)
{
        int number;
        int sign;

        while (isspace(*s))
                ++s;

        sign = (*s == '-') ? -1 : 1;

        if (*s == '-' || *s == '+')
                ++s;

        for (number = 0; isdigit(*s); ++s)
                number = number * 10 + (*s - '0');

        return number * sign;
}

int getline(char *s, size_t n)
{
        int c;
        size_t i;

        for (i = 0; i < n - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                *s++ = c;

        if (c == '\n') {
                *s++ = '\n';
                ++i;
        }

        *s = '\0';

        return i;
}
