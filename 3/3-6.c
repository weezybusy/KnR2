/*
 * Exercise 3-6
 *
 * Write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>

#define LIM 128
#define DIGITS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define TESTSNUM 6

void itob(int n, char s[], int b, int f);
void reverse(char s[]);

int main(void)
{
        char s[LIM] = { 0 };
        int tests[TESTSNUM] = { 186, -125, 8763, -379, 17, 93 };
        int bases[TESTSNUM] = { 2, 8, 10, 16, 24, 36};

        printf("field width: %d\n", 10);
        itob(tests[0], s, bases[0], 10);
        printf("%d base %d = %s\n\n", tests[0], bases[0], s);

        printf("field width: %d\n", 5);
        itob(tests[1], s, bases[1], 5);
        printf("%d base %d = %s\n\n", tests[1], bases[1], s);

        printf("field width: %d\n", 6);
        itob(tests[2], s, bases[2], 6);
        printf("%d base %d = %s\n\n", tests[2], bases[2], s);

        printf("field width: %d\n", 8);
        itob(tests[3], s, bases[3], 8);
        printf("%d base %d = %s\n\n", tests[3], bases[3], s);

        printf("field width: %d\n", 15);
        itob(tests[4], s, bases[0], 15);
        printf("%d base %d = %s\n\n", tests[4], bases[4], s);

        printf("field width: %d\n", 2);
        itob(tests[5], s, bases[5], 2);
        printf("%d base %d = %s\n", tests[5], bases[5], s);

        return 0;
}

void itob(int n, char s[], int b, int f)
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

        /* Add padding if needed */
        while (strlen(s) < f) {
                s[i++] = ' ';
                s[i] = '\0';
        }

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
