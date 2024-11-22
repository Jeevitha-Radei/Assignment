#include <stdio.h>
#include <io.h>
#include <fcntl.h>

void print_chessboard () {
   // Unicode chess piece characters
   wchar_t whitePieces[6] = { L'\u2656', L'\u2658', L'\u2657', L'\u2654', L'\u2655', L'\u2656' };
   wchar_t blackPieces[6] = { L'\u265C', L'\u265E', L'\u265D', L'\u265A', L'\u265B', L'\u265C' };
   wchar_t whitePawn = L'\u2659';
   wchar_t blackPawn = L'\u265F';

   // Initialize the chessboard
   wchar_t chessboard[8][8] = { 0 };

   // Place black pieces
   for (int i = 0; i < 8; i++) {
      chessboard[0][i] = blackPieces[i % 6];  // Black major pieces (row 0)
      chessboard[1][i] = blackPawn;           // Black pawns (row 1)
   }

   // Place white pieces
   for (int i = 0; i < 8; i++) {
      chessboard[6][i] = whitePawn;           // White pawns (row 6)
      chessboard[7][i] = whitePieces[i % 6];  // White major pieces (row 7)
   }

   // Empty spaces in the middle
   for (int i = 2; i < 6; i++) {
      for (int j = 0; j < 8; j++) {
         chessboard[i][j] = L' ';  // Empty space
      }
   }

   // Print the top border
   wprintf (L"%lc", 0x250F);  // Top-left corner
   for (int i = 0; i < 7; i++) {
      wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x2533);  // Horizontal dividers
   }
   wprintf (L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x2513);  // Top-right corner

   // Print the chessboard with pieces
   for (int row = 0; row < 8; row++) {
      wprintf (L"%lc", 0x2503);  // Left border of the row

      for (int col = 0; col < 8; col++) {
         if (chessboard[row][col] != L' ') {
            wprintf (L" %lc ", chessboard[row][col]);  // Print piece
         }
         else {
            wprintf (L"   ");  // Empty square
         }
         wprintf (L"%lc", 0x2503);  // Right border of the cell
      }

      wprintf (L"\n");

      // Divider line after each row
      if (row < 7) {
         wprintf (L"%lc", 0x2523);  // Left divider for the row
         for (int k = 0; k < 7; k++) {
            wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x254B);  // Inner dividers between cells
         }
         wprintf (L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x252B);  // Right divider for the row
      }
   }

   // Print the bottom border
   wprintf (L"%lc", 0x2517);  // Bottom-left corner
   for (int i = 0; i < 7; i++) {
      wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x253B);  // Horizontal dividers
   }
   wprintf (L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x251B);  // Bottom-right corner
}

int main () {
   // Set the console output to UTF-16 mode
   if (_setmode (_fileno (stdout), _O_U8TEXT) == -1) {
      wprintf (L"Failed to set the output mode to UTF-16.\n");
      return 1;
   }

   // Call the function to print the chessboard
   print_chessboard ();

   return 0;
}
