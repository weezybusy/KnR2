/*
 * Exercise 3-5
 *
 * Write the function itob(n, s, b) that converts the integer n into a base
 * b character representation in the string s. In particular, itob(n, s, 16)
 * formats n as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <string.h>

#define LIM 128
#define DIGITS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define TESTSNUM 6

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
        char s[LIM] = { 0 };
        int tests[TESTSNUM] = { 186, -125, 87634, -379, 17, 93 };
        int bases[TESTSNUM] = { 2, 8, 10, 16, 24, 36};

        for (int i = 0; i < TESTSNUM; ++i) {
                putchar('\n');
                for (int j = 0; j < TESTSNUM; ++j) {
                        itob(tests[j], s, bases[i]);
                        printf("%8d base %2d = %s\n", tests[j], bases[i], s);
                }
        }
        putchar('\n');

        return 0;
}

void itob(int n, char s[], int b)
{
        /* Assumes 2 <= n <= 36 */

        int i, sign;
        unsigned un;

        un = ((sign = n) < 0) ? -n : n;
        i = 0;

        do {
                s[i++] = DIGITS[un % b];
        } while ((un /= b) > 0);

        if (sign < 0)
                s[i++] = '-';
        s[i] = '\0';

        reverse(s);
}

void reverse(char s[])
{
        int start, end, temp;

        start = 0;
        end = strlen(s) - 1;

        while (start < end) {
                temp = s[start];
                s[start++] = s[end];
                s[end--] = temp;
        }
}
