/**
 * create another array twice the size of original array
 * store original array to second half of other array
 * store index of winner to higher level of tree
 * replace first index in original array with the winner
 * define the winner index of the other array as INFINITY
 * then repeat
 * **/

#include <stdio.h>
#include <stdlib.h>

void tournamentSort(int A[], int size){
    /* create tournament array, twice the size of input array */
    int *tournament = (int*)calloc(size * 2, sizeof(int));

    int x, y;
    /* transfer all elements to the second half of the tournament array */
    for(x = size - 1, y = x * 2 + 1; x >= 0; x--, y--){
        tournament[y] = A[x];
    }

    int ctr = 0; // counts how many elements is sorted in the input array
    while(ctr < size){
        /* perform 1v1 battle */
        for(x = size * 2 - 1; x > 0; x -= 2){
            int parent = (x - 1) / 2;
            /**
             * store the index of the winner to their parent
             */
            /* no sibling */
            if(x + 1 == size * 2){
                tournament[parent] = x;
            }else{
                if(x >= size){
                    tournament[parent] = (tournament[x] < tournament[x + 1])? x : x + 1;
                }else{
                    if(x + 1 >= size){
                        tournament[parent] = (tournament[tournament[x]] < tournament[x + 1])? tournament[x] : x + 1;
                    }else{
                        tournament[parent] = (tournament[tournament[x]] < tournament[tournament[x + 1]])? tournament[x] : tournament[x + 1];
                    }
                }
            }
        }
        /* store the winner to the input array */
        A[ctr++] = tournament[tournament[0]];
        /* define winner index as INFINITY */
        tournament[tournament[0]] = INT_MAX;
    }
}

int main() {
  int arr[] = {10, 8, 2, 9, 1, 4, 12, 9, -1, -17};
  int size = sizeof(arr)/sizeof(arr[0]);
  tournamentSort(arr, size);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%d ", arr[x]);
  }
  return 0;
}