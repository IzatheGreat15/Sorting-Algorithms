#include <stdio.h>
#include <stdlib.h>

void swap(int *one, int *two){
    int temp = *one;
    *one = *two;
    *two = temp;
}

void gnomeSort(int A[], int size){
  int ctr;
  for(ctr = 1; ctr < size;){
    if(ctr == 0){
        ctr++;
    }
    //if node before the ctr is larger; swap and move to previous node
    if(A[ctr - 1] > A[ctr]){
        swap(&A[ctr - 1], &A[ctr]);
        ctr--;
    }
    //if node before the ctr is smaller or equal; move to next node
    if(A[ctr - 1] <= A[ctr]){
        ctr++;
    }
  }
}

int main() {
  int arr[] = {3, 6, 4, 0, 2};
  int size = sizeof(arr)/sizeof(arr[0]);
  gnomeSort(arr, size);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%d ", arr[x]);
  }
  return 0;
}