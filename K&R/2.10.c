#include <stdio.h>

/* Convert character to lowercase using conditional expression */
int to_lower(int c);

int main(){
	int v1 = 'R';
	int v2 = to_lower(v1);
	printf("%c %c\n", v1, v2);
	return 0;
}

int to_lower(int c){
	return (c>='A' && c<='Z') ? c+'a'-'A' : c;
}