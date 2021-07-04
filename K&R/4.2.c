#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[]);

int main(){
	char s1[] = "6.02e+23";
	double s2 = atof(s1);
	printf("Here is a string: %s\n", s1);
	printf("Here is a double: %f\n", s2);
	return 0;
}

/* atof: convert string s to double */
double atof(char s[]){
	double val, power;
	int i, sign, exponent;

	/* skip leading whitespace */
	for(i=0; isspace(s[i]); i++)
		;
	/* check for negative sign */
	sign = (s[i]=='-') ? -1 : 1;
	/* skip over sign if it's there */
	if(s[i]=='+' || s[i]=='-')
		i++;
	/* scan digit values and multiply appropriately */
	for(val=0.0; isdigit(s[i]); i++)
		val = 10.0*val + (s[i]-'0');
	/* done, check for decimal point and increment */
	if(s[i]=='.')
		i++;
	/* scan digits (increase power to support simple addition) */
	for(power=1.0; isdigit(s[i]); i++){
		val = 10.0*val + (s[i]-'0');
		power *= 10.0;
	}
	/* adjust size back to normal and apply correct sign */
	val = sign*val/power;

	/* New: check for power at the end of the string
			because the power may be >10, must repeat
			the routine to multiply each spot by 10   */
	if((s[i]=='e') || (s[i]=='E')){
		i++;
		sign = (s[i]=='-') ? -1 : 1;
		if((s[i]=='+') || (s[i]=='-'))
			i++;
		for(exponent=0; isdigit(s[i]); i++)
			exponent = 10*exponent + (s[i]-'0');
		/* adjust value by appropriate amounts*/
		if(sign){
			for(i=0; i<exponent; i++)
				val *= 10;
		}
		else{
			for(i=0; i<exponent; i++)
				val /= 10;
		}
	}
	return val;
}