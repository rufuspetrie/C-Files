#include <stdio.h>
#include <limits.h>

int main(){

	printf("Character Ranges:\n");
	printf("Minimum: %d\n", SCHAR_MIN);
	printf("Maximum: %d\n", SCHAR_MAX);
	printf("Unsigned Maximum: %d\n\n", UCHAR_MAX);

	printf("Integer Ranges:\n");
	printf("Minimum: %d\n", INT_MIN);
	printf("Maximum: %d\n", INT_MAX);
	printf("Unsigned Maximum: %d\n\n", UINT_MAX);

	printf("Short Integer Ranges:\n");
	printf("Minimum: %d\n", SHRT_MIN);
	printf("Maximum: %d\n", SHRT_MAX);
	printf("Unsigned Maximum: %d\n\n", USHRT_MAX);

	printf("Long Integer Ranges:\n");
	printf("Minimum: %d\n", LONG_MIN);
	printf("Maximum: %d\n", LONG_MAX);
	printf("Unsigned Maximum: %d\n\n", ULONG_MAX);

	return 0;
}