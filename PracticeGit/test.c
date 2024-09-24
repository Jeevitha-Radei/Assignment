// -------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------------------------------------------------------------------
// test.c
// Program on A4 branch.
// ------------------------------------------------------------------------------------------------
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

/// <summary>Execute palindrome test cases </summary>
void RunPalindromeTest ();

/// <summary>Execute Integer Reversal test cases </summary>
void RunIntegerReversalTest ();

/// <summary>Dynamically allocate a string from stdin </summary>
char* DynamicStringInput ();

///  <summary>Get user input for Palindrome checker </summary>
void GetPalindromeInput ();

///  <summary>Get user input for Integer reversal </summary>
void GetIntegerInput ();

void RunPalindromeTest () {
   const char* testStrings[] = { "Eva, can I stab bats in a cave?","Too bad, I hid a boot","Hey!! World", "No lemon, no melon","Malayalam",
                                 "Her favorite number is 2", "Was it a car or a cat I saw?" };
   int expectedResults[] = { PALINDROME, PALINDROME, NOT_PALINDROME, PALINDROME, PALINDROME, NOT_PALINDROME, PALINDROME };
   int numTestCases = sizeof (testStrings) / sizeof (testStrings[0]);
   printf ("\n                           EXECUTE PALINDROME TEST CASES \n"
      "+------------------------------------------------------+-----------------------+----------+ \n"
      CYAN"|                      Test String                     |    Palindrome Check   |  Result  |\n"RESET
      "+------------------------------------------------------+-----------------------+----------+\n");
   for (int i = 0; i < numTestCases; i++) {
      int result = IsPalindrome (testStrings[i]);
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
      int reversed;
      int result = ReverseInteger (testCases[i], &reversed);
      char reversedStr[12]; // Buffer for the reversed integer string
      snprintf (reversedStr, sizeof (reversedStr), "%d", reversed);
      if (result == SUCCESS) printf ("| %-17d | %-25d | %-22s | %-20s|\n", testCases[i], reversed,
         IsPalindrome (reversedStr) == PALINDROME ? "Palindrome" : "Not a Palindrome", reversed == expectedResults[i] ? GREEN "Pass" RESET : RED "Fail" RESET);
      else printf ("| %-17d | %-25s | %-22s | %-20s|\n", testCases[i], "Overflow", "Invalid input", reversed == expectedResults[i] ? GREEN "Pass" RESET : RED "Fail" RESET);
      printf ("+-------------------+---------------------------+------------------------+----------+\n");
   }
}

// Dynamically reads a line of input from stdin and returns it as a null-terminated string.
// Handles memory allocation and failures, doubling strategy for resizing the string.
char* DynamicStringInput () {
   char* str = NULL, c;
   int size = 1;
   str = malloc (size * sizeof (char));
   if (!str) {
      perror ("Failed to allocate memory");
      return NULL;
   }
   int i = 0;
   while ((c = getc (stdin)) != '\n' && c != EOF) {
      str[i++] = c;
      if (i >= size) {
         size *= 2; // Double the size
         char* temp = realloc (str, size * sizeof (char));
         if (!temp) {
            free (str);
            perror ("Failed to reallocate memory");
            return NULL;
         }
         str = temp;
      }
   }
   str[i] = '\0';
   return str;
}

void GetPalindromeInput () {
   printf ("\nEnter a phrase or text: ");
   char* str = DynamicStringInput ();
   if (str == NULL || strlen (str) == 0) {
      printf (YELLOW "Empty input is not a valid string.\n" RESET);
      free (str);
      return;
   }
   int result = IsPalindrome (str);
   printf (result == PALINDROME ? GREEN "Palindrome\n" RESET : RED "Not a palindrome\n" RESET);
   free (str);
}

void GetIntegerInput () {
   printf ("\nEnter an integer to reverse: ");
   char* input = DynamicStringInput ();
   if (input == NULL || strlen (input) == 0) {
      printf (YELLOW "Invalid input.\n" RESET);
      return;
   }
   char* endPtr = NULL;
   long int number = strtol (input, &endPtr, 10);
   if (endPtr == input || (*endPtr != '\0' && *endPtr != '\n')) {
      printf (YELLOW "Invalid input.\n" RESET);
      free (input);
      return;
   }
   int reversed, reverseResult = ReverseInteger ((int)number, &reversed);
   if (reverseResult != SUCCESS) {
      printf ("Reversed Integer: Overflow\n" YELLOW "Invalid input\n" RESET);
      free (input);
      return;
   }
   if (number < 0) printf ("Reversed Integer: %d\n" RED "Not a palindrome\n" RESET, reversed);
   else  printf ("Reversed Integer: %d\n%s", reversed, IsPalindrome (input) == PALINDROME ? GREEN "Palindrome\n" RESET : RED "Not a palindrome\n" RESET);
   free (input);
}

int main () {
   char choiceStr[3]; // Buffer for user input
   while (1) {
      printf ("\nSelect option:\n1. Execute test cases\n2. Enter a phrase or text\n3. Enter an integer to reverse\n4. Exit\nEnter your choice (1, 2, 3, or 4): ");
      fgets (choiceStr, sizeof (choiceStr), stdin);
      char* endPtr;
      long choice = strtol (choiceStr, &endPtr, 10);
      if (endPtr != choiceStr && *endPtr == '\n' && choice >= 1 && choice <= 4) {
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
      else {
         while (getchar () != '\n');  // Discard any leftover characters
         printf ("Invalid choice. Please enter 1, 2, 3, or 4.\n");
      }
   }
   return 0;
}