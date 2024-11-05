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

///  <summary>Get user input for Integer reversal </summary>
void GetInput ();

void RunPalindromeTest () {
   const char* testStrings[] = { "Eva, can I stab bats in a cave?", "malaya&lam", "Hey!! World", 
                                "J", "12321","No lemon, no melon","$$$","Her favorite number is 2",
                                "    ra   c eca  r ", "-36963" };
   int expectedResults[] = { PALINDROME, PALINDROME, NOT_PALINDROME, PALINDROME, PALINDROME, 
                             PALINDROME,NOT_PALINDROME, NOT_PALINDROME, PALINDROME, PALINDROME };
   int numTestCases = sizeof (testStrings) / sizeof (testStrings[0]);
   printf ("\n                           EXECUTE PALINDROME TEST CASES \n"
      "+------------------------------------------------------+-----------------------+----------+ \n"
      CYAN"|                      Test String                     |    Palindrome Check   |  Result  |\n"RESET
      "+------------------------------------------------------+-----------------------+----------+\n");
   for (int i = 0; i < numTestCases; i++) {
      int result = IsPalindrome_s (testStrings[i]);
      printf ("| %-52s | %-21s | %-19s |\n", testStrings[i], result ? "Palindrome" : "Not a Palindrome", 
         result == expectedResults[i] ? GREEN "Pass" RESET : RED "Fail" RESET);
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
      if (result == SUCCESS) printf ("| %-17d | %-25d | %-22s | %-20s|\n", testCases[i], reversed,IsPalindrome_d (testCases[i])
         ? "Palindrome" : "Not a Palindrome", reversed == expectedResults[i] ? GREEN "Pass" RESET : RED "Fail" RESET);
      else printf ("| %-17d | %-25s | %-22s | %-20s|\n", testCases[i], "Overflow", "Invalid input", 
         reversed == expectedResults[i] ? GREEN "Pass" RESET : RED "Fail" RESET);
      printf ("+-------------------+---------------------------+------------------------+----------+\n");
   }
}

void GetInput () {
   char input[MAXLENGTH];
   printf ("\nEnter a phrase or an integer: ");
   if (fgets (input, MAXLENGTH, stdin) == NULL || (input[0] == '\n')) {
      printf ("Empty input is not a valid string.\n");
      return;
   }
   char* endPtr;
   long int number = strtol (input, &endPtr, 10);
   if (endPtr != input && (*endPtr == '\n' || *endPtr == '\0') && number >= INT_MIN && number <= INT_MAX) {
      int reversed;
      if (ReverseInteger ((int)number, &reversed) != SUCCESS) {
         printf ("Reversed Integer: Overflow\nInvalid input\n");
         return;
      }
      printf ("Reversed Integer: %d\n%s", reversed, IsPalindrome_d ((int)number) ? GREEN "Palindrome\n" RESET : RED "Not a palindrome\n" RESET);
   }
   else printf (IsPalindrome_s (input) ? GREEN "Palindrome\n" RESET : RED "Not a palindrome\n" RESET);
}

int main () {
   char choiceStr[3];
   while (1) {
      printf ("\nSelect option:\n1. Execute test cases\n2. Enter a phrase or integer: \n3. Exit\n "
         "Enter your choice (1, 2, or 3) : ");
      fgets (choiceStr, sizeof (choiceStr), stdin);
      char* endPtr;
      long choice = strtol (choiceStr, &endPtr, 10);
      if (endPtr == choiceStr || *endPtr != '\n' || choice < 1 || choice > 3) {
         printf ("Invalid choice. Please enter 1, 2, or 3.\n");
         while (getchar () != '\n');
         continue;
      }
      switch (choice) {
      case 1:
         RunPalindromeTest ();
         RunIntegerReversalTest ();
         break;
      case 2:
         GetInput ();
         break;
      case 3:
         printf ("\nExiting the program.\n");
         return 0;
      }
   }
   return 0;
}