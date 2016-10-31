/*
 * Exercise 4-1
 *
 * Write the function strrindex(s, t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>

#define MAXLINE 1024

int getline(char line[], int max);
int strrindex(char src[], char searchfor[]);

char pattern[] = "ould";

int main(void)
{
        char line[MAXLINE];
        int found;
        int index;

        found = 0;

        while (getline(line, MAXLINE) > 0) {
                index = strrindex(line, pattern);
                if (index >= 0) {
                        int i = 0; 
                        while (line[i]) {
                                if (i == index)
                                        printf(" -> ");
                                putchar(line[i++]);
                        }
                        ++found;
                }
        }
        printf("%d\n", found);

        return 0;
}

int getline(char s[], int lim)
{
        int c, i;

        i = 0;
        while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
                s[i++] = c;
        if (c == '\n')
                s[i++] = c;
        s[i] = '\0';
        return i;
}

int strrindex(char s[], char t[])
{
        int i, j, k, rindex;

        rindex = -1;
        for (i = 0; s[i]; ++i) {
                for (j = i, k = 0; t[k] && s[j] == t[k]; ++j, ++k)
                        continue;
                if (k > 0 && t[k] == '\0')
                        rindex = i;
        }
        return rindex;
}
