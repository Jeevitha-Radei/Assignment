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

/// <summary>Calculates change, handling errors for negative values or insufficient payment.Returns success.</summary>
int CalculateChange (int cashPaid, int actualAmt, int* denominations, int numDenom, int* coinCount,
   int* change);

int CalculateChange (int cashPaid, int actualAmt, int* denominations, int numDenom, int* coinCount,
   int* change) {
   *change = cashPaid - actualAmt;  // Calculate the total change
   if (*change < 0) return INSUFFICIENT_PAYMENT;
   int remainingChange = *change;
   for (int i = 0; i < numDenom; i++) {
      coinCount[i] = remainingChange / denominations[i];
      remainingChange = remainingChange % denominations[i];
   }
   if (cashPaid < 0 || actualAmt < 0) return NEGATIVE_VALUE;
   return SUCCESS;
}

void PrintChange (int cashPaid, int actualAmt, int* denominations, int numDenom, int* coinCount, int change) {
   printf ("\nCash Paid: Rs. %d, Actual Amount: Rs. %d\n", cashPaid, actualAmt);
   if (cashPaid < 0 || actualAmt < 0)
      printf ("Negative value encountered. Cash Paid and Actual Amount must be non-negative.\n");
   else if (change < 0)
      printf ("Insufficient payment. The remaining amount to be paid: Rs. %d\n", -change);
   else if (change == 0) printf ("No change to be returned.\n");
   else {
      printf ("Cash to be returned: Rs. %d\n", change);
      for (int j = 0; j < numDenom; j++)
         printf ("No. of Rs. %d coins: %d\n", denominations[j], coinCount[j]);
   }
}

void RunTestCases (int* denominations, int numDenom) {
   for (int i = 0; i < 10; i++) {
      int cashPaid = rand () % 1000, actualAmt = rand () % 1000;
      int coinCount[4] = { 0 }, change = 0, expected = SUCCESS;
      if (cashPaid < actualAmt) expected = INSUFFICIENT_PAYMENT;
      else if (cashPaid < 0 || actualAmt < 0) expected = NEGATIVE_VALUE;
      int result = CalculateChange (cashPaid, actualAmt, denominations, numDenom, coinCount, &change);
      PrintChange (cashPaid, actualAmt, denominations, numDenom, coinCount, change);
      if (result != expected) {
         printf (RED "Test Failed\n" RESET);
         return;
      }
   }printf (GREEN "\nAll Test Cases Passed\n" RESET);
}

void GetUserInput (int* denominations, int numDenominations) {
   int cashPaid, actualAmt;
   char input[256];
   printf ("Enter the Cash Paid: ");
   fgets (input, sizeof (input), stdin);
   cashPaid = atoi (input);
   printf ("Enter the Actual Amount: ");
   fgets (input, sizeof (input), stdin);
   actualAmt = atoi (input);
   int coinCount[4] = { 0 }, change = 0;
   int result = CalculateChange (cashPaid, actualAmt, denominations, numDenominations, coinCount, &change);
   PrintChange (cashPaid, actualAmt, denominations, numDenominations, coinCount, change);
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
         case 1: RunTestCases (denominations, numDenominations); break;
         case 2: GetUserInput (denominations, numDenominations); break;
         case 3: printf ("Exiting...\n"); break;
         default: printf ("Invalid choice. Please try again.\n"); break;
      }
   } while (choice != 3);  // Keep running until user chooses to exit
   return 0;
}