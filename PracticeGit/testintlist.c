//------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//------------------------------------------------------------------
// Implementing a linked list data structure to handle integer elements. The implementation will consist of three files:
//                         intlist.h                -      the header file
//                         intlist.c                -      the code.
//                         testintlist.c            -      the program that tests the implementation.
// 
// The following functions have been implemented:
// 
//   a) Create – this will create a new linked list.
//	  b) Delete – this will delete the list and all the linked elements.
//	  c) Add – this will add an element to the end of the list.
//	  d) Insert – this will insert an element at a particular index(zero based).
//   e) RemoveAt – this will remove the element at a particular index(zero based).
//	  f) Remove – removes the first occurrence of a specific element.
//   g) Count – number of elements in the list.
//	  h) Get – gets the element at a particular index.
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//   testintlist.c
//   Program on main branch
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

   printf("Number of elements in the list: %d\n", Count(head));

   int index = 3;
   printf("Element at index %d: %d\n", index, Get(head, index));

   Delete(&head);
   printf("After deleting the entire list: ");
   printList(head);  // Prints "NULL" since list is empty

   return 0;
}







