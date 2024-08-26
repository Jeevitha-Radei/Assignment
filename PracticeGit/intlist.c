//----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//------------------------------------------------------------------------------------------------
//   intlist.c
//   Program on Linked List functions.
//--------------------------------------------------------------------------------------------
#include <malloc.h>
#include <stdlib.h>
#include "intlist.h"

void* SafeMalloc (size_t size) {
   struct node* ptr = malloc (size);
   if (ptr == NULL) {
      perror ("Memory allocation failed");
      exit (EXIT_FAILURE); // Or return a specific error code if you want to handle it differently
   }
   return ptr;
}

List* CreateList () {
   List* head = (List*)SafeMalloc (sizeof (List));
   if (head == NULL) return NULL;
   head->first = NULL;
   return head;
}

int Append (List* head, int newData) {
   struct node* newNode = (struct node*)SafeMalloc (sizeof (struct node));
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
   struct node* newNode = (struct node*)SafeMalloc (sizeof (struct node));
   newNode->data = newData;
   if (index == 0) {
      newNode->next = head->first;
      head->first = newNode;
      return SUCCESS;
   }
   struct node* current = head->first;
   for (int i = 0; current != NULL && i < index - 1; i++) current = current->next;  // Traverse to the node before the specified index
   if (current == NULL) return ERROR_INDEX_INVALID;
   newNode->next = current->next;
   current->next = newNode;
   return SUCCESS;
}

int RemoveAt (List* head, int index) {
   if (head->first == NULL) return ERROR_EMPTY_LIST;
   struct node* current = head->first;
   if (index == 0) {
      head->first = current->next;
      free (current);
      return SUCCESS;
   }
   for (int i = 0; current != NULL && i < index - 1; i++) current = current->next; // Traverse to the node before the specified index
   if (current == NULL || current->next == NULL) return ERROR_INDEX_INVALID;
   struct node* temp = current->next;
   current->next = temp->next;
   free (temp);
   return SUCCESS;
}

int Remove (List* head, int initialData) {
   if (head == NULL || head->first == NULL) return ERROR_EMPTY_LIST;
   struct node* current = head->first;
   if (current != NULL && current->data == initialData) {     // To check if the head node is going to get removed
      head->first = current->next;
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
   return ERROR_DATA_NOT_FOUND; 
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
   if (index < 0) {
      *error = 1; // Handle invalid index
      return ERROR_INDEX_INVALID; 
   }
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