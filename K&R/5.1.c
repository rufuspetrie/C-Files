#include <stdio.h>
#include <ctype.h>

/* read input, store in buffer if non-integer */
int getch(void);
void ungetch(int);
/* read valid integer from input into variable n */
int getint(int *pn);

int main(){
	int n = 0;
	int status = getint(&n);
	if(status)
		printf("The program has read value %d into n.\n", n);
	else
		printf("Invalid input.\n");
	return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn){
	int c, sign, pm;

	/* skip whitespace */
	while(isspace(c=getch()))
		;
	/* non-numeric input */
	if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
		ungetch(c);
		return 0;
	}
	/* set appropriate sign */
	sign = (c=='-') ? -1 : 1;
	/* UPDATE: ensure that an integer follows the sign */
	if(c=='+' || c=='-'){
		pm = c;
		c = getch();
		if(!isdigit(c)){
			if(c!=EOF)
				ungetch(c);
			ungetch(pm);
			return 0;
		}
	}
	for(*pn=0; isdigit(c); c=getch())
		*pn = 10*(*pn) + (c-'0');
	*pn *= sign;
	if(c!=EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buffer */

/* getch: check for characters in buffer
		  if there aren't any, use getchar() */
int getch(void){
	return (bufp>0) ? buf[--bufp] : getchar();
}

/* ungetch: return extra characters taken from input
			back into a buffer for future use 		 */
void ungetch(int c){
	if(bufp>=BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}