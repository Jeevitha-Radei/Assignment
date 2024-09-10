// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// test.c
// Program on A3 branch.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma warning(disable:4996)
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "conversion.h"

// Defines color codes for terminal output
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

void ProcessAndPrintConversions (long long inputNumber, char* formattedBinary, char* hexString) {
   if (inputNumber < INT_MIN || inputNumber > INT_MAX) printf ("Value out of range for a 32-bit signed integer. Try again.\n");
   else {
      int n = (int)inputNumber;
      DecimalToBinary (n);
      FormatBinary (formattedBinary);
      DecimalToHexadecimal (hexString);
      printf ("Binary Equivalent for %d: % s\n", n, formattedBinary);
      printf ("Hexadecimal Equivalent for %d: % s\n", n, hexString);
   }
}

void ExecuteConversions (int isTest) {
   char formattedBinary[BITS / 8 * 9 + 1], hexString[HEX_LENGTH + 1];
   if (isTest) {
      struct TestCase {
         long long input;
         const char* expectedBinary;
         const char* expectedHexadecimal;
      };
      struct TestCase testCases[] = {
          {42, "00000000 00000000 00000000 00101010", "0000002A"},
          {INT_MAX, "01111111 11111111 11111111 11111111", "7FFFFFFF"},
          {INT_MIN, "10000000 00000000 00000000 00000000", "80000000"},
          {0, "00000000 00000000 00000000 00000000", "00000000"},
          {-123, "11111111 11111111 11111111 10000101", "FFFFFF85"},
          {255, "00000000 00000000 00000000 11111111", "000000FF"},
          {100, "00000000 00000000 00000000 01100100", "00000064"},
          {2147483649,"0000000000000000000000000000000010000000000000000000000000000001", "0000000080000001" }
      };
      printf (BLUE "\nExecuting Test Cases " RESET ":\n");
      for (int i = 0; i < sizeof (testCases) / sizeof (testCases[0]); i++) {
         long long inputNumber = testCases[i].input;
         printf ("Testing input: %lld\n", inputNumber);
         ProcessAndPrintConversions (inputNumber, formattedBinary, hexString);
         int binaryPass = strcmp (formattedBinary, testCases[i].expectedBinary) == 0;
         int hexPass = strcmp (hexString, testCases[i].expectedHexadecimal) == 0;
         printf ("Test case: %s" RESET "\n\n", (binaryPass && hexPass) ? GREEN "PASS" : RED "FAIL");
      }
   }
   else {
      long long inputNumber;
      char term;
      while (1) {
         printf ("\nPlease enter an integer: ");
         int result = scanf ("%lld%c", &inputNumber, &term);
         if (result == 2 && (term == '\n')) {
            ProcessAndPrintConversions (inputNumber, formattedBinary, hexString);
            break;
         }
         else printf ("Invalid Integer, try again.\n");
         while (getchar () != '\n');  // To clear any remaining characters in the buffer
      }
   }
}

int main () {
   int choice;
   while (1) {
      printf (YELLOW "\nSelect option : "RESET" \n1. Execute test cases\n2. Provide input\n3. Exit\nEnter your choice (1, 2, or 3):");
      if (scanf ("%d", &choice) != 1) {
         while (getchar () != '\n');
         printf ("Invalid input, please enter a number.\n");
         continue;
      }
      switch (choice) {
      case 1:
         ExecuteConversions (1);
         break;
      case 2:
         printf (BLUE "\nExecuting user input "RESET"\n");
         ExecuteConversions (0);
         break;
      case 3:
         printf (BLUE "Exiting the program."RESET"\n");
         return 0;
      default:
         printf ("Invalid choice. Please enter 1, 2, or 3.\n");
      }
   }
   return 0;
}