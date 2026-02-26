#include <stdio.h>

#define YES 1
#define NO  0 

int main()
{
	int c, charReplaced; 

	while ((c = getchar()) != EOF) {
		charReplaced = NO;
		if (c == '\t') {
			printf("\\t");
			charReplaced = YES;
		}
		if (c == '\b') {
			printf("\\b");
			charReplaced = YES;
		}
		if (c == '\\') {
			printf("\\\\");
			charReplaced = YES;
		}
		if (charReplaced == NO)
			putchar(c);
	}
	return 0;
}
