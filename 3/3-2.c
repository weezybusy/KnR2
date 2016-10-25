/*
 * Exercise 3-2
 *
 * Write a function escape(s,t) that converts characters like newline and
 * tab into visible escape sequences like \n and \t as it copies the
 * string t to s . Use a switch . Write a function for the other direction
 * as well, converting escape sequences into the real characters. 
 */

#include <stdio.h>

#define LIM 128

void escape(char src[], char dest[]);
void unescape(char src[], char dest[]);

int main(void)
{
        char s1[LIM];
        char s2[LIM];

        escape("Hello\tworld\n!", s1);
        puts(s1);
        unescape(s1, s2);
        puts(s2);

        return 0;
}

void escape(char src[], char dest[])
{
        int i, j;

        i = j = 0;
        while (src[i]) {
                switch (src[i]) {
                case '\n':
                        dest[j++] = '\\';
                        dest[j] = 'n';
                        break;
                case '\t':
                        dest[j++] = '\\';
                        dest[j] = 't';
                        break;
                case '\a':
                        dest[j++] = '\\';
                        dest[j] = 'a';
                        break;
                case '\b':
                        dest[j++] = '\\';
                        dest[j] = 'b';
                        break;
                case '\f':
                        dest[j++] = '\\';
                        dest[j] = 'f';
                        break;
                case '\r':
                        dest[j++] = '\\';
                        dest[j] = 'r';
                        break;
                case '\v':
                        dest[j++] = '\\';
                        dest[j] = 'v';
                        break;
                case '\\':
                        dest[j++] = '\\';
                        dest[j] = '\\';
                        break;
                case '\'':
                        dest[j++] = '\\';
                        dest[j] = '\'';
                        break;
                case '\"':
                        dest[j++] = '\\';
                        dest[j] = '\"';
                        break;
                case '\?':
                        dest[j++] = '\\';
                        dest[j] = '\?';
                        break;
                default:
                        dest[j] = src[i];
                        break;
                }
                ++j;
                ++i;
        }
        dest[j] = '\0';
}

void unescape(char src[], char dest[])
{
        int i, j;

        i = j = 0;
        while (src[i]) {
                if (src[i] == '\\') {
                        switch (src[++i]) {
                        case 'n':
                                dest[j] = '\n';
                                break;
                        case 't':
                                dest[j] = '\t';
                                break;
                        case 'a':
                                dest[j] = '\a';
                                break;
                        case 'b':
                                dest[j] = '\b';
                                break;
                        case 'f':
                                dest[j] = '\f';
                                break;
                        case 'r':
                                dest[j] = '\r';
                                break;
                        case 'v':
                                dest[j] = '\v';
                                break;
                        case '\\':
                                dest[j] = '\\';
                                break;
                        case '\'':
                                dest[j] = '\'';
                                break;
                        case '\"':
                                dest[j] = '\"';
                                break;
                        case '\?':
                                dest[j] = '\?';
                                break;
                        default:
                                dest[j++] = '\\';
                                dest[j] = src[i];
                                break;
                        }
                } else
                        dest[j] = src[i];
                ++i;
                ++j;
        }
        dest[j] = '\0';
}
