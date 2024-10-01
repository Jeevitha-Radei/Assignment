// -----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -----------------------------------------------------------------------------------------------
// Jeevitha R - Graduate Engineer trainee 
// -----------------------------------------------------------------------------------------------
// Palindrome Checker - Program to check whether the word is Palindrome or not.
// -----------------------------------------------------------------------------------------------
// Program.h - Function declarations
// -----------------------------------------------------------------------------------------------
#ifndef PROGRAM_H
#define PROGRAM_H

#define MAXLENGTH 100
#define SUCCESS 2
#define OVERFLOW -2
#define PALINDROME 1
#define NOT_PALINDROME 0

/// <summary>Returns true if palindrome else false for strings. </summary>
int IsPalindrome_s (const char* str);

/// <summary>Function to reverse an integer. </summary>
int ReverseInteger (int num, int* reverseResult);

/// <summary>Returns true if palindrome else false for integers. </summary>
int IsPalindrome_d (int num, int reversed);

#endif PROGRAM_H