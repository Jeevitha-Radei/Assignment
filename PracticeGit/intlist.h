// //------------------------------------------------------------------------------------------------
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
//   intlist.h
//   Program on main branch
//--------------------------------------------------------------------------------------------
#ifndef INTLIST_H
#define INTLIST_H

#define Failure 1;

// Define a structure of node
struct node {
	int data;
	struct node* next;
};

struct node* CreateList(int initialData);
void AddAtEnd(struct node* head, int newData);
void Insert(struct node* head, int index, int newData);
void RemoveAt(struct node** headRef, int index);
void Remove(struct node** headRef, int initialData);
int Count(struct node* head);
int Get(struct node* head, int index);
void Delete(struct node** headRef);
void printList(struct node* head);

#endif INTLIST_H