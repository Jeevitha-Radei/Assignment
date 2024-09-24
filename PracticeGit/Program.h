// -----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -----------------------------------------------------------------------------------------------
// Jeevitha R - Graduate Engineer trainee 
// -----------------------------------------------------------------------------------------------
// Palindrome Checker - Program to check whether the word is Palindrome or not.
// -----------------------------------------------------------------------------------------------
// Program.h
// Program on A4 branch.
// -----------------------------------------------------------------------------------------------
#ifndef PROGRAM_H
#define PROGRAM_H

#define MAXLENGTH 256
#define SUCCESS 0
#define OVERFLOW -2
#define PALINDROME 1
#define NOT_PALINDROME -1

/// <summary>Check if a string is palindrome or not. </summary>
int IsPalindrome (const char* str);

/// <summary>Function to reverse an integer. </summary>
int ReverseInteger (int num, int* reverseResult);

#endif PROGRAM_H