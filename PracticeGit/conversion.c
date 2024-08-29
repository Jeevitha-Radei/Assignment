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

// Function to convert decimal to Binary
void DecToBinary (int n) {
   for (int i = 7; i >= 0; i--) printf ("%d", (n >> i) & 1);
   printf ("\n");
}  

// Function to convert decimal to Hexadecimal
void DecToHexadecimal (int n) {
   unsigned int num = (unsigned int)n & 0xFF;   // To handle negative numbers in two's complement
   char hexNum[2];  // Array to store hexadecimal number
   int i = 0;
   while (num != 0) {   // convert to hexadecimal using modulus division operator
      int temp = num % 16;
      if (temp < 10) hexNum[i] = temp + '0';   // Convert to ASCII
      else hexNum[i] = temp + 'A' - 10;   // Convert to ASCII (A-F)
      num /= 16;
      i++;
   }
   for (int j = 1; j >= i; j--) printf ("0");   // Print leading zeros if necessary to ensure 8 - bit output
   for (int j = i - 1; j >= 0; j--) printf ("%c", hexNum[j]);   // Print Hexadecimal in reverse order
}

int main () {
   int decimalNumber;
   int result;
   char term;   // To check for additional characters
   while (1) {
      printf ("Input: ");
      result = scanf ("%d%c", &decimalNumber, &term);  // Read input and check for additional characters
      if (result == 2 && ((term == '\n') || (term == ' '))) {
         printf ("HEX: ");
         DecToHexadecimal (decimalNumber);
         printf ("\n");
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