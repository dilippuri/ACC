#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define INF INT_MAX

void badness(int n, int M, int table[][n], int l[]){
	
	int extras[n][n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			extras[i][j] = 0;
	
	int i, j; 
  
    // calculate extra spaces in a single line. 
	//The value extra[i][j] indicates extra spaces if words from word number i to j are placed in a single line 
    for(i = 0; i < n; i++){ 
        extras[i][i] = M - l[i]; 
        for(j = i+1; j < n; j++) 
            extras[i][j] = extras[i][j-1] - l[j] - 1; 
    } 
    
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",extras[i][j]);
		printf("\n");
	}printf("\n");
	
    // Calculate line cost corresponding to the above calculated extra spaces.
	//The value table[i][j] indicates cost of putting words from word number i to j in a single line 
    for(i = 0; i < n; i++){ 
        for(j = i; j < n; j++){ 
            if (extras[i][j] < 0) 
                table[i][j] = INF; 
            else if (j == n && extras[i][j] >= 0) 
                table[i][j] = 0; 
            else
                table[i][j] = extras[i][j]*extras[i][j]; 
        } 
    } 
  
  
    int cost[n+1];
    int split[n+1];	
    // Calculate minimum cost and find minimum cost arrangement. 
    //  The value c[j] indicates optimized cost to arrange words from word number 1 to j. 
    
	for(int z=0;z<n+1;z++)
		cost[z] = 0;
	
	cost[n-1] = table[n-1][n-1];
	split[n-1] = n;
	
    for(i = n-2; i >= 0; i--){
        cost[i] = INF;		
        for(j = n-1; j >= i; j--){ 
            if(table[i][j] != INF && (cost[j+1] + table[i][j] < cost[i])){ 
                cost[i] = cost[j+1] + table[i][j]; 
                split[i] = j + 1; 
            } 
        } 
    }
	
	for(int x=0;x<n;x++)
        printf("%d ",cost[x]);	
	printf("\n\n");
    
    for(int x=0;x<n;x++)
        printf("%d ",split[x]);	
	printf("\n\n");
}

void wordLen(int *l, char *s){
	int i = 0;
	int j = 0;
	int count = 0;
	while(s[i] != '\0'){
		if(s[i] == ' '){
			if(j == 0){
				l[j] = i;
				count = i;
			}
			else{
				l[j] = (i-1) - count;
				count = i;
			}
			j++;
		}
		i++;
	}
	l[j] = (i-1) - count;
}

int wordCount(char *s){
	int i = 0;
	int count = 0;
	while(s[i] != '\0'){
		if(s[i] == ' ')
			count++;
		i++;
	}
	return count + 1;
}

int main(){
	char text[1000];
	//taking input from file
	FILE *fs;
	fs = fopen("plaintext.txt","r");
	fscanf(fs,"%[^\n]",text);
	fclose(fs);
	//wordCount calculates number of words in a paragraph
	int n = 10;
	n = wordCount(text);
	//stores the cost of word in each line
	int table[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			table[i][j] = 0;
	//stores the number of words in each line	
	int l[n];
	
    wordLen(l,text);
	
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",table[i][j]);
		printf("\n");
	}printf("\n");	

    for(int i=0;i<n;i++)
        printf("%d ",l[i]);
	
    int rightMargin;
	printf("\nEnter the length of screen\n");
    scanf("%d",&rightMargin);
	//
	badness(n,rightMargin,table,l);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",table[i][j]);
		printf("\n");
	}printf("\n");
	
	return 0;
}