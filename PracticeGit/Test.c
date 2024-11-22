// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// test.c
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include "Program.h"

int main () {
   int cashPaid, actualAmount;
   printf ("Enter the cash:");
   scanf_s ("%d", &cashPaid);
   printf ("Enter the Actual amount:");
   scanf_s ("%d", &actualAmount);
   calculateChange (cashPaid, actualAmount);
   return 0;
}