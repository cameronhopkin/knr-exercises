#include <stdio.h>

#define MAXLINE 1000   /* maximum input line size */
#define THRESHOLD 80   /* lines longer than this will be printed */

int get_line(char s[], int lim);

int main() {
    int len;            
    char line[MAXLINE]; 

    while ((len = get_line(line, MAXLINE)) > 0) {
        /* 
         * Since get_line includes the '\n' in the count, 
         * (len - 1) gives us the count of actual text characters.
         */
        if (len - 1 > THRESHOLD) {
            printf("%s", line);
        }
    }
    return 0;
}

int get_line(char s[], int lim) {
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[j] = c;
            ++j;
        }
    }
    if (c == '\n') {
        if (i < lim - 1) {
            s[j] = c;
            ++j;
        }
        ++i; 
    }
    s[j] = '\0';
    return i;
}

