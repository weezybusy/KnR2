/*
 * Write a program to print all input lines that are longer than 80 characters.
 * Commented variant limits line length to 1000 characters and uncommented
 * variant do not.
 *
 * #include <stdio.h>
 * 
 * #define MAXLEN 1000
 * #define MINLEN 81
 * 
 * int getline(char line[], int size); 
 * 
 * int main(void)
 * {
 *         char line[MAXLEN];
 *         int len;
 *         int count;
 * 
 *         count = 1;
 *         printf("%d) ", count);
 *         while ((len = getline(line, MAXLEN)) > 0) {
 *                 if (len > MINLEN)
 *                         printf("-\n%s-\n", line);
 *                 printf("%d) ", ++count);
 *         }
 *         printf("Done!\n");
 * 
 *         return 0;
 * }
 *
 * int getline(...) {...}
 */

#include <stdio.h>

#define MINLEN 81

int getline(char line[], int size); 

int main(void)
{
        char line[MINLEN];
        int len;
        int c;
        int count;

        count = 1;
        printf("%d) ", count);
        while ((len = getline(line, MINLEN)) > 0) {
                if (len == MINLEN - 1 && line[MINLEN - 2] != '\n') {
                        printf("-\nLINE CONTENTS: %s", line);
                        while ((c = getchar()) != EOF && c != '\n')
                                putchar(c);
                        printf("\n-\n"); 
                }
                printf("%d) ", ++count);
        }
        printf("Done!\n");

        return 0;
}

int getline(char line[], int size)
{
        int c;
        int i;

        for (i = 0; i < (size - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
                line[i] = c;

        if (c == '\n')
                line[i++] = '\n';

        line[i] = '\0';

        return i;
}
