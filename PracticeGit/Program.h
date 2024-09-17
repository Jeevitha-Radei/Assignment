// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Jeevitha Ramesh - Graduate Engineer trainee 
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Palindrome Checker - Program to check whether the word is Palindrome or not.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Program.h
// Program on A4 branch.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef PROGRAM_H
#define PROGRAM_H

#define MAXLENGTH 256

/// <summary>Check if a string is palindrome or not. </summary>
int PalindromeChecker (const char* str);

/// <summary>Function to reverse an integer. </summary>
int ReverseInteger (int num, int* overflow);

/// <summary>Print the palindrome test cases in tabular format. </summary>
void PrintPalindromeTestCase (const char* testString, int result);

/// <summary>Print the Integer Reversal test cases in tabular format. </summary>
void PrintIntegerReversalTestCase (int original, int reversed, int overflow);

///  <summary>Execute Palindrome test cases. </summary>
void ExecutePalindromeCases (int isTest);

///  <summary>Execute Integer Reversal test cases. </summary>
void ExecuteIntegerReversalCases (int isTest);

#endif PROGRAM_H