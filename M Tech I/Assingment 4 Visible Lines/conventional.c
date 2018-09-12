#include<stdio.h>
#include<stdbool.h>

int N;

void removeLine(int i, int label[]){
	printf("%d %d\n",i,label[i]);
	label[i] = 0;
}

int intersection(float m1,float c1,float m2,float c2,int flag){
	static float inter;
	float x = (c1 - c2)/(m2 - m1);
	float y = m1 * x + c1;
	//printf("m = %f c = %f x = %f y = %f inter = %f\n",m2,c2,x,y,inter);
	if(y > inter)
		inter = y;
	else
		return 1;
	return 0;	
}

void checkLine(float m[], float c[], int label[]){
    intersection(m[0],c[0],m[N-1],c[N-1],1);
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N-1;j++){
			if(label[i] != 0){
				if(m[i] == m[j]) // slope is equal
				    c[i] > c[j] ? removeLine(i+1, label) : removeLine(i, label);
		        else{
			        int x = intersection(m[0],c[0],m[j],c[j],0);
					//printf("%d\n",x);
				    int y = intersection(m[N-1],c[N-1],m[j],c[j],0);// slope is unequal than check for intersection
			        //printf("%d\n",y);
					if(x && y)
						removeLine(j, label);
		        }
		    }
		}
	}
}

void swap(float* a, float* b){
    float t = *a;
    *a = *b;
    *b = t;
}

void track(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(float m[], float c[], int label[]){
   int i, j;
   bool swapped;
   for (i = 0; i < N-1; i++){
     swapped = false;
     for (j = 0; j < N-i-1; j++){
        if (m[j] > m[j+1]){
           swap(&m[j], &m[j+1]);
		   swap(&c[j], &c[j+1]);
		   track(&label[j], &label[j+1]);
           swapped = true;
        }
     }
     if (swapped == false)
        break;
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
	
	sort(m,c,label);
	
	checkLine(m,c,label);
	
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