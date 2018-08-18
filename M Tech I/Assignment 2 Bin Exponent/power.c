#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include<math.h>

#define MILLION 1000000

long power(long a, long b){
	return pow(a,b);
}


long bin_exponent(long x, long m, long ans){
	long q=m/2;
	long r=m%2;
	if(r == 1)
		ans=ans*x;
	if(q == 0)
		return ans;
	m=q;
	x=x*x;
	bin_exponent(x,m,ans);
}

int main() 
{

	struct timeval tpstart;
	struct timeval tpend;
	long timedif;
	
	int iters;

	printf("Please Enter the number of iterations\n");
	scanf("%d", &iters);
	printf("\n");
	
	for(int i=0;i<iters;i++){
	
	    int x,y;
		scanf("%d %d",&x,&y);
		
        gettimeofday(&tpstart, NULL);
		printf("Inbuilt = %ld\n",power(x,y));
        gettimeofday(&tpend, NULL);
		
	    timedif = MILLION* (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;				
	    fprintf(stderr, "It took %ld microseconds\n", timedif);
					
		gettimeofday(&tpstart, NULL);
		printf("Bin_exponent = %ld\n",bin_exponent(x,y,1));
        gettimeofday(&tpend, NULL);
		
	    timedif = MILLION* (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	    fprintf(stderr, "It took %ld microseconds\n\n", timedif);
	}
    return 0;
}