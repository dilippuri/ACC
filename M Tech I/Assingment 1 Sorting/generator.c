#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fs;
	fs = fopen("hund_thous_wrost_case.txt","w+");//rename file name for every input
	int n;
	printf("Enter size of input to be generated\n");
	scanf("%d",&n);
	int c;
	printf("\nPress 0 for ascending order\nPress 1 for descending order\nPress 2 for random order\n");
	scanf("%d",&c);
	
	switch(c){
		case 0:
		        for(int i=1;i<=n;i++){
					fprintf(fs,"%d ",i);
					if(i%10 == 0)
						fprintf(fs,"\n",'\0');
	            }
				break;
		case 1:
		       for(int i=n;i>=1;i--){
				   if(i%10 == 0 && i != n)
						fprintf(fs,"\n",'\0');
					fprintf(fs,"%d ",i);
	            }
				break;
		case 2:
		       for(int i=1;i<=n;i++){
					fprintf(fs,"%d ",rand());
					if(i%10 == 0)
						fprintf(fs,"\n",'\0');
	            }
				break;
	}	
	fclose(fs);
return 0;
}