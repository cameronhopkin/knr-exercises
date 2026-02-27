#include <stdio.h>

#define SIZE ('~' - '!' + 1) 
#define SCALE 1 

int main(void)
{
	int c, i, j, count;
	int characters[SIZE];


	for (i = 0; i < SIZE; ++i)
		characters[i] = 0;

	count = 0;
	while ((c = getchar()) != EOF) 
		if (c >= '!' && c <= '~') { 
			++characters[c - '!'];
			++count; 
		}

	if (!count)
		return -1;

	printf("\nHorizontal Histogram: (scale 1:%i)\n", SCALE);
	for (i = 0; i < SIZE; ++i)
		if (characters[i] != 0) { 
			printf(" %c", i + '!'); 
			for (j = 1; j <= characters[i] / SCALE; ++j)
				printf(" *");
			printf("\n");
		}

	return 0;
}
