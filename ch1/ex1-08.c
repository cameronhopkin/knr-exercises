#include <stdio.h>

int main()
{
	int c, spc, t, nl;

	spc = t = nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++spc;
        else if (c == '\t')
			++t;
        else if (c == '\n')
			++nl;
	}

	printf("%d blanks, %d tabs, %d newlines\n", spc, t, nl);

	return 0;
}
