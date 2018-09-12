#include <stdio.h>

int N;

void removeLine(int i, int label[]){
	label[i] = 0;
}

int intersection(float m1,float c1,float m2,float c2,int flag){
	static float inter;
	float x = (c1 - c2)/(m2 - m1);
	float y = m1 * x + c1;
	if(flag)
		inter = y;
	if(y < inter)
		return 1;
	return 0;	
}

void checkLine(int n, float slope[], float intercept[], int label[]){
	
	intersection(slope[0],intercept[0],slope[n-1],intercept[n-1],1);
	
	for(int i=1;i<n-1;i++){
		if(label[i] != 0){
			if(slope[i] == slope[i+1]) // slope is equal
			    intercept[i] > intercept[i+1] ? removeLine(i+1, label) : removeLine(i, label);
		    else{
			    int x = intersection(slope[0],intercept[0],slope[i],intercept[i],0);
				int y = intersection(slope[n-1],intercept[n-1],slope[i],intercept[i],0);// slope is unequal than check for intersection
			    if(x && y)
					removeLine(i, label);
		    }
		}
	}
}

void merge(int left, int mid, int right, float m[], float c[], int label[]){

    int i, j, k;
    int n = right-left+1;
    float slope[n]; 
	float intercept[n];
    int flag[n];
	
    i = left; 
    j = mid+1; 
    k = 0;
	
    while (i <= mid && j <= right){
        if (m[i] <= m[j]){
            slope[k] = m[i];
			intercept[k] = c[i];
			flag[k] = label[i];
            i++;
        }
        else{
            slope[k] = m[j];
			intercept[k] = c[j];
			flag[k] = label[j];
            j++;
			
        }
        k++;
    }
 
    while (i <= mid){
        slope[k] = m[i];
		intercept[k] = c[i];
		flag[k] = label[i];
        i++;
        k++;
    }
 
    while (j <= right){
        slope[k] = m[j];
		intercept[k] = c[j];
		flag[k] = label[j];
        j++;
        k++;
    }
	
	if(n > 1)
		checkLine(n, slope, intercept, flag);
	
	for (int z=0;z<n;z++)
        label[z+left] = flag[z];
	
	for (int z=0;z<n;z++){
        m[z+left] = slope[z];
		c[z+left] = intercept[z];
	}
}

void mergeSort(int left, int right, float m[], float c[], int label[]){
    if (left < right){
        int mid = (left+right)/2;
        mergeSort(left, mid, m, c, label);
        mergeSort(mid+1, right, m, c, label);
        merge(left, mid, right, m, c, label);
    }
}

int main(){
	printf("Enter the number of lines\n");
	scanf("%d",&N);
	float m[50];
    float c[50];
    int label[50];
	float slope, intercept;
	for(int i=0;i<N;i++){
		printf("Enter slope and y-intercept of line %d\n",i);
		scanf("%f %f",&slope,&intercept);
		m[i] = slope;
		c[i] = intercept;
		label[i] = i + 1;
	}
	
	mergeSort(0,N-1,m,c,label);
	
	printf("Equation of line that are visible are:\n");
	for(int i=0;i<N;i++){
		if(label[i] != 0){
			if(c[i] >= 0)
				printf("y = %0.2fx+%0.2f     %d\n",m[i],c[i],label[i]);
			else
				printf("y = %0.2fx%0.2f     %d\n",m[i],c[i],label[i]);
		}			
	}
	return 0;
}