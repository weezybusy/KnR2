/*
 * 2-3
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LIM   64    /* Maximum string capacity */
#define TRUE  1
#define FALSE 0

int getline(char s[], int lim);
void copy(char src[], char dest[]);
void upper(char s[]);
int withprefix(char s[]);
void delprefix(char s[], int len);
int isvalid(char s[], int len);
int htoi(char s[]);

int main(void)
{
        char hex[LIM];
        char hex_copy[LIM];
        int len;
        int dec;

        printf("> ");
        while ((len = getline(hex, LIM)) > 0) {
                copy(hex, hex_copy);
                upper(hex_copy);
                delprefix(hex_copy, len);
                if (isvalid(hex_copy, strlen(hex_copy))) {
                        dec = htoi(hex_copy);
                        printf("%d\n", dec);
                } else
                        puts("It's not a hexadecimal number.");
                printf("> ");
        }
        return 0;
}

int getline(char s[], int lim)
{
        int c;
        int i;

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

void copy(char src[], char dest[])
{
        int i;

        i = 0;
        while ((dest[i] = src[i]) != '\0')
                ++i;
        dest[i] = '\0';
}

void upper(char s[])
{
        int i;

        i = 0;
        while ((s[i] = toupper(s[i])) != '\0')
                ++i;
}

int withprefix(char s[])
{
        return (s[0] == '0' && s[1] == 'X');
}

void delprefix(char s[], int len)
{
        char temp[len];
        int i;
        int j;

        i = 2;
        j = 0;
        if (withprefix(s)) {
                while ((temp[j] = s[i]) != '\0') {
                        ++i;
                        ++j;
                }
                temp[j] = '\0';
                copy(temp, s);
        }
}

int ishexletter(int c)
{
        return (c >= 'A' && c <= 'F');
}

int isvalid(char s[], int len)
{
        int i;

        i = 0;
        while (i < len) {
                if (!isdigit(s[i]) && !ishexletter(s[i]))
                        return FALSE;
                ++i;
        }
        return TRUE;
}

int htoi(char s[])
{
        int n;
        int i;

        n = 0;
        i = 0;
        while (s[i] != '\0') {
                n = 16 * n + (isdigit(s[i]) ? (s[i] - '0') : (s[i] - '7'));
                ++i;
        }
        return n;
}
