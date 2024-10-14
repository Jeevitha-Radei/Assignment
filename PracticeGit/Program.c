// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Program.c - Program that has quick sort and binary search function
// ------------------------------------------------------------------------------------------------

#include "Program.h"

void Swap (int* a, int* b) {
   int t = *a;
   *a = *b;
   *b = t;
}

int Partition (int array[], int left, int right) {
   int pivot = array[right], i = (left - 1);
   for (int j = left; j < right; j++) {
      if (array[j] <= pivot) {
         i++;
         Swap (&array[i], &array[j]);
      }
   }
   Swap (&array[i + 1], &array[right]);
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
      int mid = (left + right) / 2;
      if (array[mid] == target) return mid;
      if (array[mid] < target) left = mid + 1;
      else right = mid - 1;
   }
   return -1; // Element not found
}