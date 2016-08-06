/*
 * Write a program to print a histogram of the lengths of words in its
 * input. It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#include <stdio.h>

#define IN         1
#define OUT        0
#define WORDLENLIM 10

int main(void)
{
        int c;
        int state = IN;
        int char_count = 0;
        int height = 0;
        int word_len[WORDLENLIM + 2] = { 0 };

        printf("Enter a string: ");
        while ((c = getchar()) != EOF) {
                if (c != ' ' && c != '\n' && c != '\t') {
                        ++char_count;
                        state = OUT;
                } else {
                        if (state == OUT) {
                                if (char_count <= WORDLENLIM)
                                        ++word_len[char_count];
                                else
                                        ++word_len[WORDLENLIM + 1];
                        }
                        char_count = 0;
                        state = IN;
                }
        }

        printf("\n%5cHorizontal-oriented histogram\n", ' ');
        printf("%5c=============================\n", ' ');

        for (int i = 1; i < WORDLENLIM + 2; ++i) {
                if (i == WORDLENLIM + 1)
                        printf("%2s|", "+");
                else
                        printf("%2d|", i);
                for (int j = 0; j < word_len[i]; ++j)
                        putchar('#');
                putchar('\n');
        }

        printf("\n%5cVertical-oriented histogram\n", ' ');
        printf("%5c=============================\n", ' ');

        for (int i = 0; i <= WORDLENLIM + 1; ++i)
                if (word_len[i] > height)
                        height = word_len[i];

        printf(" W\n");
        for (int row = height; row > 0; --row) {
                printf("%2d|", row);
                for (int col = 1; col <= WORDLENLIM + 1; ++col) {
                        if (row - word_len[col] > 0)
                                printf("%2c ", ' ');
                        else
                                printf("%2c ", '#');
                }
                putchar('\n');
        }

        printf("  +-");
        for (int col = 0; col < WORDLENLIM * 3 + 1; ++col)
                putchar('-');

        printf("\n L");
        for (int col = 1; col <= WORDLENLIM; ++col)
                printf("%3d", col);
        printf(" 10+ \n");

        return 0;
}
