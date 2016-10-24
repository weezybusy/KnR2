/*
 * Exercise 3-1
 *
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time.
 */

#include <assert.h>
#include <stdio.h>
#include <time.h>

#define LIM 20000
#define N -1

int binary_search(int elem, int ar[], int len);  /* K&R */
int binary_search2(int elem, int ar[], int len); /* New */

int main(void)
{
        int data[LIM];
        int found;
        int i;
        clock_t time_taken;

        /* Initialize array with data */
        for (i = 0; i < LIM; ++i)
                data[i] = i;

        /*  Output: approximation of time taken for 100,000 iterations
            of binary_search() */
        time_taken = 0;
        for (i = 0, time_taken = clock(); i < 100000; ++i) {
                found = binary_search(N, data, LIM);
        }
        time_taken = clock() - time_taken;

        /* Print results */
        if (found < 0)
                printf("\nElement %d not found.\n", N);
        else
                printf("\nElement %d found at index %d.\n", N, found);
        printf("binary_search() took %.0lf clocks (%.2lf seconds)\n",
                        (double) time_taken,
                        (double) time_taken / CLOCKS_PER_SEC);

        /*  Output: approximation of time taken for 100,000 iterations
            of binary_search2() */
        time_taken = 0;
        for (i = 0, time_taken = clock(); i < 100000; ++i) {
                found = binary_search2(N, data, LIM);
        }
        time_taken = clock() - time_taken;

        /* Print results */
        if (found < 0)
                printf("\nElement %d not found.\n", N);
        else
                printf("\nElement %d found at index %d.\n", N, found);
        printf("binary_search2() took %.0lf clocks (%.2lf seconds)\n\n",
                        (double) time_taken,
                        (double) time_taken / CLOCKS_PER_SEC);

        return 0;
}

/* K&R */
int binary_search(int elem, int ar[], int len)
{
        int low;
        int high;
        int mid;

        low = 0;
        high = len - 1;

        while (low <= high) {
                mid = (low + high) / 2;
                if (ar[mid] == elem)
                        return mid;
                else if (ar[mid] < elem)
                        low = mid + 1;
                else
                        high = mid - 1;
        }
        return -1;
}

/* New */
int binary_search2(int elem, int ar[], int len)
{
        int low;
        int high;
        int mid;

        low = 0;
        high = len - 1;

        while (low < high) {
                mid = (low + high) / 2;
                if (ar[mid] < elem)
                        low = mid + 1;
                else
                        high = mid;
        }
        return (ar[low] == elem) ? low : -1;
}
