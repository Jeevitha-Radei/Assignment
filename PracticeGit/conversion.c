#pragma warning(disable:4996)
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Number conversion game 
// Program to get user input and convert given decimal number to different forms such as Hexadecimal and Binary
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// conversion.c
// Program on main branch.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>

// Function to convert decimal to Binary
void DecToBinary (int n) {
   unsigned int num = (unsigned int)n; // To handle negative numbers in two's complement
   int binaryNum[32];  // Array to store binary number (32 bits)
   int i = 0;
   if (num == 0) {
      printf ("0");
      return;
   }
   while (num > 0) { 
      binaryNum[i] = num % 2;
      num /= 2;
      i++;
   }
   for (int j = i - 1; j >= 0; j--) printf ("%d", binaryNum[j]);     // Print binary number in reverse order
}

// Function to print decimal number in hexadecimal 
void DecToHexadecimal (int n) {
   unsigned int num = (unsigned int)n; // To handle negative numbers in two's complement
   char hexNum[32];                    // Array to store hexadecimal number
   int i = 0;
   while (num != 0) {
      int temp = num % 16;
      if (temp < 10) hexNum[i] = temp + '0';     // Convert to ASCII
      else hexNum[i] = temp + 'A' - 10;          // Convert to ASCII (A-F)
      num /= 16;
      i++;
   }
   hexNum[i] = '\0'; // Null-terminate the string
   for (int j = i - 1; j >= 0; j--) printf ("%c", hexNum[j]);
   printf ("%X", n);
}

int main () {
   int decimalNumber;
   int result;
   char term;             // To check for additional characters
   printf ("Input: ");
   result = scanf ("%d%c", &decimalNumber, &term);
   if (result == 2 && ((term == '\n') || (term == ' '))) {
      printf ("HEX: ");
      DecToHexadecimal (decimalNumber);
      printf ("\n");
      printf ("Binary: ");
      DecToBinary (decimalNumber);
      printf ("\n");
   }
   else printf ("Invalid Integer.\n"); 

   return 0;
}