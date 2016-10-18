/*
 * 1-4
 * Write a program to print the corresponding Celsius to
 * Fahrenheit table.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main(void)
{
        float fahr,
              celsius,
              lower,
              upper,
              step;

        lower = 0;
        upper = 300;
        step = 20;

        printf("%3c %6c\n", 'C', 'F');
        celsius = lower;
        while (celsius <= upper) {
                fahr = (9.0 / 5.0) * celsius + 32.0;
                printf("%3.0f %6.1f\n", celsius, fahr);
                celsius += step;
        }

        return 0;
}
