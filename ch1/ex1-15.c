#include <stdio.h>

/* functions */
float toCelsius(float);

float toCelsius(float f)
{
	return (5.0 / 9.0) * (f - 32.0);
}

int main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = -40;
	upper = 300;
	step  = 20;

	fahr = lower;
	printf("Fahrenheit\tCelsius\n");
	while (fahr <= upper) {
		celsius = toCelsius(fahr);
		printf("%10.0f\t%7.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
