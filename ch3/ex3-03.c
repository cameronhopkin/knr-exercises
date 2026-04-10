#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* expand: expand shorthand like a-z in s1 into abc...xyz in s2 */
void expand(char s1[], char s2[])
{
    int i, j, c;
    i = j = 0;
    while (s1[i] != '\0') {
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
            if (s1[i-1] < s1[i+1]) {
                for (c = s1[i-1] + 1; c < s1[i+1]; c++)
                    s2[j++] = (char)c;
                i++; 
            } else {
                s2[j++] = s1[i++];
            }
        } else {
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "-a-z 0-9 a-b-c-";
    char s2[100];
    char rev_test[] = "K&R Chapter 3";

    expand(s1, s2);
    printf("Expand:  [%s]\n", s2);

    printf("Original: [%s]\n", rev_test);
    reverse(rev_test);
    printf("Reversed: [%s]\n", rev_test);

    return 0;
}
