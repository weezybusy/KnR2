/*
 * Exercise 4-3
 *
 * Given the basic framework, it's straightforward to extend the calculator.
 * Add the modulus (%) operator and provisions for negative numbers.
 */

#include <ctype.h>
#include <math.h>   /* for fmod() */
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
int sign = 1;        /* -1 if operand is negative */

/* reverse Polish calculator */
int main(void)
{
        int type;
        double op2;
        char s[MAXOP];

        while ((type = getop(s)) != EOF) {
                switch (type) {
                case NUMBER:
                        push(atof(s) * sign);
                        sign = 1;    /* reset sign */
                        break;
                case '+':
                        push(pop() + pop());
                        break;
                case '*':
                        push(pop() * pop());
                        break;
                case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                case '/':
                        op2 = pop();
                        if (op2 != 0.0)
                                push(pop() / op2);
                        else
                                printf("error: zero devision\n");
                        break;
                case '%':
                        op2 = pop();
                        if (op2 != 0)
                                push(fmod(pop(), op2));
                        else
                                printf("error: zero devision\n");
                        break;
                case '\n':
                        printf("\t%.8g\n", pop());
                        break;
                default:
                        printf("error: unknown command %s\n", s);
                        break;
                }
        }
        return 0;
}

#define MAXVAL 100   /* maximum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f)
{
        if (sp < MAXVAL)
                val[sp++] = f;
        else
                printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
        if (sp > 0)
                return val[--sp];
        else {
                printf("error: stack empty\n");
                return 0.0;
        }
}

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
        int i, c, temp;

        while ((s[0] = c = getch()) == ' ' || c == '\t')
                continue;

        s[1] = '\0';

        if (c == '-') {
                /* if next character is digit, it's a sign */
                if (isdigit(temp = getch())) {
                        s[0] = temp;
                        c = temp;
                        sign = -1;
                } else
                        ungetch(temp); /* it's not a sign */
        }

        if (!isdigit(c) && c != '.')
                return c;              /* not a number */

        i = 0;
        if (isdigit(c))                /* collect integer part */
                while (isdigit(s[++i] = c = getch()))
                        continue;

        if (c == '.')                  /* collect fraction part */
                while (isdigit(s[++i] = c = getch()))
                        continue;
        s[i] = '\0';

        if (c != EOF)
                ungetch(c);

        return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */

int getch(void)      /* get a (possibly pushed-back) character */
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* push character back on input */
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}
