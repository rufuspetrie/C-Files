#include <stdio.h>

/* Perform binary search on integer array
   of length n to look for element x */
int binsearch(int x, int v[], int n);

int main(){
	int arr[] = {1,2,3,4,5};
	int pos_5 = binsearch(5, arr, 5);
	printf("Element 5 is located at index: %d", pos_5);
	return 0;
}

/* New binsearch */
int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n-1;
	mid = (low+high)/2;
	while((low<=high) && (v[mid]!=x)){
		if(x<v[mid])
			high = mid-1;
		else if(x>v[mid])
			low = mid+1;
		mid = (low+high)/2;
	}
	if(v[mid]==x)
		return mid;
	return -1;
}

/*Original binsearch
int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n-1;
	while(low<=high){
		mid = (low+high)/2;
		if(x<v[mid])
			high = mid-1;
		else if(x>v[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;
}*/