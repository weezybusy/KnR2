/*
 * Exercise 3-1
 *
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time.
 */

#include <assert.h>
#include <stdio.h>

#define LIM 6

int binary_search(int elem, int ar[], int len);

int main(void)
{
        int ar[LIM] = { 1, 2, 3, 4, 5, 6 };

        assert(binary_search(1, ar, LIM) == 0);
        assert(binary_search(2, ar, LIM) == 1);
        assert(binary_search(3, ar, LIM) == 2);
        assert(binary_search(4, ar, LIM) == 3);
        assert(binary_search(5, ar, LIM) == 4);
        assert(binary_search(6, ar, LIM) == 5);
        assert(binary_search(0, ar, LIM) == -1);
        assert(binary_search(7, ar, LIM) == -1);
        assert(binary_search(8, ar, LIM) == -1);
        puts("success");

        return 0;
}

int binary_search(int elem, int ar[], int len)
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
