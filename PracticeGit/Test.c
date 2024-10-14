// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// test.c -  Program that Executes test cases and checks the user input for sort & search.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 10
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

/// <summary> Prints the elements of an array. </summary>
void PrintArray (int array[], int size);

/// <summary> Runs test cases for the QuickSort function. </summary>
void RunQuickSortTest ();

/// <summary> Gets user input for an array, sorts it, and performs a binary search. </summary>
void GetUserInput ();

typedef struct {
   int array[MAXSIZE];
   int size;
} TestCase;

void PrintArray (int array[], int size) {
   for (int i = 0; i < size; i++) printf ("%5d", array[i]);
}

void RunQuickSortTest () {
   TestCase testCases[] = {
       {{20, 49, 11, 3, 89, 75, 11, 12, 55, 1}, 10},
       {{2, 2, 2, 2, 2, 2, 2}, 7},
       {{9}, 1},
       {{3, -1, -7, 5, 2, 0, -7}, 7},
       {{1, 2, 3, 4, 5, 6}, 6},
       {{0, -1, -2, -3, -4, -5}, 6},
       {{36, 69}, 2},
       {{22, 35, 32, 39, 46, 54, 55}, 7},
       {{12, 13, 14, 15, 16, 11}, 6}
   };
   int expectedResults[][MAXSIZE] = {
       {1, 3, 11, 11, 12, 20, 49, 55, 75, 89},
       {2, 2, 2, 2, 2, 2, 2},
       {9},
       {-7, -7, -1, 0, 2, 3, 5},
       {1, 2, 3, 4, 5, 6},
       {-5, -4, -3, -2, -1, 0},
       {36, 69},
       {22, 32, 35, 39, 46, 54, 55},
       {11, 12, 13, 14, 15, 16}
   };
   for (int i = 0; i < 9; i++) {
      int n = testCases[i].size;
      int currentTest[MAXSIZE] = { 0 };
      memcpy (currentTest, testCases[i].array, n * sizeof (int));
      printf ("\nTestcase %d\nUnsorted array: ", i + 1);
      PrintArray (testCases[i].array, n);
      QuickSort (currentTest, 0, n - 1);
      printf ("\nSorted array:   ");
      PrintArray (currentTest, n);
      const char* result = (memcmp (currentTest, expectedResults[i], n * sizeof (int)) == 0) ? GREEN"Pass"RESET : RED"Fail"RESET;
      printf ("\nResult: %s\n", result);
   }
}

void GetUserInput () {
   int array[MAXSIZE];
   int size;
   char input[256];
   printf ("Enter the number of elements: ");
   fgets (input, sizeof (input), stdin);
   size = atoi (input);
   if (size < 1 || size > MAXSIZE) {
      printf ("Invalid number of elements. Please enter a value between 1 and %d.\n", MAXSIZE);
      return;
   }
   printf ("Enter %d integers:\n", size);
   for (int i = 0; i < size; i++) {
      fgets (input, sizeof (input), stdin);
      array[i] = atoi (input);
   }
   printf ("Unsorted Array: ");
   PrintArray (array, size);
   QuickSort (array, 0, size - 1);
   printf ("\nSorted Array:   ");
   PrintArray (array, size);
   int target;
   printf ("\nEnter the element to search for: ");
   fgets (input, sizeof (input), stdin);
   target = atoi (input);
   int result = BinarySearch (array, size, target);
   printf ("Element %d %s at index %d.\n", target, (result != -1) ? "found" : "not found", (result != -1) ? result : -1);
}

int main () {
   char choiceStr[3];
   while (1) {
      printf ("\nSelect option:\n1. Executing test cases\n2. Enter an array of integers to sort and search\n3. Exit\nEnter your choice (1, 2, or 3): ");
      fgets (choiceStr, sizeof (choiceStr), stdin);
      char* endPtr;
      long choice = strtol (choiceStr, &endPtr, 10);
      if (endPtr == choiceStr || *endPtr != '\n' || choice < 1 || choice > 3) {
         printf ("Invalid choice. Please enter 1, 2, or 3.\n");
         while (getchar () != '\n');  // Clear the input buffer
         continue;
      }
      switch (choice) {
      case 1:
         RunQuickSortTest ();
         break;
      case 2:
         GetUserInput ();
         break;
      case 3:
         printf ("Exiting the program.\n");
         return 0;
      }
   }
   return 0;
}