/*
 * Write a function `reverse` that reverses the character string `s`.
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLEN 1000

int getline(char line[], int size);
void reverse(char s[], int size);

int main(void)
{
        char line[MAXLEN];
        int len;
        int count;

        count = 1;

        printf("%d) ", count);
        while((len = getline(line, MAXLEN)) > 0) {
                if (len > 1) {
                        reverse(line, len);
                        printf("-\n%s-\n", line);
                }
                printf("%d) ", ++count);
        }

        printf("\nDone!\n");

        return 0;
}

void reverse(char s[], int size)
{
        for (int i = 0, j = size - 1; i < j; --j) {
                if (s[j] != '\n') {
                        int tmp = s[i];
                        s[i] = s[j];
                        s[j] = tmp;
                        ++i;
                }
        }
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
