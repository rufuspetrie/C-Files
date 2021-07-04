#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max input size */

char *lineptr[MAXLINES];
char *temp;
int readlines(char *lineptr[], char *temp, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(){
	int nlines;

	if((nlines = readlines(lineptr, temp, MAXLINES))>=0){
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else{
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000 /* max length of input line */
int getline(char *, int);

/* readlines: read iput lines */
int readlines(char *lineptr[], char *temp, int maxlines){
	int len, nlines;
	char *p = temp;
	char *upper = temp + MAXLEN;
	char line[MAXLEN];

	/* update: check whether len exceeds space allocated
			   to the temporary array */
	nlines = 0;
	while((len = getline(line, MAXLEN))>0)
		if(nlines>=maxlines || p+len>upper)
			return -1;
		else{
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
	while(nlines-->0)
		printf("%s\n", *lineptr++);
}

/* getline: read line into s, return length */
int getline(char *s, int lim){
	int c, i;

	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
		s[i] = c;
	if(c=='\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right){
	int i, last;
	void swap(char *v[], int i, int j);

	if(left>=right)
		return;
	swap(v, left, (left+right)/2);
	last = left;
	for(i=left+1; i<=right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j){
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}