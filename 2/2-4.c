/*
 * 2-4
 * Write an alternate version of squeeze(s1, s2) that deletes each character
 * in the string s1 that matches any character in the string s2.
 */

#include <stdio.h>

#define FALSE 0
#define TRUE  1

void squeeze(char s1[], char s2[]);

int main(void)
{
        char s1[] = "helloworld";
        char s2[] = "lord";

        puts(s1);
        squeeze(s1, s2);
        puts(s1);

        return 0;
}

void squeeze(char s1[], char s2[])
{
        int i, j, k, found;

        for (i = j = 0; s1[i] != '\0'; ++i) {
                found = FALSE;
                for (k = 0; s2[k] != '\0'; ++k) {
                        if (s1[i] == s2[k]) {
                                found = TRUE;
                                break;
                        }
                }
                if (!found)
                        s1[j++] = s1[i];
        }
        s1[j] = '\0';
}
