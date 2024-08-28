#include <stdio.h>
// Function to convert decimal to Binary
void DecToBinary (int n) {
   if (n == 0) {   // Handle zero case
      printf ("0");
      return;
   }
   if (n < 0) {    // Handle Negative Integers
      printf ("-");
      n = -n;
   }
   int binaryNum[32];  // Array to store binary number (32 bits)
   int i = 0;
   while (n > 0) {        
      binaryNum[i] = n % 2;
      n = n / 2;
      i++;
   }
   for (int j = i - 1; j >= 0; j--) printf ("%d", binaryNum[j]);     // Print binary number in reverse order
}

// Function to print decimal number in hexadecimal using %X
void DecToHexadecimal (int n) {
   if (n == 0) {  
      printf ("0");
      return;
   }
   if (n < 0) {
      printf ("-");
      n = -n;
   }
   char hexNum[32];       // Array to store hexadecimal number
   int i = 0;
   while (n != 0) {
      int temp = n % 16;
      if (temp < 10)
         hexNum[i] = temp + '0';  // Convert to ASCII
      else
         hexNum[i] = temp + 'A' - 10;  // Convert to ASCII (A-F)
      n = n / 16;
      i++;
   }
   for (int j = i - 1; j >= 0; j--) printf ("%c", hexNum[j]);
   //printf ("%X", n);
}

int main () {
   int decimalNumber;
   printf ("Enter an Integer: ");
   if (scanf_s ("%d", &decimalNumber)) {
      printf ("Input: %d\n", decimalNumber);
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