//----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//------------------------------------------------------------------------------------------------
//   intlist.c
//   Program on Linked List functions.
//--------------------------------------------------------------------------------------------
#include <malloc.h>
#include "intlist.h"

List* CreateList () {
   List* head = (struct node*)malloc (sizeof (List));
   if (head == NULL) return NULL;
   head->first = NULL;
   return head;
}

int Append (List* head, int newData) {
   struct node* newNode = (struct node*)malloc (sizeof (struct node));
   if (newNode == NULL) return ERROR_MEM_ALLOC;
   newNode->data = newData;
   newNode->next = NULL;
   struct node* current = head->first;
   if (current == NULL) { 
      head->first = newNode;
      return SUCCESS;
   }
   else { 
      while (current->next != NULL) current = current->next;
      current->next = newNode;
   }
   return SUCCESS; 
}

int Insert (List* head, int index, int newData) {
   struct node* newNode = (struct node*)malloc (sizeof (struct node));
   if (newNode == NULL) return ERROR_MEM_ALLOC;
   struct node* current = head->first;
   for (int i = 0; current != NULL && i < index - 1; i++) current = current->next;  // Traverse to the node before the specified index
   if (current == NULL) return ERROR_INDEX_INVALID;
   newNode->data = newData;
   newNode->next = current->next;
   current->next = newNode;
   return SUCCESS;
}

int RemoveAt (List* head, int index) {
   struct node* current = head->first;
   if (current == NULL) return ERROR_EMPTY_LIST;
   for (int i = 0; current != NULL && i < index - 1; i++) current = current->next; // Traverse to the node before the specified index
   if (current == NULL || current->next == NULL) return ERROR_INDEX_INVALID;
   struct node* temp = current->next;
   current->next = temp->next;
   free (temp);
   return SUCCESS;
}

int Remove (List* head, int initialData) {
   struct node* current = head->first;
   if (current == NULL) return ERROR_EMPTY_LIST;
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

int Count (List* head) {
   int count = 0;
   struct node* current = head->first;
   while (current != NULL) {
      current = current->next;
      count++;
   }
   return count;
}

int Get (List* head, int index, int* error) {
   struct node* current = head->first;
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

void Delete (List* head) {
   struct node* current = head->first;
   struct node* next;
   while (current != NULL) {
      next = current->next;
      free (current);
      current = next;
   }
   head->first = NULL;
}