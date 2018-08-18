long swaps;

long insertionSort(int arr[], int n){
   int i, key, j;
   for (i = 1; i < n; i++){
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key){
           arr[j+1] = arr[j];
           j = j-1;
		   swap(0,0);
       }
       arr[j+1] = key;
   }
   return swaps;
}