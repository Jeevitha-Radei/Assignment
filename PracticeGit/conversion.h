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

// Define constants for bit manipulation and formatting
#define BITS 32
#define HEX_LENGTH 8

/// <summary>Function to convert decimal to Binary.</summary>
void DecToBinary (int n);

/// <summary>Function to format binary representation into a string. </summary>
void FormatBinary (char formattedBinary[BITS / 8 * 9 + 1]);

/// <summary>Convert a value to its corresponding hexadecimal character.</summary>
char ValueToHexChar (int value);

/// <summary>Function to convert decimal to Hexadecimal.</summary>
void DecToHexadecimal (char hexString[HEX_LENGTH + 1]);

/// <summary>Print the binary representation.</summary>
void PrintBinary (int n, const char formattedBinary[BITS / 8 * 9 + 1]);

/// <summary>Print the hexadecimal string.</summary> 
void PrintHexadecimal (int n, const char hexString[HEX_LENGTH]);

/// <summary> Function to run test cases.</summary>
void ExecuteConversions (int isTest);

#endif CONVERSION_H