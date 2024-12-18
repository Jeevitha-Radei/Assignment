// -----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -----------------------------------------------------------------------------------------------
// Program.c - Function to print chess board
// Jeevitha R
// -----------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <ctype.h>

#define TEST_PASS 0
#define OUTPUT_EOF_REACHED 1
#define REFERENCE_EOF_REACHED 2
#define DIFFERENCE 3

/// <summary>Function to print the chessboard to a given output</summary>
void PrintChessboard (FILE* output);

/// <summary>Function to compare two files and provide the exact location of differences</summary>
int FileCompare (const char* file1, const char* file2);

void PrintChessboard (FILE* output) {
   wchar_t whitePieces[8] =
   { L'\u2656', L'\u2658', L'\u2657', L'\u2654', L'\u2655', L'\u2657', L'\u2658', L'\u2656' };
   wchar_t blackPieces[8] =
   { L'\u265C', L'\u265E', L'\u265D', L'\u265A', L'\u265B', L'\u265D', L'\u265E', L'\u265C' };
   wchar_t whitePawn = L'\u2659';
   wchar_t blackPawn = L'\u265F';
   wchar_t chessboard[8][8] = { 0 };
   for (int i = 0; i < 8; i++) {
      chessboard[0][i] = blackPieces[i % 8];
      chessboard[1][i] = blackPawn;
   }
   for (int i = 0; i < 8; i++) {
      chessboard[6][i] = whitePawn;
      chessboard[7][i] = whitePieces[i % 8];
   }
   for (int i = 2; i < 6; i++)
      for (int j = 0; j < 8; j++) chessboard[i][j] = L' ';
   fwprintf (output, L"%lc", 0x250F);  // Top-left corner
   for (int i = 0; i < 7; i++) fwprintf (output, L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x2533);
   fwprintf (output, L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x2513);  // Top-right corner
   for (int row = 0; row < 8; row++) {
      fwprintf (output, L"%lc", 0x2503);  // Left border of the row
      for (int col = 0; col < 8; col++) {
         if (chessboard[row][col] != L' ') fwprintf (output, L" %lc ", chessboard[row][col]);
         else fwprintf (output, L"   ");  // For empty spaces
         fwprintf (output, L"%lc", 0x2503);  // Right border of the cell
      }
      fwprintf (output, L"\n");
      if (row < 7) {
         fwprintf (output, L"%lc", 0x2523);  // Left divider for the row
         for (int k = 0; k < 7; k++) fwprintf (output, L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x254B);
         fwprintf (output, L"%lc%lc%lc%lc\n", 0x2501, 0x2501, 0x2501, 0x252B);  // Right divider for row
      }
   }
   fwprintf (output, L"%lc", 0x2517);  // Bottom-left corner
   for (int i = 0; i < 7; i++) fwprintf (output, L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x253B);
   fwprintf (output, L"%lc%lc%lc%lc", 0x2501, 0x2501, 0x2501, 0x251B);  // Bottom-right corner
}

int FileCompare (const char* file1, const char* file2) {
   FILE* f1 = fopen (file1, "r, ccs=UTF-8");
   FILE* f2 = fopen (file2, "r, ccs=UTF-8");
   if (f1 == NULL || f2 == NULL) {
      perror ("Error opening file");
      return 0;
   }
   int line = 1, col = 1;
   wchar_t ch1 = fgetwc (f1);
   wchar_t ch2 = fgetwc (f2);
   while (ch1 != WEOF || ch2 != WEOF) {
      if (ch1 != ch2) {
         fclose (f1);
         fclose (f2);
         return DIFFERENCE;  // Files are different
      }
      if (ch1 == L'\n' || ch2 == L'\n') {
         line++;
         col = 1;
      }
      else col++;
      ch1 = fgetwc (f1);
      ch2 = fgetwc (f2);
   }
   if (ch1 == WEOF && ch2 == WEOF) {
      fclose (f1);
      fclose (f2);
      return TEST_PASS;  // Both files ended at the same time, they are identical
   }
   if (ch1 == WEOF) {
      fclose (f1);
      fclose (f2);
      return REFERENCE_EOF_REACHED;  // Reference file reached EOF first
   }
   if (ch2 == WEOF) {
      fclose (f1);
      fclose (f2);
      return OUTPUT_EOF_REACHED;  // Output file reached EOF first
   }
   fclose (f1);
   fclose (f2);
   return TEST_PASS;  // Files are identical
}

int main () {
   int k = _setmode (_fileno (stdout), _O_U8TEXT);
   FILE* output = fopen ("Chess.txt", "w, ccs=UTF-8");
   if (!output) {
      perror ("Error opening output file");
      return 1;
   }
   PrintChessboard (stdout);
   char choice[3];  // Buffer to store user input
   wprintf (L"\nDo you want to execute the test? (y/n): ");
   fgets (choice, sizeof (choice), stdin);
   if (choice[strlen (choice) - 1] == '\n') choice[strlen (choice) - 1] = '\0';
   if (choice[0] == 'y' || choice[0] == 'Y') {
      PrintChessboard (output);
      fclose (output);
      int result = FileCompare ("Chess.txt", "chessboardref.txt"), row = 1, col = 1;
      switch (result) {
      case TEST_PASS: wprintf (L"Test Passed\n"); break;
      case OUTPUT_EOF_REACHED:
         wprintf (L"Error at row %d, col %d. Output file reached EOF\n", row, col); break;
      case REFERENCE_EOF_REACHED:
         wprintf (L"Error at row %d, col %d. Reference file reached EOF\n", row, col); break;
      case DIFFERENCE: wprintf (L"Error at row %d, col %d. Files differ\n", row, col); break;
      default:wprintf (L"Unknown error at row %d, col %d\n", row, col); break;
      }
   }
   else wprintf (L"Test aborted.\n");
   return 0;
}