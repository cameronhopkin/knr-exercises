#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int get_line(char s[], int lim);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) { /* there was a line */
        printf("\nLongest line length: %d\n", max);
        printf("Text (as much as fits): %s\n", longest);
    }
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[j] = c; /* only store if there is room */
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
