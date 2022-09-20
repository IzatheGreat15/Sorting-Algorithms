#include <stdio.h>
#include <stdlib.h>

void swap(int *one, int *two){
    int temp = *one;
    *one = *two;
    *two = temp;
}

void gnomeSort(int A[], int size){
  int ctr;
  for(ctr = 0; ctr < size;){
    if(ctr == -1){
        ctr++;
    }
    //if node greater than the node after it; swap and go back to previous node
    if(A[ctr] > A[ctr + 1]){
        swap(&A[ctr], &A[ctr + 1]);
        ctr--;
    }
    //if node is less than or equal to the node after it; proceed to next node
    if(A[ctr] <= A[ctr + 1]){
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