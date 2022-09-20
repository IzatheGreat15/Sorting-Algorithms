#include <stdio.h>
#include <stdlib.h>

/*
    sort the array using counting sort per digit
 */
int findMax(int A[], int size){
    int max = A[0];
    int x;
    for(x = 0; x < size; x++){
        max = (max < A[x]) ? A[x] : max;
    }

    return max;
}

void countingSort(int A[], int size, int exp){
    int divide = exp / 10;
    //find largest digit based on exp
    int max = A[0] / divide % exp; 
    int x;
    for(x = 0; x < size; x++){
        max = (max < A[x] / divide % exp) ? A[x] / divide % exp : max;
    }
    
    //create sorted and count array
    int *sorted = (int*)calloc(size, sizeof(int));
    int *count = (int*)calloc(max + 1, sizeof(int));

    //count each occurences of number
    for(x = 0; x < size; x++){
        count[A[x] / divide % exp]++;
    }

    //store cummulative sum
    for(x = 1; x < max + 1; x++){
        count[x] += count[x - 1];
    }
    //place elements in sorted array
    for(x = size - 1; x >= 0; x--){
        sorted[count[A[x] / divide % exp] - 1] = A[x];
        count[A[x] / divide % exp]--;
    }

    //transfer sorted array to original array
    for(x = 0; x < size; x++){
        A[x] = sorted[x];
    }
}

void radixSort(int A[], int size){
  // find largest number of digit
  int digit = 0, exp, x;
  int max = findMax(A, size);
  for(;max > 0; digit++, max /= 10){}

  // perform counting sort per digit
  for(x = 0, exp = 10; x < digit; x++, exp *= 10){
    countingSort(A, size, exp);
  }
}

int main() {
  int arr[] = {23, 906, 14, 0, 342};
  int size = sizeof(arr)/sizeof(arr[0]);
  radixSort(arr, size);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%d ", arr[x]);
  }
  return 0;
}