#include<stdio.h>

int main(){
	int fahr;

	printf("Fahrenheit\tCelsius\n");

	for(fahr=300; fahr>=0; fahr-=20){
		printf("%10d\t%7.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
	return 0;
}