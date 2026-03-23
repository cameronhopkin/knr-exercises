#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n': s[j++] = '\\'; s[j++] = 'n'; break;
            case '\t': s[j++] = '\\'; s[j++] = 't'; break;
            default:   s[j++] = t[i]; break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\' && t[i+1] != '\0') {
            switch (t[++i]) {
                case 'n': s[j++] = '\n'; break;
                case 't': s[j++] = '\t'; break;
                default:  s[j++] = '\\'; s[j++] = t[i]; break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main() {
    char s[100], t[100];
    char test1[] = "A\tB\nC";
    escape(s, test1);
    unescape(t, s);
    printf("Test 1:\n  Esc:  %s\n  Unes: %s\n", s, t);

    char test2[] = "Backslash\\";
    escape(s, test2);
    unescape(t, s);
    printf("Test 2:\n  Esc:  %s\n  Unes: %s\n", s, t);
    return 0;
}
