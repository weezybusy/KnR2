/*
 * Exercise 3-3
 *
 * Write a function expand(s1, s2) that expands shorthand notations like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits, and be prepared to handle cases like
 * a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally.
 */

#include <ctype.h>
#include <stdio.h>

#define LIM 128

int expandable(int a, int b, int c);
int samecase(int a, int b);
void expand(char s1[], char s2[]);

int main(void)
{
        char *tests[] = {
                "-",
                "a",
                "a-",
                "a-z",
                "A-Z",
                "0-5",
                "text a-Z text",
                "text c-a text",
                "text a----z text",
                "text a-z text",
                "text A-Z text",
                "text 0-9 text",
                "text 5-1 text",
                "text c-nB-H text",
                "text a-d0-9 text",
                "text A-M0-9 text",
                "text a-cF-L4-7 text",
                "text a-c- text",
                "text a-d-m text",
                "text A-D-M text",
                "text 0-5-9 text",
                "text -a-d-m text",
                "text -A-D-M text",
                "text -0-5-9 text"
        };
        char expanded[LIM];
        int len;

        len = sizeof(tests) / sizeof(tests[0]);

        for (int i = 0; i < len; ++i) {
                expand(tests[i], expanded);
                printf("%-20s ->  %s\n", tests[i], expanded);
        }
        return 0;
}

void expand(char s1[], char s2[])
{
        int i, j, start, end;

        i = j = 0;
        while (s1[i]) {
                while (expandable(s1[i], s1[i+1], s1[i+2])) {
                        start = s1[i];
                        end = s1[i+2];
                        while (start < end && j < (LIM - 1))
                                s2[j++] = start++;
                        i += 2;
                }
                s2[j++] = s1[i++];
        }
        s2[j] = '\0';
}

int expandable(int a, int b, int c)
{
        int valid_letters;
        int valid_digits;

        valid_letters = isalpha(a) && isalpha(c) && samecase(a, c);
        valid_digits = isdigit(a) && isdigit(c);

        return (valid_letters || valid_digits) && (a < c) && (b == '-');
}

int samecase(int a, int b)
{
        return (islower(a) && islower(b)) || (isupper(a) && isupper(b));
}
