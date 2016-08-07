/*
 * Write a program to remove trailing blanks and tabs from each line of
 * input, and to delete entirely blank lines.
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int getline(char line[], int size); 

int main(void)
{
        char line[MAXLEN];
        char striped[MAXLEN];
        int len;
        int count;
        int i, j;

        /* set line counter, which will be used in prompt */
        count = 1;

        /* prepare to get line */
        printf("%d) ", count);

        while ((len = getline(line, MAXLEN)) > 0) {
                
                /* find first non-blank character from the left */
                for (i = 0; line[i] == '\t' || line[i] == ' '; ++i, --len)
                        continue;

                /* make line copy without spaces and tabs from the left */
                for (j = 0; line[i] != '\0'; ++j)
                        striped[j] = line[i++];
                striped[j] = '\0';

                /* find first non-blank character from the right */
                while (--len > 0 && (striped[len] == '\n' ||
                                     striped[len] == '\t' ||
                                     striped[len] == ' '))
                        continue;

                /* if there's two or more characters left,
                   it's not a blank line, so we can complete
                   the line and print the result */
                if (len > 1) {
                        striped[++len] = '\n';
                        striped[++len] = '\0';
                        printf("line: %s", striped);
                        printf("length: %d\n", len);
                }

                /* prepare to get new line */
                printf("%d) ", ++count);
        }

        printf("Done!\n");

        return 0;
}

int getline(char line[], int size)
{
        int c;
        int i;

        for (i = 0; i < size - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                line[i] = c;

        if (c == '\n')
                line[i++] = '\n';

        line[i] = '\0';

        return i;
}
