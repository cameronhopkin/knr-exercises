#include <stdio.h>

#define YES 1
#define NO  0

int main() {
    int c, d;
    int brace = 0, bracket = 0, paren = 0;
    int in_comment = NO;
    int in_string = NO;
    int in_char = NO;

    while ((c = getchar()) != EOF) {
        if (c == '/' && (d = getchar()) == '*') {
            in_comment = YES;
        } else if (c == '*' && d == '/') {
            in_comment = NO;
        } else if (c == '"' && !in_comment && !in_char) {
            in_string = !in_string;
        } else if (c == '\'' && !in_comment && !in_string) {
            in_char = !in_char;
        } else if (!in_comment && !in_string && !in_char) {
            if (c == '{') brace++;
            else if (c == '}') brace--;
            else if (c == '[') bracket++;
            else if (c == ']') bracket--;
            else if (c == '(') paren++;
            else if (c == ')') paren--;
        }
    }

    if (brace != 0) printf("Unbalanced braces\n");
    if (bracket != 0) printf("Unbalanced brackets\n");
    if (paren != 0) printf("Unbalanced parentheses\n");

    return 0;
}   
