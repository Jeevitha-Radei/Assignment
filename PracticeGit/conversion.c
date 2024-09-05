// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Number conversion game 
// Program to get user input and convert given decimal number to Hexadecimal and Binary
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// conversion.c
// Program on A3 branch.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma warning(disable:4996)
#include <stdio.h>
#include <limits.h>

#define BITS 32
#define HEX_LENGTH 8

int binary[BITS];   // Global array to hold binary representation

/// <summary>Function to convert decimal to Binary.</summary>
void DecToBinary (int n) {
   for (int i = 0; i < BITS; i++)  binary[i] = (n >> i) & 1;
}

/// <summary>Print the binary representation.</summary>
void PrintBinary (int n) {
   printf ("Binary Equivalent for %d: ", n);
   for (int i = BITS - 1; i >= 0; i--) {
      printf ("%d", binary[i]);
      if ((i+1) % 8 == 0 && i != BITS - 1) printf (" ");
   }
   printf ("\n");
}

/// <summary>Convert a value to its corresponding hexadecimal character.</summary>
char ValueToHexChar (int value) {
   return (value < 10) ? (char)(value + '0') : (char)(value - 10 + 'A');
}

/// <summary>Function to convert decimal to Hexadecimal.</summary>
void DecToHexadecimal (char hexString[HEX_LENGTH + 1]) {
   //char hexDigits[8];  // Array to store hexadecimal digits
   int hexIndex = 0;
   for (int i = BITS - 1; i >= 0; i -= 4) {  // Convert binary array to hexadecimal
      int value = 0;
      for (int j = 0; j < 4; j++) value = (value << 1) | binary[i - j];
      hexString[hexIndex++] = ValueToHexChar (value);
   }
   while (hexIndex < 8) hexString[hexIndex++] = '0';  // Fill remaining digits with '0'
   hexString[HEX_LENGTH] = '\0';  // Null-terminate the string
}

/// <summary>Print the hexadecimal string.</summary> 
void PrintHexadecimal (int n, const char hexString[HEX_LENGTH]) {
   printf ("Hexadecimal Equivalent for %d: %s\n", n, hexString);
}

/// <summary> Function to run test cases.</summary>
void RunTestCases () {
   struct TestCase {
      long long input;
      const char* expectedBinary;
      const char* expectedHexadecimal;
   };
   struct TestCase testCases[] = {
       {42, "00000000 00000000 00000000 00101010", "002A"},
       {2147483648, "01111111 11111111 11111111 11111111", "7FFFFFFF"},
       {-2147483647, "10000000 00000000 00000000 00000000", "80000000"},
       {0, "00000000 00000000 00000000 00000000", "00000000"},
       {-123, "11111111 11111111 11111111 10000101", "FFFFFF85"},
       {255, "00000000 00000000 00000000 11111111", "000000FF"},
       {100, "00000000 00000000 00000000 01100100", "00000064"},
   };
   char hexString[HEX_LENGTH + 1];
   printf ("Running Test Cases:\n");
   for (int i = 0; i < sizeof (testCases) / sizeof (testCases[0]); i++) {
      long long inputNumber = testCases[i].input;
      int decimalNumber;
      printf ("Testing input: %lld\n", inputNumber);
      if (inputNumber < INT_MIN || inputNumber > INT_MAX) {
         printf ("Value out of range for a 32-bit signed integer.\n");
         continue;
      }
      else {
         decimalNumber = (int)inputNumber;
         DecToBinary (decimalNumber);
         PrintBinary (decimalNumber);
         DecToHexadecimal (hexString);
         PrintHexadecimal (decimalNumber, hexString);
         printf ("Expected Binary: %s\n", testCases[i].expectedBinary);
         printf ("Expected Hexadecimal: %s\n\n", testCases[i].expectedHexadecimal);
      }
   }
}

/// <summary> Function to run input given. </summary>
void RunInput () {
   long long inputNumber;
   int decimalNumber;
   char term, hexString[HEX_LENGTH + 1];  // To check additional characters,  // Length of the hexadecimal string +1 for Null terminator
   while (1) {
      printf ("Please enter an integer: ");
      int result = scanf ("%lld%c", &inputNumber, &term);    // Check if input is valid integer 
      if (result == 2 && (term == '\n')) {
         if (inputNumber < INT_MIN || inputNumber > INT_MAX)  printf ("Value out of range for a 32-bit signed integer. Try again.\n"); // Check if the input is within the valid range for a 32-bit signed integer
         else {
            decimalNumber = (int)inputNumber;
            DecToBinary (decimalNumber);
            PrintBinary (decimalNumber);
            DecToHexadecimal (hexString);
            PrintHexadecimal (decimalNumber, hexString);
            break;
         }
      }
      else printf ("Invalid Integer, try again.\n");
      while (getchar () != '\n');  // Clear any remaining characters in the buffer
   }
}
int main () {
   RunTestCases ();
   printf ("Now you can enter your own integers for conversion:\n");
   RunInput ();

   return 0;
}