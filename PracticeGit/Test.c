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

/// <summary> Prints the elements of an array. </summary>
void PrintArray (int array[], int size);

/// <summary> Runs test cases for the QuickSort function. </summary>
void RunQuickSortTest ();

/// <summary> Gets user input for an array, sorts it, and performs a binary search. </summary>
void GetUserInput ();

/// <summary>Compare Arrays returns true or false. </summary>
bool ArraysEqual (int arr1[], int arr2[], int size);

typedef struct {
   int array[MAXSIZE], size;
} TestCase;

void PrintArray (int array[], int size) {
   for (int i = 0; i < size; i++) printf ("%3d", array[i]);
}

bool ArraysEqual (int arr1[], int arr2[], int size) {
   for (int i = 0; i < size; i++) {
      if (arr1[i] != arr2[i]) return false;
   }
   return true;    // Arrays are equal if all elements match
}

void RunQuickSortTest () {
   TestCase testCases[] = {
       {{20, 49, 11, 3, 89, 75, 11, 12, 1}, 9},
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
   int elementSearch[] = { 11, 1, 0, -1, 2, 6, 36, 53, 11 };
   int testCount = sizeof (testCases) / sizeof (testCases[0]);
   printf ("+--------------------------------------------------+---------------+------------------+--------+\n"
      "|                Arrays                            | Key to Search | Index of element | Result |\n"
      "+--------------------------------------------------+---------------+------------------+--------+\n");
   for (int i = 0; i < testCount; i++) {
      int size = testCases[i].size, * arrayToSort = testCases[i].array;
      printf ("| Unsorted Array   | ");
      PrintArray (arrayToSort, size);
      printf ("%*s|", (MAXSIZE - size) * 3, " ");
      int searchValue = elementSearch[i];   // Element to search for in the current test case
      QuickSort (arrayToSort, 0, size - 1);
      int foundIndex = BinarySearch (arrayToSort, size, searchValue);
      if (foundIndex != ELEMENT_NOT_FOUND) printf ("    %-11d| Found at index %-d |", searchValue, foundIndex);
      else printf ("    %-11d|    Not Found     |", searchValue);
      printf ("  %-8s  |\n", ArraysEqual (arrayToSort, expectedResults[i], size) ? GREEN"Pass"RESET : RED"Fail"RESET);
      printf ("| Sorted Array     | ");
      PrintArray (arrayToSort, size);
      printf ("%*s|", (MAXSIZE - size) * 3, " ");
      printf ("\n+--------------------------------------------------+---------------+------------------+--------+\n");
   }
}

void GetUserInput () {
   int array[MAXSIZE], size;
   char input[256];
   printf ("Enter the number of elements (1 to %d): ", MAXSIZE);
   fgets (input, sizeof (input), stdin);
   size = atoi (input);     // Convert input to an integer
   if (size < 1 || size > MAXSIZE) {
      printf ("Invalid number of elements. Please enter a value between 1 and %d.\n", MAXSIZE);
      return;
   }
   printf ("Enter %d integers:\n", size);
   for (int i = 0; i < size; i++) {
      while (true) {
         fgets (input, sizeof (input), stdin);
         char* endptr;
         array[i] = strtol (input, &endptr, 10);
         if (endptr != input && *endptr == '\n')  break;
         printf ("Invalid input. Please enter an integer: ");
      }
   }
   printf ("Unsorted Array: ");
   PrintArray (array, size);
   QuickSort (array, 0, size - 1);
   printf ("\nSorted Array: ");
   PrintArray (array, size);
   int target;  // Target element to search
   printf ("\nEnter the element to search for: ");
   fgets (input, sizeof (input), stdin);
   char* endptr;
   target = strtol (input, &endptr, 10);
   if (endptr == input || *endptr != '\n') {
      printf ("Invalid input. Please enter a valid integer.\n");
      return;
   }
   int result = BinarySearch (array, size, target);
   printf ("Element %d found at index %d.\n", target, (result != -1) ? result : -1);
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
      case 1:
         RunQuickSortTest ();
         break;
      case 2:
         GetUserInput ();
         break;
      case 3:
         printf ("Exiting...\n");
         break;
      default:
         printf ("Invalid choice. Please try again.\n");
      }
   } while (choice != 3);    // Keep running until user chooses to exit
   return 0;
}