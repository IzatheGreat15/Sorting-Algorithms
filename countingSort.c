#include <stdio.h>
#include <stdlib.h>

void countingSort(int A[], int size){
  int *sorted = (int*)calloc(size, sizeof(int));
  int x, max = A[0];
  //find the largest number in the array
  for(x = 0; x < size; x++){
    max = (max < A[x]) ? A[x] : max;
  }
  
  //create count array with length max + 1
  int *count = (int*)calloc(max + 1, sizeof(int));
  
  //count each occurences of number
  for(x = 0; x < size; x++){
    count[A[x]]++;
  }
  
  //store cumulative sum
  for(x = 1; x < max + 1; x++){
    count[x] += count[x - 1];
  }
  
  //place elements in sorted array
  for(x = 0; x < size; x++){
    sorted[count[A[x]] - 1] = A[x];
    count[A[x]]--;
  }
  
  //transfer sorted array to original array
  for(x = 0; x < size; x++){
    A[x] = sorted[x];
  }
}

int main() {
  int arr[] = {3, 6, 4, 0, 2, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  countingSort(arr, size);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%d ", arr[x]);
  }
  return 0;
}