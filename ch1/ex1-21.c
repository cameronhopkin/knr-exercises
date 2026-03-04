#include <stdio.h>
#define TABSTOP 8

int main() {
    int c, pos, spaces, start_pos;
    pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            pos = 0;
        } else if (c == ' ') {
            start_pos = pos;
            spaces = 0;
            while (c == ' ') {
                spaces++;
                pos++;
                c = getchar();
            }
            int tab_width = TABSTOP - (start_pos % TABSTOP);
            while (spaces >= tab_width) {
                putchar('\t');
                spaces -= tab_width;
                start_pos += tab_width;
                tab_width = TABSTOP;
            }
            while (spaces-- > 0) {
                putchar(' ');
            }
            if (c != EOF) {
                putchar(c);
                pos++;
            }
        } else {
            putchar(c);
            pos++;
        }
    }
    return 0;
}   
