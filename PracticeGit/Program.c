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
#define ERROR_OPEN_FILE -1

/// <summary>Function to print the chessboard to a given output</summary>
void PrintChessboard (FILE* output);

/// <summary>Function to compare two files and provide the exact location of differences</summary>
int FileCompare (const char* file1, const char* file2, int* row, int* col);

void PrintChessboard (FILE* output) {
   wchar_t whitePieces[8] =
   { L'\u2656', L'\u2658', L'\u2657', L'\u2654', L'\u2655', L'\u2657', L'\u2658', L'\u2656' },
      blackPieces[8] =
   { L'\u265C', L'\u265E', L'\u265D', L'\u265A', L'\u265B', L'\u265D', L'\u265E', L'\u265C' },
      whitePawn = L'\u2659', blackPawn = L'\u265F', chessboard[8][8] = { 0 };
   for (int i = 0; i < 8; i++) {
      chessboard[0][i] = blackPieces[i % 8];
      chessboard[1][i] = blackPawn;
      chessboard[6][i] = whitePawn;
      chessboard[7][i] = whitePieces[i % 8];
   }
   for (int i = 2; i < 6; i++)
      for (int j = 0; j < 8; j++) chessboard[i][j] = L' ';
   fwprintf (output, L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");    // Printing top border
   for (int row = 0; row < 8; row++) {    // Printing rows of the chessboard
      fwprintf (output, L"┃");   // Left border of the row
      for (int col = 0; col < 8; col++) {
         if (chessboard[row][col] != L' ') fwprintf (output, L" %lc ", chessboard[row][col]);
         else fwprintf (output, L"   ");    // For empty spaces
         fwprintf (output, L"┃");   // Right border of the cell
      } fwprintf (output, L"\n");
      if (row < 7)  fwprintf (output, L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
   } fwprintf (output, L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}

int FileCompare (const char* file1, const char* file2, int* row, int* col) {
   FILE* f1 = fopen (file1, "r, ccs=UTF-8");
   FILE* f2 = fopen (file2, "r, ccs=UTF-8");
   if (!f1 || !f2) {
      perror ("Error opening file");
      return ERROR_OPEN_FILE;  // failure in opening file
   }
   *row = *col = 1;
   wchar_t ch1 = fgetwc (f1), ch2 = fgetwc (f2);
   while (ch1 != WEOF && ch2 != WEOF) {
      if (ch1 != ch2) {
         fclose (f1);
         fclose (f2);
         return DIFFERENCE;
      }
      if (ch1 == L'\n' || ch2 == L'\n') {
         (*row)++;
         *col = 1;
      }
      else (*col)++;
      ch1 = fgetwc (f1);
      ch2 = fgetwc (f2);
   }
   fclose (f1);
   fclose (f2);
   if (ch1 == WEOF && ch2 == WEOF) {
      fclose (f1);
      fclose (f2);
      return TEST_PASS;
   }
   return (ch1 == WEOF) ? REFERENCE_EOF_REACHED : OUTPUT_EOF_REACHED;
}

int main () {
   int k = _setmode (_fileno (stdout), _O_U8TEXT);
   FILE* output = fopen ("Chess.txt", "w, ccs=UTF-8");
   if (!output) {
      perror ("Error opening output file");
      return ERROR_OPEN_FILE;
   }
   PrintChessboard (stdout);
   char choice[10];  // Buffer to store user input
   wprintf (L"\nDo you want to execute the test? (y/n): ");
   fgets (choice, sizeof (choice), stdin);
   choice[strcspn (choice, "\n")] = '\0';
   if (choice[0] == 'y' || choice[0] == 'Y') {
      PrintChessboard (output);
      fclose (output);
      int row, col, result = FileCompare ("Chess.txt", "chessboardref.txt", &row, &col);
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
   else if (choice[0] == 'n' || choice[0] == 'N') wprintf (L"Test aborted.\n");
   else wprintf (L"Invalid input. Please enter 'y' or 'n'.\n");
   return 0;
}