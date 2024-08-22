//------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//-------------------------------------------------------------------------------------------------
//   testintlist.c
//   Program on testing the Linked list functions.
//--------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "intlist.h"

//Pointer to the head of the linked list
struct node* head;

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
   Append (head, -2);
   Append (head, 23);
   Insert (head, 2, 14);
   RemoveAt (head, 3);
   Remove (head, 23);

   printf ("Elements in the List:\n ");
   printList (head);
   printf ("\n");
   printf ("Number of elements in the list: %d\n", Count (head));  // Count the number of elements in the list
   printf ("\n");

   // Get the element at the specified index
   int index = 9;
   int error = 0;
   int value = Get (head, index, &error);
   if (error) printf ("Invalid Index\n");
   else printf ("Value at index %d: %d\n", index, value);
   printf ("\n");
   
   // Delete the entire list
   Delete (head);
   head = NULL;
   if (head == NULL) {
      printf ("The entire list is deleted: ");
      printList (head);  // Prints "NULL" since list is empty
   }
   else printf ("List is not deleted");

   return 0;
}