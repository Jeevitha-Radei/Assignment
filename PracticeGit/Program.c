// -----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -----------------------------------------------------------------------------------------------
// Program.c - Function to print chess board
// Jeevitha R
// -----------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

void print_chessboard () {
   wchar_t whitePieces[6] = { L'\u2656', L'\u2658', L'\u2657', L'\u2654', L'\u2655', L'\u2656' };
   wchar_t blackPieces[6] = { L'\u265C', L'\u265E', L'\u265D', L'\u265A', L'\u265B', L'\u265C' };
   wchar_t whitePawn = L'\u2659';
   wchar_t blackPawn = L'\u265F';
   wchar_t chessboard[8][8] = { 0 };
   for (int i = 0; i < 8; i++) {
      chessboard[0][i] = blackPieces[i % 6];
      chessboard[1][i] = blackPawn;
   }
   for (int i = 0; i < 8; i++) {
      chessboard[6][i] = whitePawn;
      chessboard[7][i] = whitePieces[i % 6];
   }
   for (int i = 2; i < 6; i++)
      for (int j = 0; j < 8; j++) chessboard[i][j] = L' ';
   wprintf (L"%lc", 0x250F);  // Top-left corner
   for (int i = 0; i < 7; i++) wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x2533);  // Horizontal dividers
   wprintf (L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x2513);  // Top-right corner
   for (int row = 0; row < 8; row++) {
      wprintf (L"%lc", 0x2503);  // Left border of the row
      for (int col = 0; col < 8; col++) {
         if (chessboard[row][col] != L' ') wprintf (L" %lc ", chessboard[row][col]);  // Add space around pieces
         else wprintf (L"   ");  // For empty spaces
         wprintf (L"%lc", 0x2503);  // Right border of the cell
      }
      wprintf (L"\n");
      if (row < 7) {      // Divider line after each row
         wprintf (L"%lc", 0x2523);  // Left divider for the row
         for (int k = 0; k < 7; k++)
            wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x254B);  // Inner dividers between cells
         wprintf (L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x252B);  // Right divider for the row
      }
   }
   wprintf (L"%lc", 0x2517);  // Bottom-left corner
   for (int i = 0; i < 7; i++)
      wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x253B);  // Horizontal dividers
   wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x251B);  // Bottom-right corner
}

int main () {
   if (_setmode (_fileno (stdout), _O_U8TEXT) == -1) {
      wprintf (L"Failed to set the output mode to UTF-16.\n");
      return 1;
   }
   if (freopen ("chessboard.txt", "w, ccs=UTF-8", stdout) == NULL) {
      wprintf (L"Failed to redirect stdout to the file.\n");
      return 1;
   }
   print_chessboard ();
   fclose (stdout);
   return 0;
}