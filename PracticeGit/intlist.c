//----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//------------------------------------------------------------------------------------------------
//   intlist.c
//   Program on Linked List functions.
//--------------------------------------------------------------------------------------------
#include <malloc.h>
#include "intlist.h"

// Initialize the head pointer of the linked list to NULL.
struct node* head = NULL;

// Function to create a empty linked list
struct node* CreateList (int initialData) {
   struct node* head = (struct node*)malloc (sizeof (struct node));
   if (head == NULL)
      return ERROR_MEM_ALLOC;
   head->data = initialData;
   head->next = NULL;
   return head;
}

//	Function to add an element to the end of the list
void Append (struct node* head, int newData) {
   struct node* current = head;
   while (current->next != NULL)
      current = current->next;
   struct node* newNode = (struct node*)malloc (sizeof (struct node));
   if (newNode == NULL)
      return ERROR_MEM_ALLOC;
   newNode->data = newData;
   newNode->next = NULL;
   if (head == NULL)
      // If list is empty, make newNode the head
      return newNode;
   current->next = newNode;
   return head;
}

//  Function to insert an element at the specified index (zero based)
void Insert (struct node* head, int index, int newData) {
   struct node* newNode = (struct node*)malloc (sizeof (struct node));
   if (newNode == NULL) {
      return ERROR_MEM_ALLOC;
   }
   struct node* current = head;
   int i = 0;
   // Traverse to the node before the specified index
   while (current != NULL && i < index - 1) {
      current = current->next;
      i++;
   }
   if (current == NULL)
      return ERROR_INDEX_INVALID;
   newNode->data = newData;
   newNode->next = current->next;
   current->next = newNode;
}

//Function to Remove an element at specified index (zero based)
void RemoveAt (struct node* head, int index) {
   if (head == NULL)
      return ERROR_EMPTY_LIST;
   struct node* current = head;
   struct node* temp = NULL;
   if (index == 0) {
      temp = head;
      head = head->next; // Update head to the next node
      free (temp);
      return;
   }
   // Traverse to the node before the specified index
   for (int i = 0; current != NULL && i < index - 1; i++)
      current = current->next;
   if (current == NULL || current->next == NULL)
      return ERROR_INDEX_INVALID;
   temp = current->next;
   current->next = temp->next;
   free (temp);
}

// Function to remove the first occurrence of a specific element
void Remove (struct node* head, int initialData) {
   if (head == NULL)
      return ERROR_EMPTY_LIST;
   struct node* current = head;
   // To check the head node is going to get removed
   if (current != NULL && current->data == initialData) {
      head = current->next;
      free (current);
      return;
   }
   // Traverse through the list to find the node to remove
   while (current != NULL && current->next != NULL) {
      if (current->next->data == initialData) {
         struct node* temp = current->next;
         current->next = temp->next;
         free (temp);
         return;
      }
      current = current->next;
   }
}

// Function to count the number of elements in the list
int Count (struct node* head) {
   int count = 0;
   struct node* current = head;
   while (current != NULL) {
      count++;
      current = current->next;
   }
   return count;
}

// Function to Get the element at a Particular index
int Get (struct node* head, int index) {
   struct node* current = head;
   int i = 0;

   while (current != NULL && i < index) {
      current = current->next;
      i++;
   }
   if (current == NULL)
      return ERROR_OUT_BOUNDS;
   else
      return current->data;
}

// Function to delete the entire list 
void Delete (struct node* head) {
   struct node* current = head;
   struct node* next;
   while (current != NULL) {
      next = current->next;
      free (current);
      current = next;
   }
}