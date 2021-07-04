#include <stdio.h>

/* strend: return 1 if string t occurs at the
		   end of string 1, and 0 otherwise   */
int strend(char *s, char*t);

int main(){
	char s1[] = "Dave made a save";
	char s2[] = "ave";
	int flag = strend(s1, s2);
	if(flag)
		printf("s1 ends with s2\n");
	return 0;
}

int strend(char *s, char *t){
	/* starting positions for s and t */
	char *ps = s;
	char *pt = t;
	/* move pointers to the end of s and t */
	while(*s!='\0')
		s++;
	while(*t!='\0')
		t++;
	/* iterate backwards while elements are equal*/
	while(*t==*s){
		if(t==pt || s==ps)
			break;
		s--;
		t--;
	}
	/* check initial conditions */
	if(*t==*s && t==pt && *s!='\0')
		return 1;
	return 0;
}