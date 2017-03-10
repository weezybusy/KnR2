/*
 * Exercise 5-5.
 *
 * Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at most the first n characters of their
 * argument strings. For example, strncpy(s,t,n) copies at most n
 * characters of t to s. Full descriptions are in Appendix B.
 */

#include <stdio.h>

#define LEN 32
#define INFO_STR(expr) printf(#expr " -> %s\n", expr)
#define INFO_INT(expr) printf(#expr " -> %i\n", expr)

char *str_n_cpy(char *dest, const char *src, size_t len);
char *str_n_cat(char *s, const char *t, size_t n);
int str_n_cmp(const char *s, const char *t, size_t n);
size_t str_len(const char *s);

int main(void)
{
        char s[LEN];
        char *t1 = "hello";
        char *t2 = " world";
        char *t3 = "mellow";
        char *t4 = "hello world";

        INFO_STR(str_n_cpy(s, t1, 2));
        INFO_STR(str_n_cpy(s, t1, str_len(t1)));
        INFO_INT(str_n_cmp(s, t1, 4));
        INFO_INT(str_n_cmp(s, t1, str_len(t1)));
        INFO_STR(str_n_cat(s, t2, str_len(t2)));
        INFO_INT(str_n_cmp(s, t3, 3));
        INFO_INT(str_n_cmp(s, t1, str_len(t4)));

        return 0;
}

char *str_n_cpy(char *dest, const char *src, size_t len)
{
        char *temp;

        if (dest == NULL || src == NULL)
                return NULL;

        for (temp = dest; len && *src; ++temp, ++src, --len)
                *temp = *src;
        *temp = '\0';

        return dest;
}

char *str_n_cat(char *dest, const char *src, size_t n)
{
        char *temp;

        if (dest == NULL || src == NULL)
                return NULL;

        temp = dest;
        while (*temp)
                ++temp;

        for (; n > 0 && *src; ++temp, ++src, --n)
                *temp = *src;
        *temp = '\0';

        return dest;
}

int str_n_cmp(const char *s, const char *t, size_t n)
{
        if (s == NULL || t == NULL || n <= 0)
                return -2;

        for ( ; n > 0; ++s, ++t, --n) {
                if (*s < *t)
                        return -1;
                if (*s > *t)
                        return 1;
        }

        return 0;
}

size_t str_len(const char *s)
{
        size_t result;

        result = 0;
        while (*s++)
                ++result;

        return result;
}
