// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Program.c - Program that has quick sort and binary search function
// ------------------------------------------------------------------------------------------------
#include "Program.h"

#define ELEMENT_NOT_FOUND -1

void Swap (int* a, int* b) {
   if (a != b) {   // swap only if it is in diferent addresses
      *a = *a + *b;
      *b = *a - *b;
      *a = *a - *b;
   }
}

void QuickSort (int array[], int size) {
   if (size <= 1) return;  // No need to sort an empty or single-element array
   int left = 0, right = size - 1;
   if (left < right) {
      int pivot = array[right];   // Select the pivot element (last element in the array)
      int i = left - 1;
      for (int j = left; j < right; j++) {
         if (array[j] <= pivot) {
            i++;
            Swap (&array[i], &array[j]);
         }
      }
      Swap (&array[i + 1], &array[right]);
      int pi = i + 1;   // Partition the array and sort the subarrays recursively
      QuickSort (array, pi);         // Sort the left subarray
      QuickSort (array + pi + 1, size - pi - 1);  // Sort the right subarray
   }
}

int GetIndex (int array[], int size, int target) {
   int left = 0, right = size - 1, result = ELEMENT_NOT_FOUND;;
   while (left <= right) {
      int mid = (left + right) / 2;
      if (array[mid] == target) {
         result = mid;  // Store the index when we find the target
         right = mid - 1;  // Continue searching on the left side to find the first occurrence
      }
      else if (array[mid] < target) left = mid + 1;
      else right = mid - 1;
   }
   return result;
}