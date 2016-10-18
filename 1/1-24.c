/*
 * 1-24
 * Write a program to check a C program for rudimentary syntax errors like
 * unbalanced parentheses, brackets and braces. Don't forget about quotes,
 * both single and double, escape sequences, and comments. (This program is
 * hard if you do it in full generality.) 
 */

#include <stdio.h>
#include <string.h>

#define SIZE          1024
#define FALSE         0
#define TRUE          1
#define COMMENT       2
#define STRING        3
#define SINGLE_QUOTES 4
#define PARENTHESES   5
#define BRACES        6
#define BRACKETS      7

int main(void)
{
        int ch               = 0,
            prev             = 0,
            codes            = 0,
            in_parentheses   = FALSE,
            in_braces        = FALSE,
            in_brackets      = FALSE,
            in_comment       = FALSE,
            in_string        = FALSE,
            in_single_quotes = FALSE,
            pairs[SIZE];

        while ((ch = getchar()) != EOF) {
                if ((ch == '*')
                                && (prev == '/')
                                && !in_comment
                                && !in_string) {
                        in_comment = TRUE;
                        pairs[codes++] = COMMENT;
                } else if ((ch == '/')
                                && (prev == '*')
                                && in_comment) {
                        in_comment = FALSE;
                } else if ((ch == '\"')
                                && (prev != '\\')
                                && !in_comment
                                && !in_single_quotes) {
                        in_string = (in_string ? FALSE : TRUE);
                        pairs[codes++] = STRING;
                } else if ((ch ==  '\'')
                                && (prev != '\\')
                                && !in_comment
                                && !in_string) {
                        in_single_quotes = (in_single_quotes ? FALSE : TRUE);
                        pairs[codes++] = SINGLE_QUOTES;
                } else if (!in_comment
                                && !in_string
                                && !in_single_quotes) {
                        if (ch == '(') {
                                --in_parentheses;
                                pairs[codes++] = PARENTHESES;
                        }
                        in_parentheses += (ch == ')');
                        if (ch == '{') {
                                --in_braces;
                                pairs[codes++] = BRACES;
                        }
                        in_braces += (ch == '}');
                        if (ch == '[') {
                                --in_brackets;
                                pairs[codes++] = BRACKETS;
                        }
                        in_brackets += (ch == ']');
                }
                prev = ch;
        }

        /* Code below prints errors in order of occurrence.
           Pair is considered unbalanced if value isn't 0 */
        for (int code = 0; code < codes; ++code) {
                if ((pairs[code] == COMMENT) && in_comment)
                        printf("%d. Unclosed comment\n", code + 1);
                else if ((pairs[code] == STRING) && in_string)
                        printf("%d. Unbalanced double quotes\n", code + 1);
                else if ((pairs[code] == SINGLE_QUOTES) && in_single_quotes)
                        printf("%d. Unbalanced single quotes\n", code + 1);
                else if ((pairs[code] == PARENTHESES) && in_parentheses)
                        printf("%d. Unbalanced parentheses\n", code + 1);
                else if ((pairs[code] == BRACES) && in_braces)
                        printf("%d. Unbalanced braces\n", code + 1);
                else
                        printf("%d. Unbalanced brackets\n", code + 1);
        }
        return 0;
}
