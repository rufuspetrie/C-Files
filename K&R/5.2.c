#include <stdio.h>
#include <ctype.h>

/* read input, store in buffer if non-integer */
int getch(void);
void ungetch(int);
/* read valid integer from input into variable n */
int getint(float *pn);

int main(){
	float n = 0;
	int status = getint(&n);
	if(status)
		printf("The program has read value %f into n.\n", n);
	else
		printf("Invalid input.\n");
	return 0;
}

/* getint: get next integer from input into *pn */
int getint(float *pn){
	int c, sign, pm;
	float power;

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
	/* integer digits */
	for(*pn=0; isdigit(c); c=getch())
		*pn = 10*(*pn) + (c-'0');
	/* check for decimal point */
	if(c=='.')
		c = getch();
	/* floating digits */
	for(power=1.0; isdigit(c); c=getch()){
		*pn = 10*(*pn) + (c-'0');
		power *= 10;
	}
	*pn *= sign;
	*pn /= power;
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