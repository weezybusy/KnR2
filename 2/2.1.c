/*
 * 2-1
 * Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void)
{
        printf(" %-14s%-11s%-23s%-20s\n"
               "+-------------------------------------"
               "---------------------------------+\n"
               "| %11s | %8s | %-20d | %-20d |\n"
               "| %11s | %8s | %-20u | %-20u |\n"
               "| %11s | %8s | %-20d | %-20d |\n"
               "| %11s | %8s | %-20hu | %-20hu |\n"
               "| %11s | %8s | %-20d | %-20d |\n"
               "| %11s | %8s | %-20u | %-20u |\n"
               "| %11s | %8s | %-20ld | %-20ld |\n"
               "| %11s | %8s | %-20lu | %-20lu |\n"
               "| %11s | %8s | %-20lld | %-20lld |\n"
               "| %11s | %8s | %-20llu | %-20llu |\n"
               "| %11s | %8s | %-20e | %-20e |\n"
               "| %11s | %8s | %-20e | %-20e |\n"
               "| %11s | %8s | %-20Le | %-20Le |\n"
               "+-------------------------------------"
               "---------------------------------+\n",
               "TYPE", "SPECIFIER", "MIN", "MAX",
               "char", "signed", CHAR_MIN, CHAR_MAX,
               "char", "unsigned", 0, UCHAR_MAX,
               "short", "signed", SHRT_MIN, SHRT_MAX,
               "short", "unsigned", 0, USHRT_MAX,
               "int", "signed", INT_MIN, INT_MAX,
               "int", "unsigned", 0, UINT_MAX,
               "long", "signed", LONG_MIN, LONG_MAX,
               "long", "unsigned", 0L, ULONG_MAX,
               "long long", "signed", LLONG_MIN, LLONG_MAX,
               "long long", "unsigned", 0LL, ULLONG_MAX,
               "float", "signed", FLT_MIN, FLT_MAX,
               "double", "signed", DBL_MIN, DBL_MAX,
               "long double", "signed", LDBL_MIN, LDBL_MAX);

        return 0;
}
