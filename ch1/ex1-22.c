#include <stdio.h>
#define FOLDLINE 80

int main() {
    int c, pos, len;
    char line[FOLDLINE + 1];
    pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line[pos] = c;
            pos++;
            line[pos] = '\0';
            printf("%s", line);
            pos = 0;
        } else if (pos >= FOLDLINE - 1) {
            int i = pos - 1;
            while (i >= 0 && line[i] != ' ')
                i--;
            if (i >= 0) {
                line[i] = '\n';
                line[i + 1] = '\0';
                printf("%s", line);
                int j = 0;
                while (i + 1 + j < pos) {
                    line[j] = line[i + 1 + j];
                    j++;
                }
                line[j] = c;
                pos = j + 1;
            } else {
                line[pos] = '\n';
                line[pos + 1] = '\0';
                printf("%s", line);
                line[0] = c;
                pos = 1;
            }
        } else {
            line[pos] = c;
            pos++;
        }
    }
    if (pos > 0) {
        line[pos] = '\0';
        printf("%s", line);
    }
    return 0;
}   
