//------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//-------------------------------------------------------------------------------------------------
//   testintlist.c
//   Program on testing the Linked list functions.
//--------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "intlist.h"

void printList (List* head) {
   struct node* current = head->first;
   while (current != NULL) {
      printf ("%d -> ", current->data);
      current = current->next;
   }
   printf ("NULL\n");
}

int main () {
   List* head = CreateList ();
   // Add elements
   Append (head, 1);
   Append (head, 12);
   Append (head, 12);
   Append (head, -2);
   Append (head, 23);
   printf ("Elements in the List:\n ");
   printList (head);
   printf ("\n");
   // Insert an element at particular index
   Insert (head, 2, 14);
   printf ("List after inserting an element:\n ");
   printList (head);
   printf ("\n");
   // Remove an element at particular index
   RemoveAt (head, 3);
   printf ("List after removing an element at particular index:\n ");
   printList (head);
   printf ("\n");
   // Remove the first occurrence of a specific element
   Remove (head, 23);
   printf ("List after removing the first occurrence of a specific element:\n ");
   printList (head);
   printf ("\n");
   // Count the number of elements in the list
   printf ("Number of elements in the list: %d\n", Count (head)); 
   printf ("\n");
   // Get the element at the specified index
   int index = 3;
   int error = 0;
   int value = Get (head, index, &error);
   if (error) printf ("Invalid Index\n");
   else printf ("Value at index %d: %d\n", index, value);
   printf ("\n");
   // Delete the entire list
   Delete (head);
   if ((head->first) == NULL) {
      printf ("The entire list is deleted: ");
      printList (head);  // Prints "NULL" since list is empty
   }
   else printf ("List is not deleted");
     
   return 0;
}