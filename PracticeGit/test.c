// -------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------------------------------------------------------------------
// test.c - Function that tests the program and main.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Program.h"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

/// <summary>Execute palindrome test cases </summary>
void RunPalindromeTest ();

/// <summary>Execute Integer Reversal test cases </summary>
void RunIntegerReversalTest ();

///  <summary>Get user input for Palindrome checker </summary>
void GetPalindromeInput ();

///  <summary>Get user input for Integer reversal </summary>
void GetIntegerInput ();

void RunPalindromeTest () {
   const char* testStrings[] = { "Eva, can I stab bats in a cave?", "malaya&lam", "Hey!! World", "J", "No lemon, no melon","$$$",
                                 "Her favorite number is 2", "    ra   c eca  r " };
   int expectedResults[] = { PALINDROME, PALINDROME, NOT_PALINDROME, PALINDROME, PALINDROME,NOT_PALINDROME, NOT_PALINDROME, PALINDROME };
   int numTestCases = sizeof (testStrings) / sizeof (testStrings[0]);
   printf ("\n                           EXECUTE PALINDROME TEST CASES \n"
      "+------------------------------------------------------+-----------------------+----------+ \n"
      CYAN"|                      Test String                     |    Palindrome Check   |  Result  |\n"RESET
      "+------------------------------------------------------+-----------------------+----------+\n");
   for (int i = 0; i < numTestCases; i++) {
      int result = IsPalindrome_s (testStrings[i]);
      printf ("| %-52s | %-21s | %-19s |\n", testStrings[i], result == PALINDROME ? "Palindrome" : "Not a Palindrome", result == expectedResults[i] ? GREEN "Pass" RESET : RED "Fail" RESET);
      printf ("+------------------------------------------------------+-----------------------+----------+\n");
   }
}

void RunIntegerReversalTest () {
   int testCases[] = { 78987, 159, -1234, 0, INT_MAX, INT_MIN, 22022022, -4567654 };
   int expectedResults[] = { 78987, 951, -4321, 0, 0, 0, 22022022, -4567654 };
   int numTestCases = sizeof (testCases) / sizeof (testCases[0]);
   printf ("\n                   EXECUTE INTEGER REVERSAL TEST CASES\n"
      "\n+-------------------+---------------------------+------------------------+----------+\n"
      CYAN"| Original Integer  | Reversed Integer          | Palindrome Check       |  Result  |\n"RESET
      "+-------------------+---------------------------+------------------------+----------+\n");
   for (int i = 0; i < numTestCases; i++) {
      int reversed, result = ReverseInteger (testCases[i], &reversed);
      char reversedStr[12];    // Buffer for the reversed integer string
      snprintf (reversedStr, sizeof (reversedStr), "%d", reversed);
      char* isPalindrome = IsPalindrome_d (testCases[i], reversed) ? "Palindrome" : "Not a palindrome";
      char* testResult = reversed == expectedResults[i] ? GREEN "Pass" RESET : RED "Fail" RESET;
      printf ("| %-17d | %-25s | %-22s | %-20s|\n", testCases[i], (result == SUCCESS) ? reversedStr : "Overflow", (result == SUCCESS) ? isPalindrome : "Invalid Input", testResult);
      printf ("+-------------------+---------------------------+------------------------+----------+\n");
   }
}

void GetPalindromeInput () {
   char str[MAXLENGTH];
   printf ("\nEnter a phrase or text: ");
   if (fgets (str, MAXLENGTH, stdin) == NULL || (str[0] == '\n')) {
      printf ("Empty input is not a valid string.\n");
      return;
   }
   printf (IsPalindrome_s (str) == PALINDROME ? GREEN "Palindrome\n"RESET : RED"Not a palindrome\n"RESET);
}

void GetIntegerInput () {
   char input[MAXLENGTH];
   printf ("\nEnter an integer to reverse: ");
   if (fgets (input, MAXLENGTH, stdin) == NULL || (input[0] == '\n')) {
      printf ("Empty input is not a valid number.\n");
      return;
   }
   char* endPtr;
   long int number = strtol (input, &endPtr, 10);
   if (endPtr == input || (*endPtr != '\n' && *endPtr != '\0')) {
      printf ("Invalid input.\n");
      return;
   }
   int reversed;
   if (ReverseInteger ((int)number, &reversed) != SUCCESS) {
      printf ("Reversed Integer: Overflow\nInvalid input\n");
      return;
   }
   printf ("Reversed Integer: %d\n", reversed);
   printf (IsPalindrome_d ((int)number, reversed) == PALINDROME ? GREEN "Palindrome\n" RESET : RED "Not a palindrome\n" RESET);
}

int main () {
   char choiceStr[3];
   while (1) {
      printf ("\nSelect option:\n1. Execute test cases\n2. Enter a phrase or text\n3. Enter an integer to reverse\n4. Exit\nEnter your choice (1, 2, 3, or 4): ");
      fgets (choiceStr, sizeof (choiceStr), stdin);
      char* endPtr;
      long choice = strtol (choiceStr, &endPtr, 10);
      if (endPtr == choiceStr || *endPtr != '\n' || choice < 1 || choice > 4) {
         printf ("Invalid choice. Please enter 1, 2, 3, or 4.\n");
         while (getchar () != '\n');
         continue;
      }
      switch (choice) {
      case 1:
         RunPalindromeTest ();
         RunIntegerReversalTest ();
         break;
      case 2:
         GetPalindromeInput ();
         break;
      case 3:
         GetIntegerInput ();
         break;
      case 4:
         printf ("\nExiting the program.\n");
         return 0;
      }
   }
   return 0;
}