// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Program.c
// Program on A4 branch.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <ctype.h>
#include "Program.h"

int PalindromeChecker (const char* str) {
   if (str[0] == '-') return 0;  // Not a palindrome
   char input[MAXLENGTH] = { 0 };
   int index = 0;
   for (int i = 0; str[i] != '\0' && index < MAXLENGTH - 1; i++) {
      if (isalnum (str[i])) input[index++] = tolower (str[i]);  // Check if the character is alphanumeric
   }
   input[index] = '\0'; // Null-terminate the string
   int len = index; // Length of the input string
   for (int i = 0; i < len / 2; i++) {
      if (input[i] != input[len - 1 - i]) return 0; 
   }
   return 1; // Palindrome
}

int ReverseInteger (int num, int* reverseResult) {
   int reversed = 0;
   int isNegative = (num < 0);
   if (isNegative) num = -num;
   while (num != 0) {
      int digit = num % 10;
      if (reversed > (INT_MAX - digit) / 10) return OVERFLOW;
      reversed = reversed * 10 + digit;
      num /= 10;
   }
   *reverseResult = isNegative ? -reversed : reversed;
   return SUCCESS;
}