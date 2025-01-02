// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// TicTacToe.c - Program to implement a two-player Tic-Tac-Toe game.
// ------------------------------------------------------------------------------------------------
#include "TicTacToe.h"

char board[3][3];
int currentPlayer = 1;
char playerSymbols[] = { 'X', 'O' };

void InitializeBoard () {
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) board[i][j] = ' ';
}

int IsPlayerWon () {
   for (int i = 0; i < 3; i++) {
      if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1; // Check rows
      if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1; // Check columns
   }
   if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1; // Check 1st diagonal
   if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1; // Check 2nd diagonal
   return 0;  // No winner
}

int IsBoardFull () {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++)
         if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
   }
   return 1;  // Board is full
}

void MakeMove (int move) {
   int row = (move - 1) / 3, col = (move - 1) % 3;
   if (board[row][col] == ' ') board[row][col] = playerSymbols[currentPlayer - 1];
}

void SwitchPlayer () {
   currentPlayer = (currentPlayer == 1) ? 2 : 1;  // Switch between Player 1 (X) and Player 2 (O)
}