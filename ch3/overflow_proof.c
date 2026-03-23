#include <stdio.h>

int main() 
{
    /* Individually, these are safe 'int' values on a 32-bit machine */
    int low = 1500000000;  
    int high = 1600000000; 

    /* The 'Standard' arithmetic that fails */
    int mid_broken = (low + high) / 2;

    /* The 'Secure' arithmetic that succeeds */
    int mid_fixed = low + (high - low) / 2;

    printf("low: %d, high: %d\n", low, high);
    printf("Broken Mid ((low+high)/2): %d\n", mid_broken);
    printf("Fixed Mid (low+(high-low)/2): %d\n", mid_fixed);

    return 0;
}
