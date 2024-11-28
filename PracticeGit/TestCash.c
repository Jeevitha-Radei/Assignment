// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// TestCash.c - Testcases to handle various scenerios
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Cash.h"

int main () {
   srand (time (0));   // Seed the random number generator
   int testCases[10][2] = {
       {0, 0},
       {500, 500},
       {-100, 200},
       {200, -100},
       {1000000, 500000},
       {500, 1000},
       {rand () % 1000, rand () % 1000},
       {rand () % 1000, rand () % 1000},
       {rand () % 1000, rand () % 1000},
       {rand () % 1000, rand () % 1000}
   };
   for (int i = 0; i < 10; i++) {
      int cashPaid = testCases[i][0];
      int actualAmount = testCases[i][1];
      int change = 0;
      int coinCount[4] = { 0 };
      printf ("Test Case %d:\nCash Paid: Rs. %d, Actual Amount: Rs. %d\n", i + 1, cashPaid, actualAmount);
      calculateChange (cashPaid, actualAmount, &change, coinCount);
      if (cashPaid < 0 || actualAmount < 0)
         printf ("Expected: Negative value encountered. Cash Paid and Actual Amount must be non-negative.\n"
            "Result: % s\n", (change == -1) ? "Passed" : "Failed");
      else if (cashPaid == actualAmount)
         printf ("Expected: No change to be returned.\nResult: %s\n", (change == 0) ? "Passed" : "Failed");
      else if (change < 0)
         printf ("Expected: Remaining amount to be paid: Rs. %d\nResult: %s\n", -change,
            (change < 0) ? "Passed" : "Failed");
      else {
         int expectedCoinCount[4] = { 0 }, expectedChange = cashPaid - actualAmount;
         calculateChange (cashPaid, actualAmount, &expectedChange, expectedCoinCount);
         int pass = 1;
         for (int i = 0; i < 4; i++) {
            if (coinCount[i] != expectedCoinCount[i]) {
               pass = 0;
               break;
            }
         }
         if (pass) {
            printf ("Expected: Cash to be returned\nNo. of Rs.10 coins: %d\nNo. of Rs.5 coins: %d\n"
               "No. of Rs.2 coins: %d\nNo. of Rs.1 coins: %d\nResult: Passed\n",
               coinCount[0], coinCount[1], coinCount[2], coinCount[3]);
         }
         else printf ("Result: Failed\n");
      }
      printf ("\n");
   }
   return 0;
}