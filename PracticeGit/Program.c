// -------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------------------------------------------------------------------
// Program.c
// -------------------------------------------------------------------------------------------------

#include <stdio.h>
#include "Program.h"

void calculateChange (int cashPaid, int actualAmount) {
   int change = cashPaid - actualAmount;
   int denominations[] = { 10,5,2,1 };
   int coinCount[4] = { 0 };
   if (change < 0) {
      printf ("Cash Paid is less than the Actual Amount\n");
      return;
   }
   if (change == 0) {
      printf ("No change to be returned\n");
      return;
   }
   for (int i = 0; i < 4; i++) {
      coinCount[i] = change / denominations[i];
      change = change % denominations[i];
   }
   printf ("Cash to be returned\n");
   printf ("No. of Rs.10 coins returned: %d\n", coinCount[0]);
   printf ("No. of Rs.5 coins returned: %d\n", coinCount[1]);
   printf ("No. of Rs.2 coins returned: %d\n", coinCount[2]);
   printf ("No. of Rs.1 coins returned: %d\n", coinCount[3]);
}