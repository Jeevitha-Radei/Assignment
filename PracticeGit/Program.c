#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Program.h"

int PalindromeChecker (const char* str) {
   size_t left = 0;
   size_t right = strlen (str) - 1;
   while (left < right) {
      if (!isalnum ((unsigned char)str[left])) left++;
      else if (!isalnum ((unsigned char)str[right])) right--;
      else {
         if (tolower ((unsigned char)str[left]) != tolower ((unsigned char)str[right])) return 0;
         left++;
         right--;
      }
   }
   if (str[0] == '-') return 0;
   return 1;
}

int ReverseInteger (int num, int* overflow) {
   int reversed = 0;
   *overflow = 0; 
   if (num < 0) {
      num = -num;
      while (num != 0) {
         int digit = num % 10;
         if (reversed > (INT_MAX - digit) / 10) {
            *overflow = 1;
            return 0; // Indicate overflow
         }
         reversed = reversed * 10 + digit;
         num /= 10;
      }
      return -reversed;
   }
   else {
      while (num != 0) {
         int digit = num % 10;
         if (reversed > (INT_MAX - digit) / 10) {
            *overflow = 1;
            return 0;
         }
         reversed = reversed * 10 + digit;
         num /= 10;
      }
      return reversed;
   }
}