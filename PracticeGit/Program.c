// -----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -----------------------------------------------------------------------------------------------
// Program.c
// Program on A4 branch.
// -----------------------------------------------------------------------------------------------
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include "Program.h"

int IsPalindrome (const char* str) {
   if (strlen (str) == 1) return PALINDROME;
   int left, right = strlen (str) - 1;
   int isValidString = 0;     // Flag to indicate if the string contains valid alphanumeric characters
   for (left = 0; left < right;) {
      if (!isalnum (str[left])) {
         left++;
         continue;
      }
      if (!isalnum (str[right])) {
         right--;
         continue;
      }
      isValidString = 1;    // Mark as a valid string when a valid character is found 
      if (tolower (str[left++]) != tolower (str[right--])) return NOT_PALINDROME;
   }
   return isValidString;   // Return 1 if valid, indicating it's a palindrome
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
   *reverseResult = isNegative ? -reversed : reversed;   // Store the result with the correct sign
   return SUCCESS;
}