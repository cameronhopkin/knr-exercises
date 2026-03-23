#include <stdio.h>

/* binsearch_opt: find x in v[0]...v[n-1] with one test inside loop */
int binsearch_opt(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = low + (high - low) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    /* Final equality check after the window collapses to one element */
    return (x == v[low]) ? low : -1;
}

int main(void)
{
    int data[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = 8;
    int target_hit = 10;
    int target_miss = 7;

    printf("Array: {2, 4, 6, 8, 10, 12, 14, 16}\n");
    
    /* Test 1: Successful hit */
    printf("Searching for %d... Result: Index %d\n", 
            target_hit, binsearch_opt(target_hit, data, n));

    /* Test 2: Miss */
    printf("Searching for %d... Result: %d\n", 
            target_miss, binsearch_opt(target_miss, data, n));

    return 0;
}
