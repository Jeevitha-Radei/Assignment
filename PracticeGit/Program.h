// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Jeevitha R - GET
// ------------------------------------------------------------------------------------------------
// Program that sort integer array in ascending order using Quick sort and 
// also implemented binary search to search an element
// ------------------------------------------------------------------------------------------------
// Program.h
// ------------------------------------------------------------------------------------------------

#ifndef PROGRAM_H
#define PROGRAM_H

/// <summary> Function to swap elements.</summary>
void Swap (int* a, int* b);

/// <summary> Function to find the partition position.</summary>
int Partition (int array[], int left, int right);

/// <summary> Function to perform the QuickSort algorithm. </summary>
void QuickSort (int array[], int left, int right);

/// <summary> Function to perform a binary search on a sorted array. </summary>
int BinarySearch (int array[], int size, int target);

#endif