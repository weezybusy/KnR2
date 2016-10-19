/*
 * Exercise 1-22
 *
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define BUFFER 1024
#define BORDER 80

int main(void)
{
        char line[BUFFER];
        int ch;
        int i;
        int count;
        int last_blank_index;

        last_blank_index = 0;
        count = 0;

        printf("> ");
        for (i = 0; i < BUFFER - 1 &&
                    (ch = getchar()) != EOF && ch != '\n'; ++i) {
                ++count;
                line[i] = ch;
                /* Save index of the last blank */
                if (ch == ' ' || ch == '\t')
                        last_blank_index = i;
                /* Check if input exceeds its limit */
                if (count > BORDER) {
                        /* Handle the case with no blanks in string */
                        if (last_blank_index == 0) {
                                line[i++] = '\n';
                                count = 0;
                        /* Handle the case with blanks in string */
                        } else {
                                line[last_blank_index] = '\n';
                                count = i - last_blank_index;
                                last_blank_index = 0;
                        }
                }
        }

        if (ch == '\n')
                line[i++] = '\n';
        line[i] = '\0';

        puts("-");
        printf("%s", line);
        puts("-");

        return 0;
}
