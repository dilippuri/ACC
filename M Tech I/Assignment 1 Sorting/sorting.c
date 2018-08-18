#include <stdio.h>
#include <stdbool.h>
#include "insertionSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("%d\n",bubbleSort(arr,n));
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n%d\n",insertionSort(arr,n));
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n%d\n",mergeSort(arr,0,n-1));
	for(int i=0;i<n;i++)	
		printf("%d ",arr[i]);
	printf("\n%d\n",quickSort(arr,0,n-1));
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n%d\n",heapSort(arr,n));
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}