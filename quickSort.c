#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief sort the first, middle, and last elements
 * 
 * @param start first element
 * @param mid middle element
 * @param end last element
 * @return ** void 
 */
void medianOfThree(int *start, int *mid, int *end){
    int *min = (*mid < *end) ? mid : end;

    if(*start > *min)
        swap(start, min);
    if(*mid > *end)
        swap(mid, end);
}

void insertionSort(int A[], int start, int end){
    int x, y;

    for(x = start + 1; x <= end; x++){
        int temp = A[x];
        for(y = x - 1; y >= 0 && A[y] > temp; y--){
            A[y + 1] = A[y];
        }
        A[y + 1] = temp;
    }
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

int partitionv1(int A[], int start, int end){
    int pivot = A[end]; //pivot is the last element of segment
    int low = start, high = end;

    while(low < high){
        for(; low < high && A[low] < pivot; low++){}
        for(; high > low && A[high] >= pivot; high--){}
        if(low < high)
            swap(&A[low], &A[high]);
    }
    swap(&A[end], &A[low]);

    return low;
}

int partitionv2(int A[], int start, int end){
    //sort the first, middle, and last elements of the segment
    medianOfThree(&A[0], &A[(start + end) / 2], &A[end]);

    swap(&A[(start + end) / 2], &A[end]);
    int pivot = A[end];
    int low = start, high = end;

    while(low < high){
        for(; low < high && A[low] < pivot; low++){}
        for(; high > low && A[high] >= pivot; high--){}
        if(low < high)
            swap(&A[low], &A[high]);
    }
    swap(&A[end], &A[low]);

    return low;
}

void quickSort(int A[], int start, int end){
    if(start >= end)
        return;

    /* arrange elements lesser than the pivot to the left and elements greater than the pivot to the right */
    int pIndex = partitionv2(A, start, end);

    /* perform quick sort on the left segment */
    quickSort(A, start, pIndex - 1);

    /* perform quick sort on the right segment */
    quickSort(A, pIndex + 1, end);
}

void quickSortv1(int A[], int start, int end){
    int cutoff = 3;

    if(start >= end)
        return;

    if(end - start < cutoff){
        insertionSort(A, start, end);
    }else{
        /* arrange elements lesser than the pivot to the left and elements greater than the pivot to the right */
        int pIndex = partitionv2(A, start, end);

        /* perform quick sort on the left segment */
        quickSort(A, start, pIndex - 1);

        /* perform quick sort on the right segment */
        quickSort(A, pIndex + 1, end);
    }
}

int main() {
  int arr[] = {3, 6, 4, 0, 2, 8};
  int size = sizeof(arr)/sizeof(arr[0]);
  quickSortv1(arr, 0, size - 1);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%d ", arr[x]);
  }
  return 0;
}