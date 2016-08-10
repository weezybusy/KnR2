/*
 * Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a
 * fixed set of tab stops, say every n columns. Should n be a variable
 * or a symbolic parameter?
 * Because of the lack of specification I wrote several versions of the program:
 *
 *      1. My favorite. It's simple and doesn't require any buffer.
 *
 *      2. Uses modified getline() function from the book examples.
 *         Instead of add tab to the line, it calculates offset and
 *         adds spaces. So the line includes them.
 *
 *      3. Uses modified main() function from the book example. In this
 *         version the original line remains untouched. Only the output is
 *         modified.
 */

#include <stdio.h>

#define TABSTOP 8

int main(void)
{
        int c;
        int pos;
        int spaces;

        pos = 0;

        while ((c = getchar()) != EOF) {
                if (c == '\n') {
                        putchar(c);
                        pos = 0;
                } else if (c == '\t') {
                        spaces = TABSTOP - (pos % TABSTOP);
                        while (spaces-- != 0) {
                                putchar(' ');
                                ++pos;
                        }
                } else {
                        putchar(c);
                        ++pos;
                }
        }

        return 0;
}

/*
VERSION 2

#include <stdio.h>

#define MAXLEN  1024
#define TABSTOP 8

int getline(char line[], int size);

int main(void)
{
        char line[MAXLEN];
        int len;

        while ((len = getline(line, MAXLEN)) > 0)
                if (len > 1)
                        printf("%s", line);
        return 0;
}

int getline(char line[], int size)
{
        int c;
        int pos;
        int spaces;

        pos = 0;

        while (pos < size - 1 && (c = getchar()) != EOF && c != '\n') {
                if (c == '\t') {
                        spaces = TABSTOP - (pos % TABSTOP);
                        while (spaces-- != 0)
                                line[pos++] = ' ';
                } else
                        line[pos++] = c;
        }

        if (c == '\n')
                line[pos++] = '\n';

        line[pos] = '\0';

        return pos;
}


VERSION 3

#include <stdio.h>

#define MAXLEN  1024
#define TABSTOP 8

int getline(char line[], int size);

int main(void)
{
        char line[MAXLEN];
        int len;
        int spaces;
        int pos;
        int count;

        while ((len = getline(line, MAXLEN)) > 0) {
                pos = 0;
                for (count = 0; line[pos] != '\0'; ++count) {
                        if (line[pos] == '\t') {
                                spaces = TABSTOP - (count-- % TABSTOP);
                                while (spaces-- != 0) {
                                        putchar('_');
                                        ++count;
                                }
                        } else
                                putchar(line[pos]);
                        ++pos;
                }
        }

        return 0;
}

int getline(char line[], int size)
{
        int i;
        int c;

        for (i = 0; i < size - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
                line[i] = c;
        }

        if (c == '\n')
                line[i++] = '\n';

        line[i] = '\0';

        return i;
}
*/
