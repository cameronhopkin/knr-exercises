#include <stdio.h>

#define SIZE 5
#define SCALE 1
#define OUT  1
#define IN   0

int main()
{
	int c, i, j, count, state;
	int lengths[SIZE]; 

	for (i = 0; i < SIZE; ++i)
		lengths[i] = 0;

	state = OUT;
	count = 0;
	while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
        if (state == IN) {
            if (count < 4)
                ++lengths[0];
            else if (count >= 4 && count < 8)
                ++lengths[1];
            else if (count >= 8 && count < 12)
                ++lengths[2];
            else if (count >= 12 && count < 14)
                ++lengths[3];
            else if (count >= 14)
                ++lengths[4];
            count = 0;
        }
        state = OUT;
    } else {
        state = IN;
        ++count;
    }
}

	printf("\nHorizontal Histogram\n");
	for (i = 0; i < SIZE; ++i) {
		printf(" %i\t", lengths[i]);
		for (j = 0; j < lengths[i] / SCALE; ++j)
			printf(" *");
		printf("\n");
	}

	return 0;
}			
