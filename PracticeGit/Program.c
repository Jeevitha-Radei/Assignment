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

#define ERROR_OPEN_FILE -1
#define DIFFERENCE 1
#define TEST_PASS 0
#define OUTPUT_EOF_REACHED 2
#define REFERENCE_EOF_REACHED 3

void PrintBorder (FILE* output, const wchar_t* border) {
   fwprintf (output, L"%s\n", border);
}

void PrintRow (FILE* output, wchar_t* rowPieces) {
   fwprintf (output, L"┃");
   for (int i = 0; i < 8; i++) {
      fwprintf (output, L" %lc ", rowPieces[i]);
      fwprintf (output, L"┃");
   }
   fwprintf (output, L"\n");
}

void PrintChessboard (FILE* output) {
   wchar_t whitePieces[8] =
   { L'\u2656', L'\u2658', L'\u2657', L'\u2654', L'\u2655', L'\u2657', L'\u2658', L'\u2656' },
      blackPieces[8] =
   { L'\u265C', L'\u265E', L'\u265D', L'\u265A', L'\u265B', L'\u265D', L'\u265E', L'\u265C' },
      whitePawn = L'\u2659', blackPawn = L'\u265F';
   const wchar_t* topBorder = L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓",
      * middleBorder = L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫",
      * bottomBorder = L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛";
   PrintBorder (output, topBorder);
   PrintRow (output, blackPieces);
   PrintBorder (output, middleBorder);
   wchar_t blackPawns[8] =
   { blackPawn, blackPawn, blackPawn, blackPawn, blackPawn, blackPawn, blackPawn, blackPawn };
   PrintRow (output, blackPawns);
   PrintBorder (output, middleBorder);
   wchar_t emptyRow[8] = { L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ' };
   for (int i = 0; i < 4; i++) {
      PrintRow (output, emptyRow);
      if (i < 3) PrintBorder (output, middleBorder);
   }
   PrintBorder (output, middleBorder);
   wchar_t whitePawns[8] =
   { whitePawn, whitePawn, whitePawn, whitePawn, whitePawn, whitePawn, whitePawn, whitePawn };
   PrintRow (output, whitePawns);
   PrintBorder (output, middleBorder);
   PrintRow (output, whitePieces);
   PrintBorder (output, bottomBorder);
}

int FileCompare (const char* file1, const char* file2, int* row, int* col) {
   FILE* f1 = fopen (file1, "r, ccs=UTF-8");
   FILE* f2 = fopen (file2, "r, ccs=UTF-8");
   if (!f1 || !f2) {
      perror ("Error opening file");
      return ERROR_OPEN_FILE;
   }
   *row = 1;
   *col = 1;
   wchar_t line1[1024], line2[1024];
   while (fgetws (line1, sizeof (line1) / sizeof (wchar_t), f1) &&
      fgetws (line2, sizeof (line2) / sizeof (wchar_t), f2)) {
      if (wcscmp (line1, line2) != 0) {
         int i = 0;
         while (line1[i] != L'\0' && line2[i] != L'\0' && line1[i] == line2[i]) {
            i++;
            (*col)++;
         }
         if (line1[i] != line2[i]) {
            fclose (f1);
            fclose (f2);
            return DIFFERENCE;
         }
      }
      (*row)++;
      *col = 1;    // Reset column to 1 for the next line
   }
   fclose (f1);
   fclose (f2);                                    
   if (fgetws (line1, sizeof (line1) / sizeof (wchar_t), f1) == NULL &&
      fgetws (line2, sizeof (line2) / sizeof (wchar_t), f2) == NULL) {
      return TEST_PASS;
   }
   return (fgetws (line1, sizeof (line1) / sizeof (wchar_t), f1) == NULL) ?
      REFERENCE_EOF_REACHED : OUTPUT_EOF_REACHED;
}

int main () {
   int k = _setmode (_fileno (stdout), _O_U8TEXT);
   FILE* output = fopen ("Chess.txt", "w, ccs=UTF-8");
   if (!output) {
      perror ("Error opening output file");
      return ERROR_OPEN_FILE;
   }
   PrintChessboard (stdout);
   char choice[10];     // Buffer to store user input
   wprintf (L"\nDo you want to execute the test? (y/n): ");
   fgets (choice, sizeof (choice), stdin);
   choice[strcspn (choice, "\n")] = '\0';
   wprintf (choice[0] == 'y' || choice[0] == 'Y' ? L"Proceeding with the test...\n" :
      (choice[0] == 'n' || choice[0] == 'N' ? L"Test aborted.\n" :
         L"Invalid input. Please enter 'y' or 'n'.\n"));
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
         default: wprintf (L"Unknown error at row %d, col %d\n", row, col); break;
      }
   }
   return 0;
}