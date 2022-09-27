#include <stdio.h>
#include <stdlib.h>


//Top down approach
void merge(int A[], int L[], int R[], int Lsize, int Rsize){
  int Andx = 0, Lndx, Rndx;
  
  for(Lndx = 0, Rndx = 0; Lndx < Lsize && Rndx < Rsize;){
    if(L[Lndx] < R[Rndx]){
      A[Andx++] = L[Lndx++];
    } else {
      A[Andx++] = R[Rndx++];
    }
  }
  
  //if right array finishes first
  while(Lndx < Lsize){
    A[Andx++] = L[Lndx++];
  }
  //if left array finishes first
  while(Rndx < Rsize){
    A[Andx++] = R[Rndx++];
  }
}

int mergeSort(int arr[], int size){
  if(size < 2)
    return 0;
    
  int mid = size / 2;
  int ndx = 0, Lndx = 0, Rndx = 0;
  
  //MergeSort Left
  int *L = (int*)calloc(mid, sizeof(int));
  while(ndx < mid){
    L[Lndx++] = arr[ndx++];
  }
  mergeSort(L, mid);
  //MergeSort Right
  int *R = (int*)calloc(size - mid, sizeof(int));
  while(ndx < size){
    R[Rndx++] = arr[ndx++];
  }
  mergeSort(R, size - mid);

  //Merge
  merge(arr, L, R, mid, size - mid);
}

//Bottom up approach
void mergev2(int A[], int L[], int R[], int first, int second, int F_size, int S_size){
  int x, y, z;
  for(x = 0, y = 0, z = first; x < F_size && y < S_size; z++){
    A[z] = (L[x] <= R[y]) ? L[x++] : R[y++]; 
  }
  
  while(x < F_size){
    A[z++] = L[x++];
  }
  
  while(y < S_size){
    A[z++] = R[y++];
  }
}

void mergeSortv2(int A[], int size){
  int x, y;
  
  for(x = 1; x <= size; x *= 2){
    int *L = (int*)calloc(x, sizeof(int));
    int *R = (int*)calloc(x, sizeof(int));
    for(y = 0; y + x < size; y += x*2){
      int first = y;
      int second = y + x;
      int ctr, z, F_size = 0, S_size = 0;
      //create left segment
      for(ctr = first, z = 0; ctr < size && ctr < second; ctr++, z++){
        L[z] = A[ctr];
        F_size++;
      }
      //create right segment
      for(ctr = second, z = 0; ctr < size && ctr < second + x; ctr++, z++){
        R[z] = A[ctr];
        S_size++;
      }
      //merge
      mergev2(A, L, R, first, second, F_size, S_size);
    }
  }
}


int main() {
  int arr[] = {3, 6, 4, 0, 2, -1};
  int size = sizeof(arr)/sizeof(arr[0]);
  mergeSortv2(arr, size);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%d ", arr[x]);
  }
  return 0;
}