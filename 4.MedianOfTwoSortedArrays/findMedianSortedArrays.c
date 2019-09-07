#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(X, Y) (X < Y ? X : Y)

int findkth(int *a, int m, int *b, int n, int k)
{
	if(m > n) return findkth(b, n, a, m, k);
	//m < n
	if(m == 0) return b[k-1];
	if(k == 1) return MIN(a[0], b[0]);
	int ka = MIN(m, k>>1);
	int kb = k - ka;

	printf("m:%d, n:%d\n", m, n);
	printf("k:%d, ka:%d, kb:%d\n", k, ka, kb);
	printf("a[ka-1]=%d, b[kb-1]=%d\n", a[ka-1], b[kb-1]);
	if(a[ka-1] < b[kb-1])
		return findkth(a+ka, m-ka, b, n, k-ka);
	else if (a[ka-1] > b[kb-1])
		return findkth(a, m, b+kb, n-kb, k-kb);
	
	return a[ka-1];
}


double findMedianSortedArrays(int a[], int m, int b[], int n)
{
	//assert(!(m == 0 && n == 0));
	if ((m+n)&0x1)
	return findkth(a, m, b, n, ((m+n)>>1)+1);
	return (double)(findkth(a, m, b, n, ((m+n)>>1)+1) + findkth(a, m, b, n, (m+n)>>1)) / 2;
}


int main(int argc, char const *argv[])
{
	int arr2[] = {1,2,3,5,9};
	int arr1[] = {4,5,6};

	double medianValue = findMedianSortedArrays(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int));

	printf("medianValue=%f\n", medianValue);

	/* code */
	return 0;
}
