#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found  */

void push(double);
double pop(void);
/* getop:  get next operator or operand */
int getop(char[]);
/* getch: check a buffer for stored input before using getchar() */
int getch(void);
/* ungetch: store extra input in a buffer for future use */
void ungetch(int);

int main(){
	int type;
	double op2;
	char s[MAXOP];

	while((type=getop(s))!=EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop()+pop());
				break;
			case '*':
				push(pop()*pop());
				break;
			case '-':
				op2 = pop();
				push(pop()-op2);
				break;
			case '/':
				op2 = pop();
				if(op2!=0)
					push(pop()/op2);
				else
					printf("error: zero division\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f){
	if(sp<MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void){
	if(sp>0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next operator or operand */
int getop(char s[]){
	int i, c;

	/* skip whitespace, find first character */
	while((s[0]=c=getch())==' ' || c=='\t')
		;
	s[1] = '\0';
	/* if c isn't a number, return it */
	if(!isdigit(c) && c!='.')
		return c;
	i = 0;
	/* collect integer part */
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()))
			;
	/* collect fraction part */
	if(c=='.')
		while(isdigit(s[++i]=c=getch()))
			;
	s[i] = '\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;
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