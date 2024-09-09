// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// conversion.c
// Program on A3 branch.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "conversion.h"

int binary[BITS];   // Global array to hold binary representation

void DecToBinary (int n) {
   for (int i = 0; i < BITS; i++)  binary[i] = (n >> i) & 1;
}

void FormatBinary (char formattedBinary[BITS / 8 * 9 + 1]) {
   char actualBinary[BITS + 1];
   for (int j = 0; j < BITS; j++) actualBinary[j] = binary[BITS - 1 - j] ? '1' : '0';
   actualBinary[BITS] = '\0';
   int pos = 0;
   for (int j = 0; j < BITS; j++) {
      if (j > 0 && j % 8 == 0) formattedBinary[pos++] = ' ';
      formattedBinary[pos++] = actualBinary[j];
   }
   formattedBinary[pos] = '\0';
}

char ValueToHexChar (int value) {
   return (value < 10) ? (char)(value + '0') : (char)(value - 10 + 'A');
}

void DecToHexadecimal (char hexString[HEX_LENGTH + 1]) {
   int hexIndex = 0;
   for (int i = BITS - 1; i >= 0; i -= 4) {  // Convert binary array to hexadecimal
      int value = 0;
      for (int j = 0; j < 4; j++) value = (value << 1) | binary[i - j];
      hexString[hexIndex++] = ValueToHexChar (value);
   }
   while (hexIndex < 8) hexString[hexIndex++] = '0';  // Fill remaining digits with '0'
   hexString[HEX_LENGTH] = '\0';  // Null-terminate the string
}