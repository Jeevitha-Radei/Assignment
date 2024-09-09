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

// Define color codes for terminal output
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

void PrintBinary (int n, const char formattedBinary[BITS / 8 * 9 + 1]) {
   printf ("Binary Equivalent for %d: % s\n", n, formattedBinary);
}

void PrintHexadecimal (int n, const char hexString[HEX_LENGTH]) {
   printf ("Hexadecimal Equivalent for %d: % s\n", n, hexString);
}

void ExecuteConversions (int isTest) {
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
      };
      char formattedBinary[BITS / 8 * 9 + 1];
      char hexString[HEX_LENGTH + 1];
      printf (BLUE "Executing Test Cases " RESET ":\n");
      for (int i = 0; i < sizeof (testCases) / sizeof (testCases[0]); i++) {
         long long inputNumber = testCases[i].input;
         int decimalNumber = (int)inputNumber;
         DecToBinary (decimalNumber);
         FormatBinary (formattedBinary);
         DecToHexadecimal (hexString);
         int binaryPass = strcmp (formattedBinary, testCases[i].expectedBinary) == 0;
         int hexPass = strcmp (hexString, testCases[i].expectedHexadecimal) == 0;
         printf ("Testing input: %lld\n", inputNumber);
         PrintBinary (decimalNumber, formattedBinary);
         PrintHexadecimal (decimalNumber, hexString);
         printf ("%s" RESET "\n", (binaryPass && hexPass) ? GREEN "PASS" : RED "FAIL");
         printf ("\n");
      }
   }
   else {
      long long inputNumber;
      char term, hexString[HEX_LENGTH + 1], formattedBinary[BITS / 8 * 9 + 1];
      while (1) {
         printf ("Please enter an integer: ");
         int result = scanf ("%lld%c", &inputNumber, &term);
         if (result == 2 && (term == '\n')) {
            if (inputNumber < INT_MIN || inputNumber > INT_MAX) printf ("Value out of range for a 32-bit signed integer. Try again.\n");
            else {
               int decimalNumber = (int)inputNumber;
               DecToBinary (decimalNumber);
               FormatBinary (formattedBinary);
               DecToHexadecimal (hexString);
               PrintBinary (decimalNumber, formattedBinary);
               PrintHexadecimal (decimalNumber, hexString);
               break;
            }
         }
         else printf ("Invalid Integer, try again.\n");
         while (getchar () != '\n');  // To clear any remaining characters in the buffer
      }
   }
}

int main () {
   int choice;
   while (1) {
      printf (YELLOW "Select option : "RESET" \n");
      printf ("1. Execute test cases\n");
      printf ("2. Provide input\n");
      printf ("3. Exit\n");
      printf ("Enter your choice (1, 2, or 3):");
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
         printf (BLUE "Executing user input "RESET"\n");
         ExecuteConversions (0);
         break;
      case 3:
         printf (BLUE "Exiting the program."RESET"\n");
         return 0;
      default:
         printf ("Invalid choice. Please enter 1, 2, or 3.\n");
         printf ("\n");
      }
   }

   return 0;
}