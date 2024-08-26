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
#define SUCCESS 0 // Return success after completion
#define ERROR_MEMORY_ALLOCATION -1 // Return an if meory allocation failed
#define ERROR_INDEX_INVALID -2   //Return an error if invalid index found
#define ERROR_EMPTY_LIST -3	// Return an error if the list is empty
#define ERROR_DATA_NOT_FOUND -4 // Return an error if data not found in the list

// Define a structure of node
struct node {
   int data;
   struct node* next;
};

// Structure which points to head
typedef struct HeadList {
   struct node* first;
}List; 

/// <summary>Function to handle Memory allocation failure.</summary>
void* SafeMalloc (size_t size);

/// <summary>Function to create a empty linked list.</summary>
List* CreateList ();

/// <summary>Function to add an element to the end of the list.</summary>
int Append (List* head, int newData);

/// <summary>Function to insert an element at the specified index (zero based).</summary>
int Insert (List* head, int index, int newData);

/// <summary>Function to Remove an element at specified index (zero based).</summary>
int RemoveAt (List* head, int index);

/// <summary>Function to remove the first occurrence of a specific element.</summary>
int Remove (List* head, int initialData);

/// <summary>Function to count the number of elements in the list.</summary>
int Count (List* head);

/// <summary>Function to Get the element at a Particular index.</summary>
int Get (List* head, int index, int* error);

/// <summary>Function to delete the entire list.</summary>
void Delete (List* head);

/// <summary>Function to print the list that is modified.</summary>
void printList (List* head);

/// <summary>Function to handle and print errors.</summary>
void handleError (int errorCode);

#endif INTLIST_H