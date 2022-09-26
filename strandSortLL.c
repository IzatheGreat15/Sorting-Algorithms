#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *link;
} *List;

List convertArraytoLL(int A[], int size){
  int x;
  List head = NULL;
  List *trav = &head;

  for(x = 0; x < size; x++){
    *trav = (List)calloc(1, sizeof(struct node));
    (*trav)->data = A[x];
    trav = &(*trav)->link;
  }

  return head;
}

void displayLL(List head){
  List trav;

  for(trav = head; trav != NULL; trav = trav->link){
    printf("%d ", trav->data);
  }
}

List deleteFirst(List *head){
  List *trav, temp;
  temp = *head;
  trav = head;

  *trav = temp->link;
  temp->link = NULL;

  return temp;
}

void inserttoLL(List *head, List node){
  List *trav = head;
  node->link = *trav;
  *trav = node;
}

List mergeLL(List *one, List *two){
  List output = NULL;
  List *travOne = NULL, *travTwo = NULL, *trav = NULL, temp = NULL;

  for(travOne = one, travTwo = two, trav = &output; *travOne != NULL && *travTwo != NULL; trav = &(*trav)->link){
    if((*travOne)->data < (*travTwo)->data){
      inserttoLL(trav, deleteFirst(travOne));
    } else {
      inserttoLL(trav, deleteFirst(travTwo));
    }
  }

  while(*travOne != NULL){
    inserttoLL(trav, deleteFirst(travOne));
    trav = &(*trav)->link;
  }

  while(*travTwo != NULL){
    inserttoLL(trav, deleteFirst(travTwo));
    trav = &(*trav)->link;
  }

  return output;
}

List strandSort(List *head){
  List *trav = head, temp = NULL;
  List subList = NULL, output = NULL;
  List *travS = &subList;
  
  while(*head != NULL){
    /* insert first element of unsorted list to sublist */
    trav = head;
    inserttoLL(&subList, deleteFirst(trav));
printf("\n%d\n", (*travS)->data);
    /* insert to sublist elements that are greater than the last inserted element to sublist */
    for(; *trav != NULL;){
      printf("%d ", (*trav)->data);
      if((*travS)->data <= (*trav)->data){
        temp = *trav;

        *trav = temp->link;
        inserttoLL(&(*travS)->link, temp);
        travS = &(*travS)->link;
      }else{
        trav = &(*trav)->link;
      }
    }

    /* merge output and sublist */
    output = mergeLL(&subList, &output);
  }

  return output;
}

int main() {
  int arr[] = {10, 8, 2, 9, 1, 4, 9, 12, 1, -1};
  int size = sizeof(arr)/sizeof(arr[0]);

  List head = convertArraytoLL(arr, size);
  
  List sorted = strandSort(&head);
  displayLL(sorted);

  // //display sorted array
  // int x;
  // for(x = 0; x < size; x++){
  //   printf("%d ", arr[x]);
  // }
  return 0;
}