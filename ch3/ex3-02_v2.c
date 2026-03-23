#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n': s[j++] = '\\'; s[j++] = 'n'; break;
            case '\t': s[j++] = '\\'; s[j++] = 't'; break;
            case '\\': s[j++] = '\\'; s[j++] = '\\'; break; /* THE FIX */
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
                case 'n':  s[j++] = '\n'; break;
                case 't':  s[j++] = '\t'; break;
                case '\\': s[j++] = '\\'; break; /* HANDLE ESCAPED BS */
                default:   s[j++] = '\\'; s[j++] = t[i]; break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main() {
    char s[100], t[100];
    
    /* The Injection-Style Test Case */
    char test[] = "a\\b"; /* String is: a, backslash, b */
    
    escape(s, test);
    unescape(t, s);

    printf("Input:   [%s]\n", test);
    printf("Escaped: [%s]\n", s); // Should be a\\b
    printf("Unesc:   [%s]\n", t);

    return 0;
}
