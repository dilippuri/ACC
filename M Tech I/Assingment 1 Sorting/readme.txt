_______________README_____________________________

1. Run SortingT.c
  1.1 All the sorting functions are included as header files.

2. Input size of array and array elements.

3. Output is 
   . Number of swaps for each sorting techniques for particular input.
  . Time require to complete the execution of each sorting techniques in microsecond.

*note : . All the readings in Output.doc is obtained while running the program in windows environment. 
            . generator.c is used to generate the inputs for testcases.
           . All the testcase used is present in Inputs folder.

____________ANALYSIS______________________________

1. Both Bubble Sort and Insertion Sort has zero swaps in Best Case.

2. In both Bubble Sort and Insertion sort best case occur when elements are in ascending order and worst case occur when elements are in descending    order.

3. Merge sort is non-adaptive sorting algorithm because it's run time does not effected by the sortedness of array elements.
    It is up-place sorting algorithm because it takes O(n) space complexity.

4. Quick Sort O(nlogn) in Best case and O(n^2) in Wrost case. 
   Here best case and wrost case depends upon the sortedness of array elements.

5. Beat Case and Worst Case of Heap Sort is O(n.logn).
  Assuming you're using a max heap represented as an array and inserting your max elements backwards into your output array/into the back of your  array if you're doing it in-place, the worst case input for heapSort is any input that forces you to "bubble down" or reheapify every time you remove an   element. This happens every time you are trying to sort a set with no duplicates. It will still be Θ(n log n).

This property implies that heapSort's best-case is when all elements are equal (Θ(n), since you don't have to reheapify after every removal, which takes log(n) time since the max height of the heap is log(n)). It's kind of an impractical case, though, which is why the real best case for heapsort is Θ(n log n).                                                                                                                

