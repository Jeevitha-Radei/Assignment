//------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//   testintlist.c
//   Program on testing the Linked list functions.
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "intlist.h"

struct node* head;

int main() {
   head = CreateList(0);
   AddAtEnd(head, 12);
   AddAtEnd(head, 12);
   AddAtEnd(head, 12);
   AddAtEnd(head, 23);
   Insert(head, 1, 7);
   RemoveAt(&head, 3);
   Remove(&head, 12);

   printf("Elements in the List:\n ");
   printList(head);
   // Count the number of elements in the list
   printf("Number of elements in the list: %d\n", Count(head));

   // Get the element at the specified index
   int index = 3;
   printf("Element at index %d: %d\n", index, Get(head, index));
   // Delete the entire list
   Delete(&head);
   printf("After deleting the entire list: ");
   printList(head);  // Prints "NULL" since list is empty

   return 0;
}







