#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include <math.h>
//#include <sys/ioctl.h>
#include <unistd.h>

#define inf FLT_MAX
#define pline printf("\n");

int tChar=0;

struct strgn{
	char *x;
};

int wordcnt(char *str){
	int i=0;int flag=0; int wc=1;
	while(str[i]!='\0'){
		i++;
		if(flag==0 && str[i]==' '){
			wc++;
			flag=1;
		}
		else if(str[i]!=' '){
			flag=0;
		}
	}
return wc;
}

int* wlen(char *str, int wc){
	int* wl = malloc(sizeof(int)*wc);
	int i=0, flag=0, wordlen,j=0;
	while(str[i]!='\0'){
		if(flag==0 && str[i]==' '){
			wl[j]=wordlen;j++;
			tChar += wordlen;
			wordlen=0;
			flag=1;
		}
		else if(str[i]!=' '){
			flag=0;
			wordlen++;
		}
		i++;
	}wl[j]=wordlen-1;tChar += wordlen-1;

return wl;
}

void badness(int **mat, int *p, int dim, int line){
	int i,j,k,temp,flag;
	for(i=0 ; i < dim; i++){
		mat[i][i] = line - p[i];
		for(j=i+1; j < dim; j++){
			mat[i][j] = mat[i][j-1] - p[j] - 1; 
		}
	}
	for(i=0; i < dim; i++){
            for(j=i; j < dim; j++){
                if(mat[i][j] < 0){
                    mat[i][j] = 50000;
                }else{
                    mat[i][j] = (int)(mat[i][j]*mat[i][j]);
                }
            }
	}
}

int* justify(int **mat, int dim){
	int minCost[dim];
	int* result = malloc(sizeof(int)*dim);
	int i;
	for(i=0;i<dim;i++){minCost[i]=0;result[i]=0;}
	for(i = dim-1; i >= 0 ; i--){
		minCost[i] = mat[i][dim-1];
		result[i] = dim;
		int j;
		for(j=dim-1; j > i; j--){
			if(mat[i][j-1] == 50000){
				continue;
			}
			if(minCost[i] > (minCost[j] + mat[i][j-1])){
				minCost[i] = minCost[j] + mat[i][j-1];
				result[i] = j;
			}
		}
	}
	printf("----------------------------------------------------\n");
	printf("Min cost %d\n",minCost[0]);
//	for(i=0;i<dim;i++){printf("%d ",result[i]);}pline
	return result;
}

void splitWords(char *strg, struct strgn *lin){
	char * pch;int i=0;
	pch = strtok (strg," ");
	while (pch != NULL){
		lin[i++].x = pch;
		pch = strtok (NULL, " ");
	}
}

void pretty(struct strgn *str, int *q, int dim){
	int i=0,j=0,k=0;
	printf("\b----------------------------------------------------");
	pline
	do{
		j = q[i];
		for(k=i; k < j; k++){
			printf("%s ",str[k].x);
		}
		printf("\n");
		i = j;
	}while(j < dim);
	printf("\b----------------------------------------------------");
	pline
}

int main(){

int i=0,j,k,**mat,dim;

FILE *fp; char ch; char str[6000];// = (char *)malloc(sizeof(char));
fp = fopen("plaintext.txt","r");
while((ch = fgetc(fp))!=EOF){
	str[i]=ch;
	i++;
}str[i] = '\0';
fclose(fp);

dim = wordcnt(str);				// it will count the no of words
int *p=wlen(str, dim);			//it will return the array which contains the length of each word

mat = calloc(dim,sizeof(int*));	//2d array initialization with 0 size of dim(total words)
for(i=dim-1; i>-1; i--)
    mat[i]=(int*)calloc(dim,sizeof(int));

//struct winsize w;				//it will find the size of terminal(console) (w.ws_row, w.ws_col)
//ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

badness(mat,p,dim,10);	//it will fill the 2d matrix (upper matrix) with badness value (width - len(words))^2

/*
printf("Badness Matrix: \n");
for(i=0; i<dim; i++)
    for(j=0; j<dim; j++)
        printf("%d%c",j>=i?mat[i][j]:0,j!=dim-1?' ':'\n');
*/

int *q = justify(mat,dim);		//it will find that how many words print in line so it optimize total badness
struct strgn lin[5000];
splitWords(str, lin);			//it will split words from string

for(i=0;i<dim;i++){
	printf("%s ",lin[i].x);
}
pretty(lin,q,dim);				//it will print words

return 0;
}
