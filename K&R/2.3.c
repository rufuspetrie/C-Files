#include <stdio.h>

int htoi(char string[]);

int main(){
	char hex[] = "0x1000";
	int converted = htoi(hex);
	printf("Value in hex: %s\n", hex);
	printf("Integer value: %d\n", converted);
	return 0;
}

int htoi(char string[]){

	/* flag indicates whether the current digit is valid hex,
	   value stores the value of the current digit */
	int value = 0;
	int flag = 1;
	int i = 0;
	int n = 0;

	/* Check whether string begins with 0x or 0X */
	if(string[i]=='0' && (string[i+1]=='x' || string[i+1]=='X'))
		i = 2;

	/* Check for valid hex values */
	while(flag){
		if(string[i]>='0' && string[i]<='9')
			value = string[i] - '0';
		else if(string[i]>='a' && string[i]<='f')
			value = string[i] - 'a' + 10;
		else if(string[i]>='A' && string[i]<='F')
			value = string[i] - 'A' + 10;
		else
			flag = 0;

		/* If valid, add to current value */
		if(flag)
			n = 16*n + value;
		i++;
	}
	return n;
}