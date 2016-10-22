/*
 * Exercise 2-10
 *
 * Rewrite the function lower, which converts upper case letters to lower
 * case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

int lower(int c);

int main(void)
{
        char test_word[] = "HeLlO wOrLd!";
        int i;

        printf("Original word:   %s\n", test_word);
        printf("Lowercased word: ");

        i = 0;
        while (test_word[i] != '\0')
                putchar(lower(test_word[i++]));
        putchar('\n');

        return 0;
}

int lower(int c)
{
        return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A': c;
}
