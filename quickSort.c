#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int start, int end){
    int pivot = A[end]; //pivot is the last element of the segment
    int x, pIndex;

    for(x = pIndex = 0; x < end; x++){
        if(A[x] < pivot){
            swap(&A[x], &A[pIndex]);
            pIndex++;
        }
    }
    swap(&A[pIndex], &A[end]);

    return pIndex;
}

void quickSort(int A[], int start, int end){
    if(start >= end)
        return;

    /* arrange elements lesser than the pivot to the left and elements greater than the pivot to the right */
    int pIndex = partition(A, start, end);

    /* perform quick sort on the left segment */
    quickSort(A, start, pIndex - 1);

    /* perform quick sort on the right segment */
    quickSort(A, pIndex + 1, end);
}

int main() {
  int arr[] = {3, 6, 4, 0, 2};
  int size = sizeof(arr)/sizeof(arr[0]);
  quickSort(arr, 0, size - 1);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%d ", arr[x]);
  }
  return 0;
}