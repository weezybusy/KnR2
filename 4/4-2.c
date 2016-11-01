/*
 * Exercise 4-2
 *
 * Extend atof to handle scientific notation of the form 123.45e-6 where a
 * floating-point number may be followed by e or E and an optionally signed
 * exponent.
 */

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char s[]);

int main(void)
{
        assert(atof("123") == 123);
        assert(atof("1.23") == 1.23);
        assert(atof("12.3e2") == 1230);
        assert(atof("12.3e+2") == 1230);
        /* if we pass number with negative exponent, we need to
           round atof() result for proper assertion */
        assert((round(atof("123e-2") * 100) / 100) == 1.23);
        return 0;
}

double atof(char s[])
{
        double val, pow, exp_factor;
        int i, sign, exp;

        /* skip white space */
        for (i = 0; isspace(s[i]); ++i)
                continue;

        /* save the sign */
        sign = (s[i] == '-') ? -1 : 1;

        /* handle digits before decimal point */
        for (val = 0.0; isdigit(s[i]); ++i)
                val = 10.0 * val + (s[i] - '0');

        /* skip decimal point */
        if (s[i] == '.')
                ++i;

        /* handle digits after decimal point */
        for (pow = 1.0; isdigit(s[i]); ++i) {
                val = 10.0 * val + (s[i] - '0');
                pow *= 10;
        }

        /* calculate value without applying exponent */
        val = sign * val / pow;

        /* check if e/E exists */
        if (tolower(s[i]) == 'e')
                ++i;

        /* get exponent factor */
        if (s[i] == '-') {
                exp_factor = 0.1;
                ++i;
        } else if (s[i] == '+') {
                exp_factor = 10.0;
                ++i;
        } else
                exp_factor = 10.0;

        /* get exponent value */
        for (exp = 0; isdigit(s[i]); ++i)
                exp = exp_factor * exp + (s[i] - '0');

        /* calculate final result */
        for (i = exp; i > 0; --i)
                val *= exp_factor;

        return val;
}
