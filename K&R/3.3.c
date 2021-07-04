#include <stdio.h>

/* Expand hyphenated notation like a-z in s1
   into a complete like abc...xyz in s2		 */
void expand(char s1[], char s2[]);

int main(){
	char v1[] = "a-z";
	char v2[100];
	expand(v1, v2);
	printf("Original string: %s\n", v1);
	printf("Expanded string: %s\n", v2);
	return 0;
}

void expand(char s1[], char s2[]){
	char c;
	int i = 0;
	int j = 0;

	/* notice: invariant retrieves c and increments i */
	while((c=s1[i++])!='\0')
		if(s1[i]=='-' && s1[i+1>=c]){
			/* increment i to skip the hyphen */
			i++;
			while(c<s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;
	s2[j] = '\0';
}