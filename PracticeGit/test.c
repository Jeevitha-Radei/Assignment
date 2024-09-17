#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "Program.h"

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

void PrintPalindromeTestCase (const char* testString, int result) {
   printf ("| %-52s | %-32s |\n", testString, result ? GREEN"Palindrome"RESET : RED"Not a Palindrome"RESET);
}

void PrintIntegerReversalTestCase (int original, int reversed, int overflow) {
   if (overflow) printf ("| %-17d | %-36s | %-33s |\n", original, BLUE"Overflow"RESET, YELLOW"Invalid input"RESET);
   else {
      char reversedStr[12]; // Buffer for the reversed integer string
      snprintf (reversedStr, sizeof (reversedStr), "%d", reversed);
      printf ("| %-17d | %-25d | %-33s |\n", original, reversed, PalindromeChecker (reversedStr) ? GREEN"Palindrome"RESET : RED"Not a Palindrome"RESET);
   }
}

void ExecutePalindromeCases (int isTest) {
   if (isTest) {
      const char* testStrings[] = { "Eva, can I stab bats in a cave?","Too bad, I hid a boot","Hey!! World", "No lemon, no melon","Malayalam","Her favorite number is 2", "Was it a car or a cat I saw?" };
      int numTestCases = sizeof (testStrings) / sizeof (testStrings[0]);
      printf (MAGENTA"\n                    EXECUTE PALINDROME TEST CASES \n"RESET);
      printf ("+------------------------------------------------------+-----------------------+\n");
      printf (CYAN"|                      Test String                     |        Result         |\n"RESET);
      printf ("+------------------------------------------------------+-----------------------+\n");
      for (int i = 0; i < numTestCases; i++) {
         int result = PalindromeChecker (testStrings[i]);
         PrintPalindromeTestCase (testStrings[i], result);
         printf ("+------------------------------------------------------+-----------------------+\n");
      }
   }
   else {
      char str[MAXLENGTH];
      printf ("\nEnter a phrase or text: ");
      while (getchar () != '\n');
      if (fgets (str, MAXLENGTH, stdin) != NULL) {
         str[strcspn (str, "\n")] = '\0';
         if (strlen (str) == 0) printf ("Empty input is not a valid string.\n");
         else {
            int result = PalindromeChecker (str);
            printf (result ? GREEN"Palindrome"RESET : RED"Not a palindrome"RESET);
         }
      }
      else printf (RED"Error reading input.\n"RESET);
   }
}

void ExecuteIntegerReversalCases (int isTest) {
   if (isTest) {
      int testCases[] = { 78987,159,-1234,0,INT_MAX, INT_MIN,22022022,-4567654 };
      int numTestCases = sizeof (testCases) / sizeof (testCases[0]);
      printf (MAGENTA"                 EXECUTE INTEGER REVERSAL TEST CASES\n"RESET);
      printf ("+-------------------+---------------------------+------------------------+\n");
      printf (CYAN"| Original Integer  | Reversed Integer          | Palindrome Check       |\n"RESET);
      printf ("+-------------------+---------------------------+------------------------+\n");
      for (int i = 0; i < numTestCases; i++) {
         int overflow;
         int result = ReverseInteger (testCases[i], &overflow);
         PrintIntegerReversalTestCase (testCases[i], result, overflow);
         printf ("+-------------------+---------------------------+------------------------+\n");
      }
   }
   else {
      char input[MAXLENGTH];
      printf ("\nEnter an integer to reverse: ");
      while (getchar () != '\n');  // Discard any leftover characters
      if (fgets (input, sizeof (input), stdin) != NULL) {
         char* endPtr = NULL;
         long int number = strtol (input, &endPtr, 10);
         if (endPtr == NULL || *endPtr != '\0' && *endPtr != '\n') printf (YELLOW"Invalid input.\n"RESET);
         else {
            int overflow;
            int reversed = ReverseInteger ((int)number, &overflow);
            if (overflow) printf ("Reversed Integer: "BLUE"Overflow\n"RESET""YELLOW"Invalid input\n"RESET);
            else {
               char reversedStr[12];
               snprintf (reversedStr, sizeof (reversedStr), "%d", reversed);
               printf ("Reversed Integer: %d\n%s", reversed, PalindromeChecker (reversedStr) ? GREEN"Palindrome"RESET : RED"Not a palindrome"RESET);
            }
         }
      }
      else printf (RED"Error reading input.\n"RESET);
   }
}

int main () {
   int choice;
   while (1) {
      printf ("\nSelect option:\n1. Execute test cases\n2. Enter a phrase or text\n3. Enter an integer to reverse\n4. Exit\nEnter your choice (1, 2, 3, or 4): ");
      if (scanf ("%d", &choice) != 1) {
         while (getchar () != '\n');
         printf (YELLOW"Invalid input. Please enter a number.\n"RESET);
         continue;
      }
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
         printf ("Invalid choice. Please enter 1, 2, 3, or 4.\n");
      }
   }
   return 0;
}