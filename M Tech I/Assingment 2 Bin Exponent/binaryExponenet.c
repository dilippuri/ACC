#include<stdio.h>

int ans=1;

int bin_exponent(int x, int m){
	int q=m/2;
	int r=m%2;
	if(r == 1)
		return ans*x;
	if(q==0)
		return ans;
	m=q;
	x=x*x;
	bin_exponent(x,m);
}

int main(){
	printf("%d",bin_exponent(3,4));
	return 0;
}