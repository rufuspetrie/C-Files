#include <stdio.h>

/* Return location of first character in s1 contained in s2 */
int any(char s1[], char s2[]);

int main(){
	char v1[] = "Rufus";
	char v2[] = "pringles";
	int x = any(v1, v2);
	printf("%d\n", x);
	return 0;
}

int any(char s1[], char s2[]){
	int i, j;

	for(i=0; s1[i]!='\0'; i++)
		for(j=0; s2[j]!='\0'; j++)
			if(s1[i]==s2[j])
				return i;
	return -1;
}