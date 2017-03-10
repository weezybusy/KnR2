/*
 * Exercise 5-3.
 *
 * Write a pointer version of the function strcat that we showed in
 * Chapter 2: strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>
#include <string.h>

#define LEN 128

char *str_cat(char *dest, const char *src);

int main(void)
{
        char s1[LEN] = "hello";
        char *s2 = " world";
        if (str_cat(s1, s2))
                printf("%s\n", s1);
        else
                fprintf(stderr, "str_cat: failed concatenate strings.\n");

        return 0;
}

// Concatenates strings. Assumes dest has enough space to hold final string.
char *str_cat(char *dest, const char *src)
{
        char *result;

        if (dest == NULL || src == NULL)
                return NULL;

        result = dest;

        while (*dest)
                ++dest;

        while ((*dest++ = *src++) != '\0')
                continue;

        return result;
}
