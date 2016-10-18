/*
 * 1-21
 * Write a program entab that replaces strings of blanks by the minimum
 * number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would
 * suffice to reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define MAXLEN  1024
#define TABSTOP 4

int getline(char line[], int size);

int main(void)
{
        char line[MAXLEN];
        int len;
        int tabs;
        int spaces;
        int spaces_total;
        int i;

        while ((len = getline(line, MAXLEN)) > 0) {
                i = 0;
                while (i < len) {
                        if (line[i] == ' ') {
                                spaces_total = 0;
                                while (line[i++] == ' ')
                                        ++spaces_total;
                                --i;
                                tabs = spaces_total / TABSTOP;
                                spaces = spaces_total % TABSTOP;
                                while (tabs-- > 0)
                                        printf("\\t");
                                while (spaces-- > 0)
                                        putchar('_');
                        } else
                                putchar(line[i++]);
                }
        }

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
