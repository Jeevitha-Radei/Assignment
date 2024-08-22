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

struct node* CreateList (int initialData) {
   struct node* head = (struct node*)malloc (sizeof (struct node));
   if (head == NULL) return ERROR_MEM_ALLOC;
   head->data = initialData;
   head->next = NULL;
   return head;
}

int Append (struct node* head, int newData) {
   struct node* current = head;
   while (current->next != NULL) current = current->next;
   struct node* newNode = (struct node*)malloc (sizeof (struct node));
   if (newNode == NULL) return ERROR_MEM_ALLOC;
   newNode->data = newData;
   newNode->next = NULL;
   if (head == NULL) return newNode;  // If list is empty, make newNode the head
   current->next = newNode;
   return SUCCESS; 
}

int Insert (struct node* head, int index, int newData) {
   struct node* newNode = (struct node*)malloc (sizeof (struct node));
   if (newNode == NULL) return ERROR_MEM_ALLOC;
   struct node* current = head;
   for (int i = 0; current != NULL && i < index - 1; i++) current = current->next;  // Traverse to the node before the specified index
   if (current == NULL) return ERROR_INDEX_INVALID;
   newNode->data = newData;
   newNode->next = current->next;
   current->next = newNode;
   return SUCCESS;
}

int RemoveAt (struct node* head, int index) {
   if (head == NULL) return ERROR_EMPTY_LIST;
   struct node* current = head;
   for (int i = 0; current != NULL && i < index - 1; i++) current = current->next; // Traverse to the node before the specified index
   if (current == NULL || current->next == NULL) return ERROR_INDEX_INVALID;
   struct node* temp = current->next;
   current->next = temp->next;
   free (temp);
   return SUCCESS;
}

int Remove (struct node* head, int initialData) {
   if (head == NULL) return ERROR_EMPTY_LIST;
   struct node* current = head;
   if (current != NULL && current->data == initialData) {     // To check the head node is going to get removed
      head = current->next;
      free (current);
      return SUCCESS; 
   }
   while (current != NULL && current->next != NULL) {         // Traverse through the list to find the node to remove
      if (current->next->data == initialData) {
         struct node* temp = current->next;
         current->next = temp->next;
         free (temp);
         return SUCCESS; 
      }
      current = current->next;
   }
}

int Count (struct node* head) {
   int count = 0;
   struct node* current = head;
   while (current != NULL) {
      current = current->next;
      count++;
   }
   return count;
}

int Get (struct node* head, int index, int* error) {
   struct node* current = head;
   for (int i = 0; current != NULL && i < index; i++) current = current->next;
   if (current == NULL) {
      *error = 1; // Set error 
      return ERROR_INDEX_INVALID;
   }
   else {
      *error = 0; // No error
      return current->data;
   }
}

void Delete (struct node* head) {
   struct node* current = head;
   struct node* next;
   while (current != NULL) {
      next = current->next;
      free (current);
      current = next;
   }
}