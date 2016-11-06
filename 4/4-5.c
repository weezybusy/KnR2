/*
 * Exercise 4-5
 *
 * Add access to library functions like sin, exp, and pow. See <math.h> in
 * Appendix B, Section 4.
 */

#include <ctype.h>
#include <math.h>   /* for fmod() */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h> /* for strlen() */

#define MAXOP  100  /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define COS    '1'  /* signal that a cos function was found */
#define SIN    '2'  /* signal that a sin function was found */
#define POW    '3'  /* signal that a pow function was found */
#define EXP    '4'  /* signal that a exp function was found */
#define SQRT   '5'  /* signal that a sqrt function was found */

int getop(char []);
void push(double);
double pop(void);
void printtop(void);
void dupetop(void);
void swaptop(void);
void clrstack(void);
int cmp(char s1[], char s2[]);

int sign = 1;        /* -1 if operand is negative */
int popallowed = 1;  /* 0 if pop is not allowed when pressed Enter */

int main(void)
{
        /* reverse Polish calculator */

        int type;
        double op2;
        char s[MAXOP];

        while ((type = getop(s)) != EOF) {
                switch (type) {
                case NUMBER:
                        push(atof(s) * sign);
                        sign = 1;    /* reset sign */
                        break;
                case SIN:
                        push(sin(pop()));
                        break;
                case COS:
                        push(cos(pop()));
                        break;
                case EXP:
                        push(exp(pop()));
                        break;
                case POW:
                        op2 = pop();
                        push(pow(pop(), op2));
                        break;
                case SQRT:
                        push(sqrt(pop()));
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
                        if (popallowed)
                                printf("\t%.8g\n", pop());
                        else
                                popallowed = 1;
                        break;
                case '?':
                        printtop();
                        break;
                case '&':
                        dupetop();
                        break;
                case '~':
                        swaptop();
                        break;
                case '!':
                        clrstack();
                        break;
                default:
                        printf("error: unknown command\n");
                        break;
                }
        }
        return 0;
}

#define MAXVAL 100   /* maximum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

void push(double f)
{
        /* push: push f onto value stack */

        if (sp < MAXVAL)
                val[sp++] = f;
        else
                printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
        /* pop: pops top element from the stack */

        if (sp > 0)
                return val[--sp];
        else {
                printf("error: stack empty\n");
                return 0.0;
        }
}

void printtop(void)
{
        /* printtop: prints the top element of the stack without popping */

        if (sp > 0)
                printf("%g\n", val[sp-1]);
        else
                printf("nothing to show\n");

        popallowed = 0;
}

void dupetop(void)
{
        /* dupetop: duplicates the top element of the stack */

        double temp;

        if (sp > 0) {
                temp = pop();
                push(temp);
                push(temp);
        } else
                printf("nothing to duplicate\n");
}

void swaptop(void)
{
        /* swaptop: swaps two top elements of the stack */

        double temp1;
        double temp2;


        if (sp > 1) {
                temp1 = pop();
                temp2 = pop();
                push(temp1);
                push(temp2);
        } else
                printf("have less then two values in stack\n");
}

void clrstack(void)
{
        /* clrstack: clears the stack */

        sp = 0;
        printf("stack was creared\n");
        popallowed = 0;
}

int cmp(char s1[], char s2[])
{
        /* cmp: compares two strings.
                returns 1 if they are equal, 0 otherwise */

        int i;

        if (strlen(s1) != strlen(s2))
                return 0;
        i = 0;
        while (s1[i] == s2[i] && i < strlen(s1))
                ++i;
        if (s1[i] != '\0')
                return 0;

        return 1;
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
        /* getop: get next character, numeric operand or math function */

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

        if (!isalnum(c) && c != '.')
                return c;    /* not a number or a math function */

        i = 0;
        if (isalpha(c)) {         /* get math function name */
                while (isalpha(s[++i] = c = getch()))
                        continue;
                s[i] = '\0';

                if (c != EOF)
                        ungetch(c);

                if (cmp(s, "sin"))
                        return SIN;
                else if (cmp(s, "cos"))
                        return COS;
                else if (cmp(s, "exp"))
                        return EXP;
                else if (cmp(s, "pow"))
                        return POW;
                else if (cmp(s, "sqrt"))
                        return SQRT;
                else
                        return '_'; /* not a math function */
        }

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
