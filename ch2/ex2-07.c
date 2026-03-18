#include <stdio.h>

/* invert: returns x with the n bits that begin at position p inverted */
unsigned invert(unsigned x, int p, int n)
{
    unsigned mask;
    /* Use 0U to ensure we are shifting an unsigned type (Entry 15 fix) */
    mask = (~(~0U << n)) << (p + 1 - n);
    return x ^ mask;
}

int main(void)
{
    unsigned r1, r2;

    /* Test Case 1: invert(85, 4, 3) -> Expected 73 */
    r1 = invert(85, 4, 3);
    printf("Test 1: invert(85, 4, 3)\n");
    printf("Expected: 73 | Actual: %u\n", r1);

    /* Test Case 2: invert(15, 7, 4) -> Expected 255 */
    r2 = invert(15, 7, 4);
    printf("\nTest 2: invert(15, 7, 4)\n");
    printf("Expected: 255 | Actual: %u\n", r2);

    if (r1 == 73 && r2 == 255) {
        printf("\nResult: PASS\n");
    } else {
        printf("\nResult: FAIL\n");
    }

    return 0;
}
