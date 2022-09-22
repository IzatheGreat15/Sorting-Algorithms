#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    float num;
    struct node *link;
}*nodePtr;

void insertSortedLL(nodePtr *head, float num){
    nodePtr *trav;
    nodePtr temp;

    for(trav = head; *trav != NULL && (*trav)->num < num; trav = &(*trav)->link){}
    temp = (nodePtr)calloc(1, sizeof(struct node));
    temp->num = num;
    temp->link = *trav;
    *trav = temp;
}

void bucketSort(float A[], int size, int no_of_buckets){
  float max, min, range;
  int x;
  max = min = A[0];

  //find max and min elements
  for(x = 0; x < size; x++){
    max = (max < A[x]) ? A[x] : max;
    min = (min > A[x]) ? A[x] : min;
  }

  range = (max - min) / no_of_buckets;

  //create n buckets
  nodePtr *buckets = (nodePtr*)calloc(no_of_buckets, sizeof(struct node));

  //scatter the array element to individual buckets
  for(x = 0; x < size; x++){
    int bucketIndex = (A[x] - min) / range;
    insertSortedLL(&buckets[bucketIndex], A[x]);
  }

  //gather the sorted elements to original array
  int ctr = 0;
  for(x = 0; x < sizeof(buckets); x++){
    nodePtr ptr;
    for(ptr = buckets[x]; ptr != NULL; ptr = ptr->link){
        A[ctr++] = ptr->num;
    }
  }

}

int main() {
  float arr[] = { 9.0 , 10.6 , 10.1 , 1.9 , 3.07 , 3.04 , 5.0 , 8.0 , 4.8 , 99};
  int size = sizeof(arr)/sizeof(arr[0]);
  bucketSort(arr, size, 10);

  //display sorted array
  int x;
  for(x = 0; x < size; x++){
    printf("%.2f ", arr[x]);
  }
  return 0;
}