// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// TestTicTacToe.c - Test Program to implement the logic
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TicTacToe.h"

/// <summary>Function to get valid user input using fgets</summary>
int getValidMove ();

/// <summary>Function to display the game board</summary>
void displayBoard ();

int getValidMove () {
   char input[10];
   int move;
   while (1) {
      printf ("Player %d, enter a number (1-9): ", currentPlayer);
      if (fgets (input, sizeof (input), stdin) == NULL) {
         printf ("Error reading input. Please try again.\n");
         continue;
      }
      input[strcspn (input, "\n")] = '\0';  // Remove newline character from input
      char* endptr;
      move = strtol (input, &endptr, 10);
      if (*endptr != '\0' || move < 1 || move > 9) {
         printf ("Invalid input! Please enter a number between 1 and 9.\n");
         continue;
      }
      int row = (move - 1) / 3, col = (move - 1) % 3;
      if (board[row][col] == ' ') return move;  // Valid move
      else printf ("That box is already taken! Please choose another box.\n");
   }
}


void displayBoard () {
   printf ("\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         printf ("%c ", board[i][j]);
         if (j < 2) printf ("| ");
      }
      printf ("\n");
      if (i < 2) printf ("--------\n");
   }
   printf ("\n");
}

int main () {
   int gameOver = 0;
   initializeBoard ();
   displayBoard ();
   while (!gameOver) {
      int move = getValidMove ();
      makeMove (move);
      displayBoard ();
      if (checkWinner ()) {
         printf ("Player %d wins! Hurrahhh!\n", currentPlayer);
         gameOver = 1;
      }
      else if (isBoardFull ()) {
         printf ("It's a draw!\n");
         gameOver = 1;
      }
      if (!gameOver) switchPlayer ();
   }
   return 0;
}