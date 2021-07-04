#include <stdio.h>
#include <string.h>

/* convert integer n to characters in string s */
void itoa(int n, char s[]);

/* reverse character array s1 */
void reverse(char s1[]);

int main(){
	int v1 = 123456;
	char v2[6];
	printf("As an integer: %d\n", v1);
	itoa(v1, v2);
	printf("As a string: %s\n", v2);
	return 0;
}

void itoa(int n, char s[]){
	int i = 0;
	int sign = n;

	do{
		if(n%10>0)
			s[i++] = (n%10) + '0';
		else
			s[i++] = (-1*(n%10)) + '0';
	}while((n/=10) != 0);

	if(sign<0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
    int length = strlen(s) ;
    int c, i, j;

    for (i=0, j=length-1; i<j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* Original Version
   This doesn't work because the expression n = -n
   will overflow for the most negative integer value
   Therefore, must apply the negative after conversion
void itoa(int n, char s[]){
	int i, sign;

	if((sign = n) < 0)
		n = -n;
	i = 0;
	do{
		s[i++] = n%10 + '0';
	} while((n/=10) > 0);
	if(sign<0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}*/