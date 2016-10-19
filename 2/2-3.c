/*
 * 2-3
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LIM   64
#define TRUE  1
#define FALSE 0

unsigned int getline(char s[], const unsigned int lim);
void copy(const char src[], char dest[]);
void upper(char s[]);
int is_prefixed(const char s[]);
void del_prefix(char s[], const unsigned int len);
int is_hex_letter(const int c);
int is_valid_hex(const char s[], const unsigned int len);
unsigned int htoi(const char s[]);

int main(void)
{
        char hex[LIM];
        char hex_copy[LIM];
        unsigned int len;
        unsigned int dec;

        printf("> ");
        while ((len = getline(hex, LIM)) > 0) {
                copy(hex, hex_copy);
                upper(hex_copy);
                del_prefix(hex_copy, len);
                if (is_valid_hex(hex_copy, strlen(hex_copy))) {
                        dec = htoi(hex_copy);
                        printf("%u\n", dec);
                } else
                        puts("It's not a hexadecimal number");
                printf("> ");
        }
        return 0;
}

unsigned int getline(char s[], const unsigned int lim)
{
        int c;
        unsigned int i;

        i = 0;
        while (i < (lim - 1)) {
                c = getchar();
                if (c == EOF || c == '\n')
                        break;
                s[i++] = c;
        }
        s[i] = '\0';

        return i;
}

void copy(const char src[], char dest[])
{
        unsigned int i;

        i = 0;
        while ((dest[i] = src[i]) != '\0')
                ++i;
        dest[i] = '\0';
}

void upper(char s[])
{
        unsigned int i;

        i = 0;
        while ((s[i] = toupper(s[i])) != '\0')
                ++i;
}

int is_prefixed(const char s[])
{
        return (s[0] == '0' && s[1] == 'X');
}

void del_prefix(char s[], const unsigned int len)
{
        char temp[len];
        unsigned int i;
        unsigned int j;

        i = 2;
        j = 0;
        if (is_prefixed(s)) {
                while ((temp[j] = s[i]) != '\0') {
                        ++i;
                        ++j;
                }
                temp[j] = '\0';
                copy(temp, s);
        }
}

int is_hex_letter(const int c)
{
        return (c >= 'A' && c <= 'F');
}

int is_valid_hex(const char s[], const unsigned int len)
{
        unsigned int i;

        i = 0;
        while (i < len) {
                if (!isdigit(s[i]) && !is_hex_letter(s[i]))
                        return FALSE;
                ++i;
        }
        return TRUE;
}

unsigned int htoi(const char s[])
{
        unsigned int n;
        unsigned int i;

        n = 0;
        i = 0;
        while (s[i] != '\0') {
                n = 16 * n + (isdigit(s[i]) ? (s[i] - '0') : (s[i] - '7'));
                ++i;
        }
        return n;
}
