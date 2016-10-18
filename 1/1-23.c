/*
 * 1-23
 * Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments do not
 * nest. 
 */

#include <stdio.h>

#define MAXLEN 1024

char line[MAXLEN];

int getline(void)
{
        int c, i;

        for (i = 0; i < MAXLEN && (c = getchar()) != EOF && c != '\n'; ++i)
                line[i] = c;

        if (c == '\n')
                line[i++] = c;
        line[i] = '\0';

        return i;
}

int main(void)
{
        int len;
        int prev;
        int comment;
        int string;
        int j;
        char uncommented[MAXLEN];

        prev = '\0';
        comment = 0;
        string = 0;
        j = 0;

        while ((len = getline()) > 0) {
                for (int i = 0; i < len; ++i) {
                        if (line[i] == '/') {
                                if (line[i + 1] == '*' && !comment && !string)
                                        comment = 1;
                                else if (prev == '*' && comment)
                                        comment = 0;
                                else
                                        uncommented[j++] = line[i];
                                prev = line[i];
                                continue;
                        }

                        if (line[i] == '"' && prev != '\\' && !comment)
                                string = string ? 0 : 1;

                        if (!comment)
                                uncommented[j++] = line[i];
                        prev = line[i];
                }
        }
        uncommented[j] = '\0';
        puts(uncommented);
        return 0;
}
