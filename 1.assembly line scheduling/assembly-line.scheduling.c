#include<stdio.h>

#define num_line 2

int num_station;

int min(int a, int b){
	return a<b?a:b;
}

int assembly_line_scheduling(int *e,int *x,int a[][num_station],int t[][num_station]){
	int T1[num_station];
	int T2[num_station];
	T1[0]=a[0][0]+e[0];
	T2[0]=a[1][0]+e[1];
	for(int i=1;i<num_station;i++){
		T1[i]=min(T1[i-1]+a[0][i], T2[i-1]+t[1][i]+a[0][i]);
		T2[i]=min(T2[i-1]+a[1][i], T1[i-1]+t[0][i]+a[1][i]);
	}
	return min(T1[num_station-1]+x[0], T2[num_station-1]+x[1]);
}

int main(){
	printf("Enter the number of station\n");
	scanf("%d",&num_station);
	int e[num_line];
	int x[num_line];
	for(int i=0;i<num_line;i++){
		printf("Enter the weight of entry point for station %d\n",i+1);
		scanf("%d",&e[i]);
	}
	for(int i=0;i<num_line;i++){
		printf("Enter the weight of exit point for station %d\n",i+1);
		scanf("%d",&x[i]);
	}
	int a[num_line][num_station];
	for(int i=0;i<num_line;i++){
		for(int j=0;j<num_station;j++){
			printf("Enter the weight of station a%d%d\n",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	int t[num_line][num_station];
	for(int i=0;i<num_line;i++){
		for(int j=0;j<num_station;j++){
			printf("Enter the time t%d%d\n",i+1,j+1);
			scanf("%d",&t[i][j]);
		}
	}
	printf("%d",assembly_line_scheduling(e,x,a,t));
	return 0;
}