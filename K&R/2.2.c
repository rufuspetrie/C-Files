#include <stdio.h>

int main(){
	return 0;
}

/* Original Loop:
for(i=0; i<lim-1 && (c=getchar())!='\n' && c!=EOF; i++)
	s[i] = c;
*/

/* New Version:
bool flag = true;
while(flag)
	if(i>=lim-1)
		flag = false;
	else if((c=getchar())=='\n')
		flag = false;
	else if(c==EOF)
		flag = false;
	else{
		s[i] = c;
		i++;
	}

*/