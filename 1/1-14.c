/*
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 */

#include <stdio.h>

#define MAXCHARSNUM 94

int main(void)
{
        int c;
        int chars[MAXCHARSNUM] = { 0 };
        int height = 0;

        printf("\nInput: ");
        while ((c = getchar()) != EOF)
                if (c >= 33 && c <= 126) {
                        ++chars[c - 33];
                        if (chars[c - 33] > height)
                                height = chars[c - 33];
                }

        printf("\n%29cx-axis = character    y-axis = quantity\n\n", ' ');

        for (int row = height; row > 0; --row) {
                printf("%3d ", row);
                for (int col = 0; col < MAXCHARSNUM; ++col) {
                        if (row - chars[col] > 0)
                                printf("%c", ' ');
                        else
                                printf("%c", '|');
                }
                putchar('\n');
        }

        printf("    ");
        for (int col = 0; col < MAXCHARSNUM; ++col)
                putchar('-');

        printf("\n    ");
        for (int col = 0; col < MAXCHARSNUM; ++col)
                printf("%c", col + 33);
        printf("\n\n");

        return 0;
}
