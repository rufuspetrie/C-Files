#include <stdio.h>

/* stradd: copy string t to the end of string s */
void stradd(char *s, char *t);

int main(){
	char s1[] = "Dave";
	char s2[] = " likes hockey.";
	stradd(s1, s2);
	printf("%s", s1);
	return 0;
}

/* stradd: copy string t to the end of string s 
	 note: comparisons to '\0' are unnecessary */
void stradd(char *s, char *t){
	/* move s pointer to end of string */
	while(*s!='\0')
		s++;
	/* copy elements over */
	while((*s++=*t++)!='\0')
		;
	*s = '\0';
}