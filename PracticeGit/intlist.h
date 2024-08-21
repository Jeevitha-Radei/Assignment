//------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//---------------------------------------------------------------------------------------------------
//   intlist.h
//   Program on Linked list header file
//--------------------------------------------------------------------------------------------
/// <summary>
/// Implementing a linked list data structure to handle integer elements. The implementation will consist of three files:
///                         intlist.h                -      the header file
///                         intlist.c                -      the code.
///                         testintlist.c            -      the program that tests the implementation.
/// 
/// The following functions have been implemented:
/// 
///    a) Create – this will create a new linked list.
///    b) Delete – this will delete the list and all the linked elements.
///	 c) AddAtEnd – this will add an element to the end of the list.
///    d) Insert – this will insert an element at a particular index(zero based).
///    e) RemoveAt – this will remove the element at a particular index(zero based).
///    f) Remove – removes the first occurrence of a specific element.
///    g) Count – number of elements in the list.
///    h) Get – gets the element at a particular index.
///  </summary>
// ---------------------------------------------------------------------------------------------

#ifndef INTLIST_H
#define INTLIST_H
// Define error codes
#define ERROR_MEM_ALLOC "Memory allocation failed"	  // Return an error if memory allocation failed
#define ERROR_INDEX_INVALID "Invalid index found"   //Return an error if invalid index found
#define ERROR_EMPTY_LIST "List is empty"	// Return an error if the list is empty

// Define a structure of node
struct node {
   int data;
   struct node* next;
};
/// <summary>Function to create a empty linked list.</summary>
struct node* CreateList (int initialData);

/// <summary>Function to add an element to the end of the list.</summary>
void Append (struct node* head, int newData);

/// <summary>Function to insert an element at the specified index (zero based).</summary>
void Insert (struct node* head, int index, int newData);

/// <summary>Function to Remove an element at specified index (zero based).</summary>
void RemoveAt (struct node* head, int index);

/// <summary>Function to remove the first occurrence of a specific element.</summary>
void Remove (struct node* head, int initialData);

/// <summary>Function to count the number of elements in the list.</summary>
int Count (struct node* head);

/// <summary>Function to Get the element at a Particular index.</summary>
int Get (struct node* head, int index);

/// <summary>Function to delete the entire list.</summary>
void Delete (struct node* head);

/// <summary>Function to print the list that is modified.</summary>
void printList (struct node* head);

#endif INTLIST_H