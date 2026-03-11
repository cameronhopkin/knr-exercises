#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int trim(char s[], int len);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        len = trim(line, len);
        
        /* 
         * After trimming, a line that was only whitespace 
         * or only a newline will have a length of 0.
         */
        if (len > 0) {
            printf("%s\n", line); 
        }
    }
    return 0;
}

/* get_line: standard K&R version (includes newline) */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* trim: removes trailing blanks, tabs, AND the newline */
int trim(char s[], int len) {
    int i;

    /* Start at the very end of the string (index of \0 minus 1) */
    i = len - 1;

    /* 
     * Back up past the newline, spaces, and tabs.
     * We use a while loop to move the pointer 'i' backwards.
     */
    while (i >= 0 && (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')) {
        i--;
    }

    /* 
     * i now points to the last "real" character.
     * We place the null terminator right after it.
     */
    s[i + 1] = '\0';

    /* Return the new length (number of characters before \0) */
    return i + 1;
}

