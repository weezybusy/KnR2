/*
 * Exercise 5-7.
 *
 * Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage. How much faster is
 * the program?
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LEN    1000
#define MAX_LINES  5000
#define ALLOC_SIZE 10000
#define MAX_STORE ALLOC_SIZE

int read_lines(char *line_ptr[], int n_lines);
int new_read_lines(char *line_ptr[], int n_lines, char line_store[]);
void write_lines(char *line_ptr[], int n_lines);
void quick_sort(char *v[], int left, int right);

char *line_ptr[MAX_LINES];
static char alloc_buf[ALLOC_SIZE];
static char *alloc_p = alloc_buf;

int main(void)
{
        int n_lines;
        char line_store[MAX_STORE];
        time_t start;

        start = clock();
        if ((n_lines = read_lines(line_ptr, MAX_LINES)) >= 0) {
                quick_sort(line_ptr, 0, n_lines - 1);
                printf("\nusing alloc\n-----------\n");
                write_lines(line_ptr, n_lines);
        } else {
                fprintf(stderr, "Input too big to sort.\n");
                return 1;
        }
        printf("-----------\ntime: ");
        printf("%f\n\n", (double) (clock() - start) / CLOCKS_PER_SEC);

        start = clock();
        if ((n_lines = new_read_lines(line_ptr, MAX_LINES, line_store)) >= 0) {
                quick_sort(line_ptr, 0, n_lines - 1);
                printf("\nusing array\n-----------\n");
                write_lines(line_ptr, n_lines);
        } else {
                fprintf(stderr, "Input too big to sort.\n");
                return 1;
        }
        printf("-----------\ntime: ");
        printf("%f\n\n", (double) (clock() - start) / CLOCKS_PER_SEC);

        return 0;
}

int new_read_lines(char *line_ptr[], int max_lines, char line_store[])
{
        int get_line(char *s, int n);

        int len;
        int n_lines;
        int next_line_index;

        n_lines = 0;
        next_line_index = 0;
        while ((len = get_line(line_store + next_line_index, MAX_LEN)) > 0) {
                if (n_lines >= max_lines)
                        return -1;
                else {
                        line_store[next_line_index + len - 1] = '\0';
                        line_ptr[n_lines++] = &line_store[next_line_index];
                }
                next_line_index += len;
        }
        return n_lines;
}

int read_lines(char *line_ptr[], int max_lines)
{
        char *alloc(int n);
        void afree(char *p);
        int get_line(char *s, int n);
        void str_cpy(char *s, char *t);

        int len;
        int n_lines;
        char *p;
        char line[MAX_LEN];

        n_lines = 0;
        while ((len = get_line(line, MAX_LEN)) > 0) {
                if (n_lines >= max_lines || (p = alloc(len)) == NULL)
                        return -1;
                else {
                        line[len - 1] = '\0'; // Delete newline
                        str_cpy(p, line);
                        line_ptr[n_lines++] = p;
                }
        }
        return n_lines;
}

int get_line(char *s, int n)
{
        int c;
        int i;

        for (i = 0; i < n - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                *s++ = c;

        if (c == '\n') {
                *s++ = '\n';
                ++i;
        }

        *s = '\0';

        return i;
}

void write_lines(char *line_ptr[], int n_lines)
{
        int i;

        for (i = 1; n_lines-- > 0; ++i)
                printf("%i) %s\n", i, *line_ptr++);
}

void quick_sort(char *v[], int left, int right)
{
        int str_cmp(char *s, char *t);
        void swap(char *v[], int i, int j);

        int i;
        int last;

        if (left >= right)
                return;

        swap(v, left, (left + right) / 2);
        last = left;

        for (i = left + 1; i <= right; ++i)
                if (str_cmp(v[i], v[left]) < 0)
                        swap(v, ++last, i);
        swap(v, left, last);
        quick_sort(v, left, last - 1);
        quick_sort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
        char *temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
}

void str_cpy(char *s, char *t)
{
        while ((*s++ = *t++) != '\0')
                continue;
}

int str_cmp(char *s, char *t)
{
        for ( ; *s == *t; ++s, ++t)
                if (*t == '\0')
                        return 0;
        return *s - *t;
}

char *alloc(int n)
{
        if (alloc_buf + ALLOC_SIZE - alloc_p >= n) {
                alloc_p += n;
                return alloc_p - n;
        } else
                return 0;
}

void afree(char *p)
{
        if (p >= alloc_buf && p < alloc_buf + ALLOC_SIZE)
                alloc_p = p;
}
