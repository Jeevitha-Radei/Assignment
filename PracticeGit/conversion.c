#pragma warning(disable:4996)
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
#include <stdio.h>

#define BITS 32

/// <summary>Function to convert decimal to Binary.</summary>
void DecToBinary (int n, int binary[], int numBits) {
   for (int i = 0; i < numBits; i++)  binary[i] = (n >> i) & 1;
}

/// <summary>Print the binary representation.</summary>
void PrintBinary (int binary[], int numBits) {
   for (int i = numBits - 1; i >= 0; i--)  printf ("%d", binary[i]);
}

/// <summary>Convert a decimal integer to its two's complement binary representation.</summary>
void TwosComplement (int n, int binary[], int numBits) {
   DecToBinary (n, binary, numBits);
   for (int i = 0; i < numBits; i++) binary[i] = 1 - binary[i];   // Invert the bits
   int carry = 1;    // Add 1 to the result
   for (int i = 0; i < numBits; i++) {
      int sum = binary[i] + carry;
      binary[i] = sum % 2;
      carry = sum / 2;
   }
}

/// <summary>Convert a value to its corresponding hexadecimal character.</summary>
char ValueToHexChar (int value) {
   return (value < 10) ? (char)(value + '0') : (char)(value - 10 + 'A');
}

/// <summary>Function to convert decimal to Hexadecimal.</summary>
void DecToHexadecimal (int n) {
   char hexDigits[8];  // Array to store hexadecimal digits
   int hexIndex = 0, binary[BITS];
   if (n < 0) TwosComplement (-n, binary, BITS);  // Handle negative integers by converting to two's complement
   else DecToBinary (n, binary, BITS);  // Compute binary representation
   for (int i = BITS - 1; i >= 0; i -= 4) {  // Convert binary array to hexadecimal
      int value = 0;
      for (int j = 0; j < 4; j++) value = (value << 1) | binary[i - j];
      hexDigits[hexIndex++] = ValueToHexChar (value);
   }
   while (hexIndex < 8) hexDigits[hexIndex++] = '0';  // Fill remaining digits with '0'
   for (int i = 0; i < 8; i++) printf ("%c", hexDigits[i]);
}

int main () {
   int decimalNumber, binary[BITS];
   char term;  // To check for additional characters
   while (1) {
      printf ("Input: ");
      int result = scanf ("%d%c", &decimalNumber, &term);  // Read input and check for additional characters
      if (result == 2 && (term == '\n')) {
         printf ("HEX: ");
         DecToHexadecimal (decimalNumber);
         printf ("\n");
         printf ("Binary: ");
         DecToBinary (decimalNumber, binary, BITS);
         PrintBinary (binary, BITS);
         printf ("\n");
         break;
      }
      else {
         printf ("Invalid Integer, try again.\n");
         while (getchar () != '\n');  
      }
   }
   return 0;
}
