#include <stdio.h>

/* Delete characters in s1 that occur in s2 */
void squeeze(char s1[], char s2[]);

int main(){
	char v1[] = "Rufus";
	char v2[] = "pringles";
	squeeze(v1, v2);
	printf("%s", v1);
	return 0;
}

/* Idea: for each i in s1, iterate through s2 while s1[i] != s2[j]
   		 if the final value of s2[j] == '\0', copy s1[i]
   		 otherwise, increment i and continue */
void squeeze(char s1[], char s2[]){
	int i, j, k;

	for(i=j=0; s1[i]!='\0'; i++){
		for(k=0; s2[k]!='\0' && s2[k]!=s1[i]; k++)
			; 
		if(s2[k]=='\0')
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}