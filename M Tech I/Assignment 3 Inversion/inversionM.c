#include<stdio.h>
#include<stdlib.h>

int merge(int arr[], int l, int m, int r){
	int count = 0;
    int i, j, k;
    int n = r-l+1;
    int aux[n];

    i = l; 
    j = m+1; 
    k = 0; 
    while (i <= m && j <= r){
        if (arr[i] <= arr[j]){
            aux[k] = arr[i];
            i++;
        }
        else{
            aux[k] = arr[j];
            j++;
			//printf("m = %d, i = %d\n",m,i);
			count += (m - i + 1);
        }
        k++;
    }
 
    while (i <= m){
        aux[k] = arr[i];
        i++;
        k++;
    }
 
    while (j <= r){
        aux[k] = arr[j];
        j++;
        k++;
    }
	for (int z=0;z<n;z++)
        arr[z+l] = aux[z]; 
	return count;
}

int mergeSort(int arr[], int l, int r){

	int count = 0;
	
	if(r > l){
		int m = (l + r)/2;
	    count = mergeSort(arr, l, m);
	    count += mergeSort(arr, m+1, r);
	    count += merge(arr, l, m, r);
	    return count;
	}
	return count;
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	printf("Inversion : %d\n",mergeSort(arr,0,n-1));
	
	//for(int i=0;i<n;i++)
		//printf("%d ",arr[i]);
	
	return 0;
}