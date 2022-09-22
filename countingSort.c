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
    sorted[--count[A[x]]] = A[x];
  }
  
  //transfer sorted array to original array
  for(x = 0; x < size; x++){
    A[x] = sorted[x];
  }
}

void countingSortv2(int A[], int size){
  int *sorted = (int*)calloc(size, sizeof(int));
  int x, max = A[0], min = A[0];

  //find the smallest and largest number in the array
  for(x = 1; x < size; x++){
    max = (max < A[x]) ? A[x] : max;
    min = (min > A[x]) ? A[x] : min;
  }

  min = (min < 0) ? min * -1 : 0;
  //create count array with length max + 1 + min
  int *count = (int*)calloc((max + 1) + min, sizeof(int));

  //count each occurense of number
  for(x = 0; x < size; x++){
    count[A[x] + min]++;
  }

  //store cummulative sum
  for(x = 1; x < max + 1 + min; x++){
    count[x] += count[x - 1];
  }

  //place elments in sorted array
  for(x = 0; x < size; x++){
    sorted[--count[A[x] + min]] = A[x];
    // printf(" occ : %d %d ", --count[A[x] + min], A[x]);
  }

  //transfer sorted array to original array
  for(x = 0; x < size; x++){
    A[x] = sorted[x];
  }

}

int main() {
  int arr[] = {3, 6, 4, 0, 2, 3, -4};
  int size = sizeof(arr)/sizeof(arr[0]);
  countingSortv2(arr, size);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%d ", arr[x]);
  }
  return 0;
}