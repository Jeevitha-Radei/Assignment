// -------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------------------------------------------------------------------
// Cash.c - Program to calulate the changes to return
// -------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RESET "\033[0m"   // colour codes
#define GREEN "\033[32m"
#define RED "\033[31m"
#define SUCCESS 1     // Error codes
#define NEGATIVE_VALUE -1
#define INSUFFICIENT_PAYMENT -2

/// <summary>Calculates change, handling errors for negative values or insufficient payment. Returns success.</summary>
int CalculateChange (int cashPaid, int actualAmount, int* denominations, int numDenominations);

int CalculateChange (int cashPaid, int actualAmount, int* denominations, int numDenominations) {
   int change = cashPaid - actualAmount, coinCount[4] = { 0 };
   for (int i = 0; i < numDenominations; i++) {
      coinCount[i] = change / denominations[i];
      change = change % denominations[i];  // Update the remaining change
   }
   printf ("Cash Paid: Rs. %d, Actual Amount: Rs. %d\n", cashPaid, actualAmount);
   if (cashPaid < 0 || actualAmount < 0) {
      printf ("Negative value encountered. Cash Paid and Actual Amount must be non-negative.\n");
      return NEGATIVE_VALUE;
   }
   else if (cashPaid < actualAmount) {
      printf ("Insufficient payment. The remaining amount to be paid: Rs. %d\n", actualAmount - cashPaid);
      return INSUFFICIENT_PAYMENT;
   }
   else if (cashPaid == actualAmount) printf ("No change to be returned.\n");
   else {
      printf ("Cash to be returned: %d\n", cashPaid - actualAmount);
      for (int j = 0; j < numDenominations; j++)
         printf ("No. of Rs. %d coins: %d\n", denominations[j], coinCount[j]);
   }
   return SUCCESS;
}

void RunTestCases (int* denominations, int numDenominations) {
   for (int i = 0; i < 10; i++) {
      int cashPaid = rand () % 1000, actualAmount = rand () % 1000;
      printf ("\nTest Case %d:\n", i + 1);
      int expected = SUCCESS;
      if (cashPaid < actualAmount) expected = INSUFFICIENT_PAYMENT;
      else if (cashPaid < 0 || actualAmount < 0) expected = NEGATIVE_VALUE;
      int result = CalculateChange (cashPaid, actualAmount, denominations, numDenominations);
      (result == expected) ? printf (GREEN"Test Passed\n"RESET) : printf (RED"Test Failed\n"RESET);
   }
}

void GetUserInput (int* denominations, int numDenominations) {
   int cashPaid, actualAmount;
   char input[256];
   printf ("Enter the Cash Paid: ");
   fgets (input, sizeof (input), stdin);
   cashPaid = atoi (input);
   printf ("Enter the Actual Amount: ");
   fgets (input, sizeof (input), stdin);
   actualAmount = atoi (input);
   CalculateChange (cashPaid, actualAmount, denominations, numDenominations);
}

int main () {
   srand (time (0));  // Seed the random number generator
   int denominations[] = { 10, 5, 2, 1 }, choice;
   int numDenominations = sizeof (denominations) / sizeof (denominations[0]);
   char input[256];  // Buffer to store user input
   do {
      printf ("\nSelect Option:\n1. Run Test Cases\n2. Get User Input for Change Calculation\n"
         "3. Exit\nEnter your choice: ");
      fgets (input, sizeof (input), stdin);
      choice = atoi (input);  // Convert the string input to an integer
      switch (choice) {
      case 1:
         RunTestCases (denominations, numDenominations);
         break;
      case 2:
         GetUserInput (denominations, numDenominations);
         break;
      case 3:
         printf ("Exiting...\n");
         break;
      default:
         printf ("Invalid choice. Please try again.\n");
         break;
      }
   } while (choice != 3);  // Keep running until user chooses to exit
   return 0;
}