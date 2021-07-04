#include <stdio.h>

int main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Celsius\tFahrenheit\n");

	celsius = lower;
	while(celsius<=upper){
		fahr = (9*celsius)/5+32;
		printf("%7.0f\t%10.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}