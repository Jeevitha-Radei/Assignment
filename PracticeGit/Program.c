// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "Program.h"

void displayBoard (char board[3][3]) {
   printf ("\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        // printf (" %c ", board[i][j]);
         if (j < 3) printf ("|   ");
      }
      printf ("\n");
      if (i < 3) printf ("|---|---|---|");
   }
   printf ("\n");
}