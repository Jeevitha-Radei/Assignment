// -----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -----------------------------------------------------------------------------------------------
// Program.c - Function handles palindrome checking for strings & integers, along with integer reversal.
// -----------------------------------------------------------------------------------------------
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include "Program.h"

int IsPalindrome_s (const char* str) {
   int left = 0, right = (int)strlen (str) - 1, isValidString = 0;
   while (left <= right) {
      if (!isalnum (str[left])) {
         left++;
         continue;
      }
      if (!isalnum (str[right])) {
         right--;
         continue;
      }
      isValidString = 1;
      if (tolower (str[left++]) != tolower (str[right--])) return NOT_PALINDROME;
   }
   return isValidString;
}

int ReverseInteger (int num, int* reverseResult) {
   int reversed = 0, isNegative = 0;
   if (num < 0) { isNegative = 1; num = -num; }
   while (num != 0) {
      int digit = num % 10;
      if (reversed > (INT_MAX - digit) / 10) return OVERFLOW;
      reversed = reversed * 10 + digit;
      num /= 10;
   }
   *reverseResult = isNegative ? -reversed : reversed;   // Store the result with the correct sign
   return SUCCESS;
}

int IsPalindrome_d (int num, int reversed) {
   return (num >= 0 && num == reversed) ? PALINDROME : NOT_PALINDROME;
}