#include <stdio.h>
#include <stdlib.h>

void shellSort(int A[], int size){
  int interval, x, y, temp = 0;
  
  for(interval = size / 2; interval > 0; interval /= 2){
    for(x = interval; x < size; x++){
      temp = A[x];
      //comparing of nodes based on interval
      for(y = x; y >= interval && A[y - interval] > temp; y-= interval){
        A[y] = A[y - interval];
      }
      A[y] = temp;
    }
  }
}

int main() {
  int arr[] = {3, 6, 4, 0, 2};
  int size = sizeof(arr)/sizeof(arr[0]);
  shellSort(arr, size);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%d ", arr[x]);
  }
  return 0;
}