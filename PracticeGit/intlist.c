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
//   intlist.c
//   Program on main branch
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "intlist.h"

const char* memoryAllocationError = "Memory allocation failed.\n";
struct node* head = NULL;

// Function to create a empty linked list
struct node* CreateList(int initialData) {
   struct node* head = (struct node*)malloc(sizeof(struct node));
   if (head == NULL) {
      printf("%s", memoryAllocationError);
      exit(1);
   }
   head->data = initialData;
   head->next = NULL;
   return head;
}

//	Function to add an element to the end of the list
void AddAtEnd(struct node* head, int newData) {
   struct node* current = head;

   // Traverse to the end of the list
   while (current->next != NULL) {
      current = current->next;
   }

   struct node* newNode = (struct node*)malloc(sizeof(struct node));
   if (newNode == NULL) {
      printf("%s", memoryAllocationError);
      exit(1);
   }
   newNode->data = newData;
   newNode->next = NULL;

   current->next = newNode;
}

//  Function to insert an element at the specified index (zero based)
void Insert(struct node* head, int index, int newData) {
   struct node* current = head;
   int i = 0;

   // Traverse to the node before the specified index
   while (current != NULL && i < index - 1) {
      current = current->next;
      i++;
   }
   if (current == NULL) {
      printf("Invalid index.\n");
      return;
   }
   struct node* newNode = (struct node*)malloc(sizeof(struct node));
   if (newNode == NULL) {
      printf("%s", memoryAllocationError);
      exit(1);
   }
   newNode->data = newData;
   newNode->next = current->next;
   current->next = newNode;
}

//Function to Remove an element at specified index (zero based)
void RemoveAt(struct node** headRef, int index) {
   if (*headRef == NULL) {
      printf(" List is empty.\n");
      return;
   }
   struct node* current = *headRef;
   struct node* temp = NULL;

   if (index == 0) {
      *headRef = current->next;
      free(current);
      return;
   }
   // Traverse to the node before the specified index
   for (int i = 0; current != NULL && i < index - 1; i++) {
      current = current->next;
   }

   if (current == NULL || current->next == NULL) {
      printf("Invalid index.\n");
      return;
   }

   temp = current->next;
   current->next = temp->next;
   free(temp);
}

// Function to remove the first occurrence of a specific element
void Remove(struct node** headRef, int initialData) {
   struct node* current = *headRef;

   // To check the head node is going to get removed
   if (current != NULL && current->data == initialData) {
      *headRef = current->next;
      free(current);
      return;
   }
   // Traverse through the list to find the node to remove
   while (current != NULL && current->next != NULL) {
      if (current->next->data == initialData) {
         struct node* temp = current->next;
         current->next = temp->next;
         free(temp);
         return;
      }
      current = current->next;
   }

   // If the node was not found
   printf("Element with initialData %d not found in the list.\n", initialData);
}


// Function to count the number of elements in the list
int Count(struct node* head) {
   int count = 0;
   struct node* current = head;
   while (current != NULL) {
      count++;
      current = current->next;
   }
   return count;
}

// Function to Get the element at a Particular index
int Get(struct node* head, int index) {
   struct node* current = head;
   int i = 0;

   while (current != NULL && i < index) {
      current = current->next;
      i++;
   }

   if (current == NULL) {
      printf("Index out of bounds.\n");
      return -1; // Return an error
   }
   else {
      return current->data;
   }
}

// Function to delete the entire list 
void Delete(struct node** headRef) {
   struct node* current = *headRef;
   struct node* next;

   while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
   }
   *headRef = NULL;
}

//  Function to print the list that is modified
void printList(struct node* head) {
   struct node* current = head;
   while (current != NULL) {
      printf("%d -> ", current->data);
      current = current->next;
   }
   printf("NULL\n");
}