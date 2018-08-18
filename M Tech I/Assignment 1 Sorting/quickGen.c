#include <stdio.h>

void generate(int n,int piv,int a[]){
	int m = n/2;
	int i=0;
	while(m){
		a[i] = piv - i - 1;
		m--;
		i++;
	}
	a[i++] = piv;
	while(i <= n){
		a[i] = piv + m + 1;
		m++;
		i++;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int pivot;
	printf("Enter number greater than %d\n",n);
	scanf("%d",&pivot);
	int arr[n];
	
	generate(n-1,pivot,arr);
	
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
		
	return 0;
}