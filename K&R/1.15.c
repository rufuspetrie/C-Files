#include <stdio.h>

/* Note: can prototype functions like C++ */
float f_to_c(float fahr);

int main(){
	
	float i;

	printf("Fahrenheit\tCelsius\n");

	for(i=0; i<=23; i++)
		printf("-");

	printf("\n");

	for(i=0; i<=300; i+=20)
		printf("%10.0f\t%7.1f\n", i, f_to_c(i));

	return 0;
}

float f_to_c(float fahr){
	return 5*(fahr-32)/9;
}