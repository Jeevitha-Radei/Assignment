// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// TicTacToe.h - Header for C file  
// Jeevitha R
// ------------------------------------------------------------------------------------------------
#ifndef TICTACTOE_H
#define TICTACTOE_H

extern char board[3][3];  // 3x3 board for the game
extern int currentPlayer;  // 1 for player X, 2 for player O
extern char playerSymbols[];  // Array to hold player symbols

/// <summary>Function to initialize the game board with empty spaces</summary>
void InitializeBoard ();

/// <summary>Function to check if the current player has won</summary>
int IsPlayerWon ();

/// <summary>Function to check if the board is full (a draw)</summary>
int IsBoardFull ();

/// <summary>Function to make a move for the current player</summary>
void MakeMove (move);

/// <summary>Function to switch the current player</summary>
void SwitchPlayer ();

#endif