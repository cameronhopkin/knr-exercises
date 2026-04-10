#include <stdio.h>
#include <string.h>
#include <limits.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s; K&R Exercise 3-4 idiomatic fix */
void itoa_fixed(int n, char s[]) {
    int i, sign;

    sign = n;
    /* Unify to negative domain to handle INT_MIN safely */
    if (n > 0)
        n = -n;

    i = 0;
    do {
        /* n % 10 is 0 or negative; '0' - (-8) = '8' */
        s[i++] = '0' - (n % 10);
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[32];
    
    /* Test Case: Zero */
    printf("Testing Zero (0):  ");
    itoa_fixed(0, s);
    printf("[%s]\n", s);

    /* Case 1: Positive Number */
    itoa_fixed(1234, s);
    printf("Positive (1234):  %s\n", s);
    
    /* Case 2: Negative Number */
    itoa_fixed(-5678, s);
    printf("Negative (-5678): %s\n", s);
    
    /* Case 3: The INT_MIN Trap */
    printf("Testing INT_MIN:  %d\n", INT_MIN);
    itoa_fixed(INT_MIN, s);
    printf("Result:           %s\n", s);
    
    return 0;
}
