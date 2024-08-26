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

void handleError (int errorCode) {
   switch (errorCode) {
   case SUCCESS:
      printf ("Operation Succesfull.\n");
      break;
   case ERROR_MEMORY_ALLOCATION:
      printf ("Error: Memory Allocation failed.\n");
      break;
   case ERROR_INDEX_INVALID:
      printf ("Error: Invalid Index\n");
      break;
   case ERROR_EMPTY_LIST:
      printf ("Error: The list is empty\n");
      break;
   case ERROR_DATA_NOT_FOUND:
      printf ("Error: Data not found\n");
      break;
   default:
      printf ("Unknown Error\n");
      break;
   }
}

int main () {
   List* head = CreateList ();
   if (head == NULL) {
      printf ("Error: Could not create list\n");
      return 1;
   }
   else handleError (SUCCESS);
   // Add elements
   int result = Append (head, 1);
   if (result != SUCCESS) {
      handleError (result);
      return 1;
   }
   result = Append (head, 12);
   if (result != SUCCESS) {
      handleError (result);
      return 1;
   }
   result = Append (head, 12);
   if (result != SUCCESS) {
      handleError (result);
      return 1;
   }
   result = Append (head, -2);
   if (result != SUCCESS) {
      handleError (result);
      return 1;
   }
   result = Append (head, 23);
   if (result != SUCCESS) {
      handleError (result);
      return 1;
   }
   printf ("Elements in the List:\n ");
   printList (head);
   // Insert an element at particular index
   result = Insert (head, 2, 14);
   if (result != SUCCESS) {
      handleError (result);
      return 1;
   }
   printf ("List after inserting an element:\n ");
   printList (head);
   // Remove an element at particular index
   result = RemoveAt (head, 3);
   if (result != SUCCESS) {
      handleError (result);
      return 1;
   }
   printf ("List after removing an element at particular index:\n ");
   printList (head);
   // Remove the first occurrence of a specific element
   result = Remove (head, 12);
   if (result != SUCCESS) {
      handleError (result);
      return 1;
   }
   printf ("List after removing the first occurrence of a specific element:\n ");
   printList (head);
   // Count the number of elements in the list
   int count = Count (head);
   if (count < 0) handleError (count);
   else printf ("Number of elements in the list: %d\n", count);
   // Get the element at the specified index
   int index = 3;
   int error = 0;
   int value = Get (head, index, &error);
   if (error) handleError (ERROR_INDEX_INVALID);
   else printf ("Value at index %d: %d\n", index, value);
   // Delete the entire list
   Delete (head);
   if (head->first == NULL) {
      printf ("The entire list is deleted: ");
      printList (head);  // Prints "NULL" since list is empty
   }
   else printf ("List is not deleted\n");

   return 0;
}
