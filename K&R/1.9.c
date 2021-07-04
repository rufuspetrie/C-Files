#include <stdio.h>

int main(){
	int c, space_count;
	space_count = 0;

	while((c = getchar()) != EOF)
		if(c != ' '){
			putchar(c);
			space_count = 0;
		}	
		else{
			if(space_count == 0)
				putchar(c);
				space_count++;
		}
	return 0;
}