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
    char raw[] = "Tab\tTest\nBackslash at end\\";
    char esc[100], unesc[100];

    escape(esc, raw);
    unescape(unesc, esc);

    printf("Raw:     [%s]\n", raw);
    printf("Escaped: [%s]\n", esc);
    printf("Unesc:   [%s]\n", unesc);

    return 0;
}
