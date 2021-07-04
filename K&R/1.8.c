#include<stdio.h>

int main(){
	int c, count;

	count = 0;
	while((c=getchar())!=EOF)
		if(c=='\n' || c=='\t' || c==' ')
			count += 1;
	printf("%d\n", count);
	return 0;
}

/* Note: to put an EOF into terminal, use control-z */