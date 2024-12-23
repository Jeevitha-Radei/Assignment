// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// test.c -  Program that Executes test cases and checks the user input for sort & search.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 10
#define ELEMENT_NOT_FOUND -1
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

/// <summary>Prints the elements of an array.</summary>
void PrintArray (int array[], int size);

/// <summary>Runs test cases for the QuickSort function.</summary>
void RunQuickSortTest ();

/// <summary>Gets user input for an array, sorts it,& performs a binary search.</summary>
void GetUserInput ();

/// <summary>Compare Arrays returns true or false. </summary>
bool AreArraysEqual (int arr1[], int arr2[], int size1, int size2);

void PrintArray (int array[], int size) {
   for (int i = 0; i < size; i++) printf ("%3d", array[i]);
}

bool AreArraysEqual (int arr1[], int arr2[], int size1, int size2) {
   if (size1 != size2) return false;
   for (int i = 0; i < size1; i++)
      if (arr1[i] != arr2[i]) return false;
   return true;    // Arrays are equal if all elements match
}

void SortEntireArray (int array[], int size) {
   QuickSort (array, 0, size - 1);     // Default start index is 0
}

void RunQuickSortTest () {
   int testCases[][MAXSIZE] = {
       {20, 49, 11, 3, 89, 75, 11, 12, 1},
       {2, 2, 2, 2, 2, 2, 2},
       {9},
       {3, -1, -7, 5, 2, 0, -7},
       {1, 2, 3, 4, 5, 6},
       {0, -1, -2, -3, -4, -5},
       {36, 69},
       {22, 35, 32, 39, 46, 54, 55},
       {12, 13, 14, 15, 16, 11},
   };
   int expectedResults[][MAXSIZE] = {
       {1, 3, 11, 11, 12, 20, 49, 75, 89},
       {2, 2, 2, 2, 2, 2, 2},
       {9},
       {-7, -7, -1, 0, 2, 3, 5},
       {1, 2, 3, 4, 5, 6},
       {-5, -4, -3, -2, -1, 0},
       {36, 69},
       {22, 32, 35, 39, 46, 54, 55},
       {11, 12, 13, 14, 15, 16}
   };
   int sizes[] = { 9, 7, 1, 7, 6, 6, 2, 7, 6 };
   int elementSearch[] = { 11, 1, 0, -1, 2, 6, 36, 53, 11 };
   int expectedIndex[] = { 2, ELEMENT_NOT_FOUND, ELEMENT_NOT_FOUND, 2, 1,ELEMENT_NOT_FOUND, 0, ELEMENT_NOT_FOUND, 0 };
   int testCount = sizeof (testCases) / sizeof (testCases[0]);
   printf ("+--------------------------------------------------+---------------+------------------+--------+\n"
      "|                Arrays                            | Key to Search | Index of element | Result |\n"
      "+--------------------------------------------------+---------------+------------------+--------+\n");
   for (int i = 0; i < testCount; i++) {
      int size = sizes[i], * arrayToSort = testCases[i];
      printf ("| Unsorted Array   | ");
      PrintArray (arrayToSort, size);
      printf ("%*s|", (MAXSIZE - size) * 3, " ");
      int searchValue = elementSearch[i];
      SortEntireArray (arrayToSort, size);
      int foundIndex = GetIndex (arrayToSort, size, elementSearch[i]);
      bool searchTestPass = (foundIndex == expectedIndex[i]);
      bool sortTestPass = AreArraysEqual (arrayToSort, expectedResults[i], size, size);
      printf (" %-14d| %-2d | %-8s  | %-8s  |\n", elementSearch[i], foundIndex, foundIndex== - 1 ?
         "Not Found " : " Found    ", (searchTestPass && sortTestPass) ? GREEN "Pass " RESET : RED "Fail " RESET);
      printf ("| Sorted Array     | ");
      PrintArray (arrayToSort, size);
      printf ("\n");
      printf ("+--------------------------------------------------+---------------+------------------+--------+\n");
   }
}

void GetUserInput () {
   int array[MAXSIZE], size;
   char input[256], * endptr;
   while (true) {
      printf ("Enter the number of elements (1 to %d): ", MAXSIZE);
      fgets (input, sizeof (input), stdin);
      size = strtol (input, &endptr, 10);   // Convert input to integer
      if (size < 1 || size > MAXSIZE) {
         printf ("Invalid number of elements. Please enter a value between 1 and %d.\n", MAXSIZE);
         continue;
      }
      break;
   }
   printf ("Enter %d integers:\n", size);
   for (int i = 0; i < size; i++) {
      while (true) {
         fgets (input, sizeof (input), stdin);
         long value = strtol (input, &endptr, 10);
         if ((*endptr != '\0' && *endptr != '\n') || value < INT_MIN || value > INT_MAX) {
            printf ("Invalid input.lease enter within the valid range of %d to %d: ",
               INT_MIN, INT_MAX);
            continue;
         }
         array[i] = (int)value;
         break;
      }
   }
   printf ("Unsorted Array: ");
   PrintArray (array, size);
  SortEntireArray (array, size);
   printf ("\nSorted Array: ");
   PrintArray (array, size);
   int target;    // Target element to search
   printf ("\nEnter the element to search for: ");
   fgets (input, sizeof (input), stdin);
   long value = strtol (input, &endptr, 10);
   if ((*endptr != '\0' && *endptr != '\n') || value < INT_MIN || value > INT_MAX) {
      printf ("Invalid input or input out of range."
         "Please enter a valid integer within the range of % d to % d.\n", INT_MIN, INT_MAX);
      return;
   }
   target = (int)value;  // Safe to assign the value
   int result = GetIndex (array, size, target);
   printf (result == ELEMENT_NOT_FOUND ? "Element %d not found.\n" :
      "Element %d found at index %d.\n", target, result);
}

int main () {
   int choice;
   do {
      printf ("\nSelect Option:\n1. Run Test Cases\n2. Get User Input for Sorting and Searching\n"
         "3. Exit\nEnter your choice: ");
      char input[256];
      fgets (input, sizeof (input), stdin);
      choice = atoi (input);    // Get user input for menu choice
      switch (choice) {
      case 1: RunQuickSortTest (); break;
      case 2: GetUserInput (); break;
      case 3: printf ("Exiting...\n"); break;
      default: printf ("Invalid choice. Please try again.\n");
      }
   } while (choice != 3);    // Keep running until user chooses to exit
   return 0;
}