#include <stdio.h>

/* binsearch: find x in v[0]...v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        /* Entry 23 Fix: Avoid (low + high) overflow */
        mid = low + (high - low) / 2;
        
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

int main(void)
{
    int data[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = 8;
    int target = 10;
    int result;

    result = binsearch(target, data, n);

    if (result != -1)
        printf("Found %d at index %d\n", target, result);
    else
        printf("%d not found\n", target);

    return 0;
}
