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

int Partition (int array[], int left, int right) {
   int pivot = array[right], i = (left - 1);   // Select the last element as pivot
   for (int j = left; j < right; j++)
      if (array[j] <= pivot) Swap (&array[++i], &array[j]);
   Swap (&array[i + 1], &array[right]);   // Place the pivot in its correct position
   return (i + 1);
}

void QuickSort (int array[], int left, int right) {
   if (left < right) {
      int pi = Partition (array, left, right);
      QuickSort (array, left, pi - 1);
      QuickSort (array, pi + 1, right);
   }
}

int BinarySearch (int array[], int size, int target) {
   int left = 0, right = size - 1;
   while (left <= right) {
      int mid = (left + right) / 2, midValue = array[mid];   // Get the value at the middle index
      if (midValue == target) return mid;
      if (midValue < target) left = mid + 1;
      else right = mid - 1;
   }
   return ELEMENT_NOT_FOUND;
}