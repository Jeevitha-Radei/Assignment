//------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//-------------------------------------------------------------------------------------------------
//   testintlist.c
//   Program on testing the Linked list functions.
//--------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "intlist.h"

struct node* head;

//  Function to print the list that is modified
void printList (struct node* head) {
   struct node* current = head;
   while (current != NULL) {
      printf ("%d -> ", current->data);
      current = current->next;
   }
   printf ("NULL\n");
}

int main () {
   head = CreateList (0);
   Append (head, 1);
   Append (head, 12);
   Append (head, 12);
   Append (head, 16);
   Append (head, 23);
   Insert (head, 2, 14);
   RemoveAt (head, 3);
   Remove (head, 23);

   printf ("Elements in the List:\n ");
   printList (head);
   // Count the number of elements in the list
   printf ("Number of elements in the list: %d\n", Count (head));

   // Get the element at the specified index
   int index = 2;
   int value = Get (head, index);
   if (value != -2)
      printf ("Value at index %d: %d\n", index, value);
   printf ("Value at index %d: %d\n", index, value);
   else
      printf ("Index %d out of bounds\n", index);

   // Delete the entire list
   Delete (head);
   head = NULL;
   if (head == NULL) {
      printf ("The entire list is deleted: ");
      printList (head);  // Prints "NULL" since list is empty
   }
   else
      printf ("List is not deleted");

   return 0;
}