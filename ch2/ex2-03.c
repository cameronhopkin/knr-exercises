#include <stdio.h>

/* htoi: convert hexadecimal string s to integer */
int htoi(char s[])
{
    int i, n, digit;

    i = 0;
    /* 1. Handle the optional prefix */
    if (s[i] == '0') {
        i++;
        if (s[i] == 'x' || s[i] == 'X') {
            i++;
        }
    }

    n = 0;
    /* 2. Process digits until a non-hex character is found */
    for ( ; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            digit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            digit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            digit = s[i] - 'A' + 10;
        else
            break; /* Stop at first non-hex character */

        /* 3. Shift the current total and add the new digit */
        n = 16 * n + digit;
    }

    return n;
}

int main() 
{
    printf("Result of 0x1A: %d\n", htoi("0x1A")); /* Expect 26 */
    printf("Result of fff:  %d\n", htoi("fff"));  /* Expect 4095 */
    return 0;
}
