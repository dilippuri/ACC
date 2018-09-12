#include<stdio.h>

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition (int arr[], int low, int high){
    int mid = (low + high) / 2;
	swap(arr,mid,high);
	return mid;
}
 
void quickSort(int arr[], int low, int high){
    if (low < high-1){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot, high-1);
    }
}

int main(){
	int n;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int input[n];
	for(int i=0;i<n;i++)
		input[i] = i+1;
	quickSort(input,0,n-1);
	printf("Quick Sort's Bestest Case Ever\n");
	for(int i=0;i<n;i++)
		printf("%d ",input[i]);
	return 0;
}