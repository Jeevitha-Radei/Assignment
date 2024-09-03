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
void DecToBinary (int n) {
   for (int i = 15; i >= 0; i--) printf ("%d", (n >> i) & 1);
   printf ("\n");
}

/// <summary>Function to convert decimal to Hexadecimal.</summary>
void DecToHexadecimal (int n) {
   char hexDigits[8];  // Array to store hexadecimal digits
   int hexIndex = 0;
   if (n < 0) {   // Handle negative integers by converting to two's complement
      int temp = -n;     // Convert positive part to binary
      int binary[BITS];
      for (int i = 0; i < BITS; i++) binary[i] = (temp >> i) & 1;  // Convert to binary
      for (int i = 0; i < BITS; i++) binary[i] = 1 - binary[i];  // Invert the bits
      int carry = 1;      // Add 1 to the result
      for (int i = 0; i < BITS; i++) {
         int sum = binary[i] + carry;
         binary[i] = sum % 2;
         carry = sum / 2;
      }
      for (int i = BITS - 1; i >= 0; i -= 4) {   // Convert binary array to hexadecimal
         int value = 0;
         for (int j = 0; j < 4; j++) value = (value << 1) | binary[i - j];
         if (value < 10) hexDigits[hexIndex++] = value + '0';   // Convert to character '0'-'9'
         else hexDigits[hexIndex++] = value - 10 + 'A';   // Convert to character 'A'-'F'
      }
   }
   else {
      while (n > 0) {    // Convert positive integer to hexadecimal
         int digit = n % 16;
         if (digit < 10) hexDigits[hexIndex++] = digit + '0';
         else hexDigits[hexIndex++] = digit - 10 + 'A';
         n /= 16;
      }
      while (hexIndex < 8)  hexDigits[hexIndex++] = '0';   // Fill remaining digits with '0'
      for (int i = 0; i < hexIndex / 2; i++) { // Reverse the array to get the correct hexadecimal representation
         char temp = hexDigits[i];
         hexDigits[i] = hexDigits[hexIndex - i - 1];
         hexDigits[hexIndex - i - 1] = temp;
      }
   }
   for (int i = 0; i < 8; i++) printf ("%c", hexDigits[i]);  // Print the hexadecimal digits
   printf ("\n");
}

int main () {
   int decimalNumber;
   int result;
   char term;   // To check for additional characters
   while (1) {
      printf ("Input: ");
      result = scanf ("%d%c", &decimalNumber, &term);  // Read input and check for additional characters
      if (result == 2 && (term == '\n')) {
         printf ("HEX: ");
         DecToHexadecimal (decimalNumber);
         printf ("Binary: ");
         DecToBinary (decimalNumber);
         printf ("\n");
         break;
      }
      else {
         printf ("Invalid Integer, try again. \n");
         while (getchar () != '\n');
      }
   }
   return 0;
}