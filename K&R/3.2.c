#include <stdio.h>

/* Convert newlines and tabs to visible escape
   sequences like \n and \t while copying the
   string s to string t (using a switch)       */
void escape(char s[], char t[]);

int main(){
	char s1[] = "Dave\thas\tsome\ttabs";
	char s2[40];
	escape(s1, s2);
	printf("What we see: \t\t%s\n", s1);
	printf("What the computer sees: %s\n", s2);
	return 0;
}

void escape(char s[], char t[]){
	int i, j;

	/* i points to position in original array,
	   j points to position in the new array   */
	for(i=j=0; s[i]!='\0'; i++){
		switch(s[i]){
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			default:
				t[j++] = s[i];
				break;
		}
	}
	t[j] = '\0';
}