/*
 * Exercise 2-2
 *
 * for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *         s[i] = c;
 * Write a loop equivalent to the for loop above without using && or ||.
 */

#include <stdio.h>

#define MAXLINE 1024

int getline(char s[], int lim);

int main(void)
{
        char line[MAXLINE];

        getline(line, MAXLINE);
        puts(line);

        return 0;
}

int getline(char s[], int lim)
{
        int c, i;

        i = 0;
        while (i < (lim - 1)) {
                c = getchar();
                if (c == EOF) break;
                else if (c == '\n') break;
                else s[i++] = c;
        }
        s[i] = '\0';

        return i;
}
