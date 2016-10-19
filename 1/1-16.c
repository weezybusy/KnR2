/*
 * Exercise 1-16
 *
 * Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrary long input lines, and
 * as much as possible of the text.
 */

#include <stdio.h>

#define MAXLINE 15

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
        int c;
        int count;
        int len;
        int max;
        char line[MAXLINE];
        char longest[MAXLINE];

        max = 0;
        count = 1;

        printf("%d) ", count);
        while ((len = getline(line, MAXLINE)) > 0) {

                if (len == (MAXLINE - 1) && line[MAXLINE - 2] != '\n')
                        while ((c = getchar()) != EOF && c != '\n')
                                ++len;

                if (len > max) {
                        max = len;
                        copy(longest, line);
                }

                printf("%d) ", ++count);
        }

        printf("---\n");

        if (max > 0) {
                printf("The longest line is %d characters long:\n", max);
                printf("> %s", longest);

                /* print new line if longest line doesn't have it */
                if (max >= (MAXLINE - 1) && longest[MAXLINE - 2] != '\n')
                        printf("...\n");
        }

        return 0;
}

int getline(char line[], int maxline)
{
        int c;
        int i;

        for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                line[i] = c;

        if (c == '\n') {
                line[i] = c;
                ++i;
        }

        line[i] = '\0';

        return i;
}

void copy(char to[], char from[])
{
        int i;

        i = 0;
        while ((to[i] = from[i]) != '\0')
                ++i;
}
