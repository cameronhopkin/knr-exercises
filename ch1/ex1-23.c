#include <stdio.h>

#define NO  0
#define YES 1

int main() {
    int c, d;
    int in_comment = NO;
    int in_quote = NO;
    int quote_char;

    while ((c = getchar()) != EOF) {
        if (!in_comment && !in_quote) {
            if (c == '/' && (d = getchar()) == '*') {
                in_comment = YES;
            } else if (c == '/' && d == '/') {
                putchar('\n');  // Replace // comment with newline
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                if (c == EOF) break;
            } else if (c == '\'' || c == '"') {
                in_quote = YES;
                quote_char = c;
                putchar(c);
            } else {
                putchar(c);
                if (c == '/' && d != EOF) {
                    putchar(d);
                }
            }
        } else if (in_comment) {
            if (c == '*' && (d = getchar()) == '/') {
                in_comment = NO;
            }
        } else if (in_quote) {
            putchar(c);
            if (c == '\\') {
                if ((c = getchar()) != EOF) {
                    putchar(c);
                }
            } else if (c == quote_char) {
                in_quote = NO;
            }
        }
    }
    return 0;
}   
