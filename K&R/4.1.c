#include <stdio.h>

/* return index of rightmost occurrence of substring t in s */
int strindex(char s[], char t[]);

int main(){
	char s1[] = "Would could should";
	char s2[] = "ould";
	int x = strindex(s1, s2);
	printf("The substring \'%s\' ", s2);
	printf("has its final occurrence in string \'%s\' ", s1);
	printf("at index %d.\n", x);
	return 0;
}

/* Note: can keep most of code from the chapter,
		 just need to keep track of index and return
		 after loop instead of returning the first one */
int strindex(char s[], char t[]){
	int i, j, k;
	int index = -1;

	for(i=0; s[i]!='\0'; i++){
		for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if(k>0 && t[k]=='\0')
			index = i;
	}
	return index;
}