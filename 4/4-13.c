/*
 * Exercise 4-13
 *
 * Write a recursive version of the function reverse(s), which reverses the
 * string s in place.
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 128

void reverse(char s[]);

int main(void)
{
        char s1[MAXLEN] = "";
        char s2[MAXLEN] = "Test string.";
        char s3[MAXLEN] = "Another test string.";
        char s4[MAXLEN] = "The last test string.";

        printf("%s -> ", s1);
        reverse(s1);
        printf("%s -> ", s1);
        reverse(s1);
        printf("%s\n", s1);

        printf("%s -> ", s2);
        reverse(s2);
        printf("%s -> ", s2);
        reverse(s2);
        printf("%s\n", s2);

        printf("%s -> ", s3);
        reverse(s3);
        printf("%s -> ", s3);
        reverse(s3);
        printf("%s\n", s3);

        printf("%s -> ", s4);
        reverse(s4);
        printf("%s -> ", s4);
        reverse(s4);
        printf("%s\n", s4);

        return 0;
}

void reverse(char s[])
{
        /* reverse: recursively reverses string s in place */

        static int start;
        int end;
        int tmp;

        end = strlen(s) - start - 1;
        if (start >= end) {
                start = 0;
                return;
        }
        tmp = s[start];
        s[start++] = s[end];
        s[end--] = tmp;
        reverse(s);
}
