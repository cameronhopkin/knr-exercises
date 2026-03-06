#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    /* Part 1: Print ranges from standard headers */
    printf("Ranges from limits.h and float.h:\n");
    printf("  char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("  signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("  unsigned char: 0 to %u\n", UCHAR_MAX);
    printf("  short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("  unsigned short: 0 to %u\n", USHRT_MAX);
    printf("  int: %d to %d\n", INT_MIN, INT_MAX);
    printf("  unsigned int: 0 to %u\n", UINT_MAX);
    printf("  long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("  unsigned long: 0 to %lu\n", ULONG_MAX);
    printf("  float: %g to %g\n", -FLT_MAX, FLT_MAX);
    printf("  float (min positive normalized): %g\n", FLT_MIN);
    printf("  double: %g to %g\n", -DBL_MAX, DBL_MAX);
    printf("  double (min positive normalized): %g\n", DBL_MIN);

    /* Part 2: Calculate ranges by direct computation */
    printf("\nRanges by direct computation:\n");

    /* Unsigned types: Max value is when all bits are 1 */
    unsigned char uc_max = (unsigned char) ~0;
    unsigned short us_max = (unsigned short) ~0;
    unsigned int ui_max = (unsigned int) ~0;
    unsigned long ul_max = (unsigned long) ~0;
    printf("  unsigned char: 0 to %u\n", uc_max);
    printf("  unsigned short: 0 to %u\n", us_max);
    printf("  unsigned int: 0 to %u\n", ui_max);
    printf("  unsigned long: 0 to %lu\n", ul_max);

    /* Signed types: Use bit twiddling assuming 2's complement */
    char c_max = (char) (uc_max >> 1);
    char c_min = ~c_max;
    printf("  char: %d to %d\n", c_min, c_max);

    short s_max = (short) (us_max >> 1);
    short s_min = ~s_max;
    printf("  short: %d to %d\n", s_min, s_max);

    int i_max = (int) (ui_max >> 1);
    int i_min = ~i_max;
    printf("  int: %d to %d\n", i_min, i_max);

    long l_max = (long) (ul_max >> 1);
    long l_min = ~l_max;
    printf("  long: %ld to %ld\n", l_min, l_max);

    /* Note: Direct computation of float/double ranges is complex */
    /* and relies on IEEE 754 format knowledge. We rely on float.h. */

    return 0;
}   
