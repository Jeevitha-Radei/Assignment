// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
// test.c
// Program on A4 branch.
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "Program.h"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

void PrintPalindromeTestCase (const char* testString, int result, int expectedResults) {
   printf ("| %-52s | %-21s | %-19s |\n", testString, result ? "Palindrome" : "Not a Palindrome", result == expectedResults ? GREEN"Pass"RESET : RED"Fail"RESET);
}

void PrintIntegerReversalTestCase (int original, int reverseResult, int reversed, int expectedResults) {
   char reversedStr[12]; // Buffer for the reversed integer string
   snprintf (reversedStr, sizeof (reversedStr), "%d", reversed);
   if (reverseResult == SUCCESS) printf ("| %-17d | %-25d | %-22s | %-20s|\n",
      original, reversed, PalindromeChecker (reversedStr) ? "Palindrome" : "Not a Palindrome", reversed == expectedResults ? GREEN"Pass"RESET : RED"Fail"RESET);
   else printf ("| %-17d | %-25s | %-22s | %-20s|\n", original, "Overflow", "Invalid input", reversed == expectedResults ? GREEN"Pass"RESET : RED"Fail"RESET);
}

void ExecutePalindromeCases (int isTest) {
   if (isTest) {
      const char* testStrings[] = { "Eva, can I stab bats in a cave?","Too bad, I hid a boot","Hey!! World", "No lemon, no melon","Malayalam",
                                    "Her favorite number is 2", "Was it a car or a cat I saw?" };
      int expectedResults[] = { PALINDROME, PALINDROME, NOT_PALINDROME, PALINDROME, PALINDROME, NOT_PALINDROME, PALINDROME };
      int numTestCases = sizeof (testStrings) / sizeof (testStrings[0]);
      printf ("\n                           EXECUTE PALINDROME TEST CASES \n");
      printf ("+------------------------------------------------------+-----------------------+----------+\n");
      printf (CYAN"|                      Test String                     |    Palindrome Check   |  Result  |\n"RESET);
      printf ("+------------------------------------------------------+-----------------------+----------+\n");
      for (int i = 0; i < numTestCases; i++) {
         int result = PalindromeChecker (testStrings[i]);
         PrintPalindromeTestCase (testStrings[i], result, expectedResults[i]);
         printf ("+------------------------------------------------------+-----------------------+----------+\n");
      }
   }
   else {
      char str[MAXLENGTH];
      printf ("\nEnter a phrase or text: ");
      if (fgets (str, MAXLENGTH, stdin) != NULL) {
         str[strcspn (str, "\n")] = '\0';
         if (strlen (str) == 0) printf ("Empty input is not a valid string.\n");
         else {
            int result = PalindromeChecker (str);
            printf (result ? GREEN"Palindrome\n"RESET : RED"Not a palindrome\n"RESET);
         }
      }
      else printf (RED"Error reading input.\n"RESET);
   }
}

void ExecuteIntegerReversalCases (int isTest) {
   if (isTest) {
      int testCases[] = { 78987, 159, -1234, 0, INT_MAX, INT_MIN, 22022022, -4567654 };
      int expectedResults[] = { 78987, 951, -4321, 0, 0, 0, 22022022, -4567654 };
      int numTestCases = sizeof (testCases) / sizeof (testCases[0]);
      printf ("                   EXECUTE INTEGER REVERSAL TEST CASES\n");
      printf ("+-------------------+---------------------------+------------------------+----------+\n");
      printf (CYAN"| Original Integer  | Reversed Integer          | Palindrome Check       |  Result  |\n"RESET);
      printf ("+-------------------+---------------------------+------------------------+----------+\n");
      for (int i = 0; i < numTestCases; i++) {
         int reversed;
         int result = ReverseInteger (testCases[i], &reversed);
         PrintIntegerReversalTestCase (testCases[i], result, reversed, expectedResults[i]);
         printf ("+-------------------+---------------------------+------------------------+----------+\n");
      }
   }
   else {
      char input[MAXLENGTH];
      printf ("\nEnter an integer to reverse: ");
      if (fgets (input, sizeof (input), stdin) != NULL) {
         char* endPtr = NULL;
         long int number = strtol (input, &endPtr, 10);
         if (endPtr == input || *endPtr != '\0' && *endPtr != '\n') printf (YELLOW"Invalid input.\n"RESET);
         else {
            int reversed, reverseResult = ReverseInteger ((int)number, &reversed);
            if (reverseResult == SUCCESS) {
               char reversedStr[12];
               snprintf (reversedStr, sizeof (reversedStr), "%d", reversed);
               printf ("Reversed Integer: %d\n%s", reversed, PalindromeChecker (reversedStr) ? GREEN"Palindrome\n"RESET : RED"Not a palindrome\n"RESET);
            }
            else printf ("Reversed Integer: Overflow\n"YELLOW"Invalid input\n"RESET);
         }
      }
      else printf (RED"Error reading input.\n"RESET);
   }
}

int main () {
   char choiceStr[3]; // Buffer for user input
   while (1) {
      printf ("\nSelect option:\n1. Execute test cases\n2. Enter a phrase or text\n3. Enter an integer to reverse\n4. Exit\nEnter your choice (1, 2, 3, or 4): ");
      fgets (choiceStr, sizeof (choiceStr), stdin);
      int choice = atoi (choiceStr);
      switch (choice) {
      case 1:
         ExecutePalindromeCases (1);
         ExecuteIntegerReversalCases (1);
         break;
      case 2:
         ExecutePalindromeCases (0);
         break;
      case 3:
         ExecuteIntegerReversalCases (0);
         break;
      case 4:
         printf ("Exiting the program.\n");
         return 0;
      default:
         while (getchar () != '\n');  // Discard any leftover characters
         printf ("Invalid choice. Please enter 1, 2, 3, or 4.\n");
      }
   }
   return 0;
}