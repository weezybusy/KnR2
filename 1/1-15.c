/*
 * 1-15
 * Rewrite the temperature conversion program of section 1.2 to use a
 * function for conversion.
 */

#include <stdio.h>

float f2c(float f);

int main(void)
{
        float fahr, celsius;
        int lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        printf("%3c %3c\n", 'F', 'C');
        fahr = lower;
        while (fahr <= upper) {
                celsius = f2c(fahr);
                printf("%3.0f %6.1f\n", fahr, celsius);
                fahr += step;
        }

        return 0;
}

float f2c(float f)
{
        return (5.0 / 9.0) * (f - 32.0);
}
