// -------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------------------------------------------------------------------
// Cash.c - Program to calulate the changes to return
// -------------------------------------------------------------------------------------------------
#include "Cash.h"

void calculateChange (int cashPaid, int actualAmount, int* change, int* coinCount) {
   if (cashPaid < 0 || actualAmount < 0) {
      *change = -1;
      return;
   }
   *change = cashPaid - actualAmount;
   if (*change < 0) return;
   int denominations[] = { 10, 5, 2, 1 };
   for (int i = 0; i < 4; i++) {
      coinCount[i] = *change / denominations[i];
      *change = *change % denominations[i];
   }
}