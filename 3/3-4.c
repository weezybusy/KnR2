/*
 * Exercise 3-4
 *
 * In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to -(2 to
 * the power (wordsize - 1)). Explain why not. Modify it to print that value
 * correctly regardless of the machine on which it runs. 
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define LIM 128

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
        char s[LIM];

        printf("%-13s %s\n", "number", "string");
        printf("--------------------\n");
        itoa(INT_MIN, s);
        printf("%-13d %s\n", INT_MIN, s);
        itoa(-93048, s);
        printf("%-13d %s\n", -93048, s);
        itoa(INT_MAX, s);
        printf("%-13d %s\n", INT_MAX, s);
        itoa(56748, s);
        printf("%-13d %s\n", 56748, s);

        return 0;
}

void itoa(int n, char s[])
{
        int i, sign;
        unsigned un;

        un = ((sign = n) < 0) ? -n : n;
        i = 0;

        do {
                s[i++] = un % 10 + '0';
        } while ((un /= 10) > 0);

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

        do {
                temp = s[start];
                s[start] = s[end];
                s[end] = temp;
        } while (start++ < end--);
}
