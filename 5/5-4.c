/*
 * Exercise 5-4.
 *
 * Write the function strend(s,t), which returns 1 if the string t
 * occurs at the end of the string s, and zero otherwise.
 */

#include <stdio.h>
#include <string.h>

int strend(const char *s, const char *t);

int main(void)
{
        char *s1 = "hello";
        char *s2 = "llo";

        printf("%i\n", strend(s1, s2));

        return 0;
}

int strend(const char *s, const char *t)
{
        size_t s_len;
        size_t t_len;

        if (s == NULL || t == NULL)
                return -1;

        s_len = strlen(s);
        t_len = strlen(t);

        if (s_len < t_len)
                return -1;

        return (strcmp(s + (s_len - t_len), t)) ? 1 : 0;
}
