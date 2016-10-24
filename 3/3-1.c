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
void print_results(int index, char name[], double time_taken);

int main(void)
{
        int data[LIM];
        int index;
        int i;
        clock_t time_taken;

        for (i = 0; i < LIM; ++i)
                data[i] = i;

        /*  Output: approximation of time taken for 1,000,000 iterations
            of binary_search() */

        time_taken = 0;
        for (i = 0, time_taken = clock(); i < 1000000; ++i)
                index = binary_search(N, data, LIM);
        time_taken = clock() - time_taken;
        print_results(index, "binary_search()", (double) time_taken);

        /*  Output: approximation of time taken for 1,000,000 iterations
            of binary_search2() */

        time_taken = 0;
        for (i = 0, time_taken = clock(); i < 1000000; ++i)
                index = binary_search2(N, data, LIM);
        time_taken = clock() - time_taken;
        print_results(index, "binary_search2()", (double) time_taken);

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

void print_results(int index, char name[], double time_taken)
{
        if (index < 0)
                printf("\nElement %d not found.\n", N);
        else
                printf("\nElement %d found at index %d.\n", N, index);

        printf("%s took %.0lf clocks (%.2lf seconds)\n",
                        name, time_taken, time_taken / CLOCKS_PER_SEC);
}
