#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include "bubbleSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"

#define MILLION 1000000

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);

	struct timeval tpstart;
	struct timeval tpend;
	long timedif;
	//--------------------Bubble Sort---------------------------------------------------------------------------------
    gettimeofday(&tpstart, NULL);
	printf("Number of swaps in Bubble Sort : %ld\n",bubbleSort(arr,n));
    gettimeofday(&tpend, NULL);

    timedif = MILLION* (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

	fprintf(stderr, "It took %ld microseconds\n", timedif);
	
	printf("\n");
    //--------------------Insertion Sort---------------------------------------------------------------------------------
    gettimeofday(&tpstart, NULL);
	printf("Number of swaps in Insertion Sort : %ld\n",insertionSort(arr,n));
    gettimeofday(&tpend, NULL);

    timedif = MILLION* (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

	fprintf(stderr, "It took %ld microseconds\n", timedif);
	
	printf("\n");
	//--------------------Merge Sort-------------------------------------------------------------------------------------
	gettimeofday(&tpstart, NULL);
	printf("Number of swaps in Merge Sort : %ld\n",mergeSort(arr,0,n-1));
    gettimeofday(&tpend, NULL);

    timedif = MILLION* (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

	fprintf(stderr, "It took %ld microseconds\n", timedif);
	
	printf("\n");
	//--------------------Quick Sort-------------------------------------------------------------------------------------
	gettimeofday(&tpstart, NULL);
	printf("Number of swaps in Quick Sort : %ld\n",quickSort(arr,0,n-1));
    gettimeofday(&tpend, NULL);

    timedif = MILLION* (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

	fprintf(stderr, "It took %ld microseconds\n", timedif);
	
	printf("\n");
	//---------------------Heap Sort-------------------------------------------------------------------------------------
	gettimeofday(&tpstart, NULL);
	printf("Number of swaps in Heap Sort : %ld\n",heapSort(arr,n));
    gettimeofday(&tpend, NULL);

    timedif = MILLION* (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

	fprintf(stderr, "It took %ld microseconds\n", timedif);
	
	return 0;
}
