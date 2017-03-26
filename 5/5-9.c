/*
 * Exercise 5-9.
 *
 * Rewrite the routines day_of_year and month_day with pointers
 * instead of indexing.
 */

#include <stdio.h>

#define DAYS_IN_YEAR 365

int day_of_year(int year, int month, int day);
int month_day(int year, int year_day, int *pmonth, int *pday);
char *month_name(int n);

int main(void)
{
        int day;
        int month;
        int year;
        int year_day;

        day = 13;
        month = 10;
        year = 1984;
        year_day = 287;

        if ((day = day_of_year(year, month, day)) != -1)
                printf("%i\n", day);

        if (month_day(year, year_day, &month, &day) != -1)
                printf("%i %s %i\n", day, month_name(month), year);

        return 0;
}

static char daytab[2][13] = {
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(int year, int month, int day)
{
        int i;
        int leap;
        char *p;

        if (month < 1 || month > 12) {
                fprintf(stderr, "Invalid month.\n");
                return -1;
        }

        leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        p = &daytab[leap][1];
        if (day < 1 || day > *(p + month)) {
                fprintf(stderr, "Invalid day.\n");
                return -1;
        }

        for (i = 1; i < month; ++i)
                day += *(p + i);

        return day;
}

int month_day(int year, int year_day, int *pmonth, int *pday)
{
        int i;
        int leap;
        char *p;

        if (pmonth == NULL || pday == NULL) {
                fprintf(stderr, "Null pointer error.\n");
                return -1;
        }

        leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (year_day < 1 || year_day > DAYS_IN_YEAR + leap) {
                fprintf(stderr, "Invalid year day.\n");
                return -1;
        }

        p = &daytab[leap][1];
        for (i = 1; year_day > *(p + i); ++i)
                year_day -= *(p + i);

        *pmonth = i;
        *pday = year_day;

        return 0;
}

char *month_name(int n)
{
        static char *name[] = {
                "Illigal month",
                "January",
                "February",
                "March",
                "April",
                "May",
                "June",
                "July",
                "August",
                "September",
                "October",
                "November",
                "December"
        };

        return (n < 1 || n > 12) ? *name : *(name + n);
}
