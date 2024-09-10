// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Jeevitha Ramesh - Graduate Engineer trainee 
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Number conversion game - Program to get user input and convert given decimal number to Hexadecimal and Binary
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// conversion.h
// Program on A3 branch.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef CONVERSION_H
#define CONVERSION_H

// Defines constant for bit manipulation and formatting
#define BITS 32
#define HEX_LENGTH 8

/// <summary>Converts decimal to Binary.</summary>
void DecimalToBinary (int n);

/// <summary>Formats binary representation into a string. </summary>
void FormatBinary (char formattedBinary[BITS / 8 * 9 + 1]);

/// <summary>Converts a value to its corresponding hexadecimal character.</summary>
char ValueToHexCharacter (int value);

/// <summary>Converts decimal to Hexadecimal.</summary>
void DecimalToHexadecimal (char hexString[HEX_LENGTH + 1]);

/// <summary>Process and print conversions for a given integer.</summary>
void ProcessAndPrintConversions (long long inputNumber, char* formattedBinary, char* hexString);

/// <summary>Executes conversions either in test mode or interactive mode.</summary>
void ExecuteConversions (int isTest);

#endif CONVERSION_H