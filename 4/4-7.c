/*
 * Exercise 4-7
 *
 * Write a routine ungets(s) that will push back an entire string onto the
 * input. Should ungets know about buf and bufp, or should it just use
 * ungetch?
 */

#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);
void ungets(char []);

int main(void)
{
        /* test for ungets() */

        char s[] = "This is a test string.";
        int c;

        ungets(s);
        while ((c = getch()) != EOF && c != '\n')
                putchar(c);
        return 0;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void)
{
        /* getch: gets a (possibly pushed-back) character */

        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  
{
        /* ungetch: pushes character back on input */

        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}

void ungets(char s[])
{
        /* ungets: push back an entire string onto output */

        int len;

        len = strlen(s);
        while (len > 0)
                ungetch(s[--len]);
}
