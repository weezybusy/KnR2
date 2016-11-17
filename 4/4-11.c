/*
 * Exercise 4-11
 *
 * Modify getop so that it doesn't need to use ungetch. Hint: use an internal
 * static variable.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP   128
#define NUMBER  '0'

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(void)
{
        int type;
        double op2;
        char s[MAXOP];

        while ((type = getop(s)) != EOF) {
                switch (type) {
                case NUMBER:
                        push(atof(s));
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

#define MAXVAL 128

int sp = 0;
double val[MAXVAL];

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
        /* pop: pop element from the stack */

        if (sp > 0)
                return val[--sp];
        else {
                printf("error: stack empty\n");
                return 0.0;
        }
}

int getop(char s[])
{
        /* getop: get next character or numeric operand */

        int i, c;
        static int buf;

        s[0] = c = (buf) ? buf : getchar();
        buf = 0;

        while (c == ' ' || c == '\t') {
                s[0] = c = getchar();
                continue;
        }
        s[1] = '\0';

        if (!isdigit(c) && c != '.')
                return c;

        i = 0;
        if (isdigit(c))
                while (isdigit(s[++i] = c = getchar()))
                        continue;

        if (c == '.')
                while (isdigit(s[++i] = c = getchar()))
                        continue;
        s[i] = '\0';

        buf = c;

        return NUMBER;
}
