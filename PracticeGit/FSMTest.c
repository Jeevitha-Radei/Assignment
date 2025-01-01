// -----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -----------------------------------------------------------------------------------------------
// FSMtest.c
// -----------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define NTESTS 6

/// <summary> Function to execute the FSM program with provided file paths. </summary>
int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName);

/// <summary>Compares two files, ignoring spaces & newlines and reports the mismatch.</summary>
int CompareFiles (const char* file1, const char* file2);

int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName) {
   char* cmdline = malloc (strlen (exeFilePathAndName) + strlen (inputFilePathAndName) + strlen (outputFilePathAndName) + 3);
   if (cmdline == NULL) {
      printf ("Unable to allocate memory\n");
      return 1;
   }
   sprintf (cmdline, "%s %s %s", exeFilePathAndName, inputFilePathAndName, outputFilePathAndName);
   STARTUPINFOA si;
   PROCESS_INFORMATION pi;
   ZeroMemory (&si, sizeof (si)), si.cb = sizeof (si);
   ZeroMemory (&pi, sizeof (pi));
   if (!CreateProcessA (NULL, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
      int err = GetLastError ();
      printf ("Failed to start process. Error: %lu\n", err);
      free (cmdline);
      return 1;
   }
   WaitForSingleObject (pi.hProcess, INFINITE);
   CloseHandle (pi.hProcess);
   CloseHandle (pi.hThread);
   free (cmdline);
   return 0;
}

void closeFiles (FILE* f1, FILE* f2) {
   if (f1) fclose (f1);  // Close the first file if it's open
   if (f2) fclose (f2);  // Close the second file if it's open
}

int CompareFiles (const char* file1, const char* file2) {
   FILE* f1 = fopen (file1, "r");  // Open file1 for reading
   FILE* f2 = fopen (file2, "r");  // Open file2 for reading
   if (!f1 || !f2) {  // If any file fails to open
      printf ("Error opening one or both files.\n");
      return 0;  // Return 0 meaning files are not identical
   }
   fseek (f1, 0, SEEK_END);  //Check if the file sizes are the same
   fseek (f2, 0, SEEK_END);
   long size1 = ftell (f1);
   long size2 = ftell (f2);
   if (size1 != size2) {  // If file sizes are different
      printf ("Files have different sizes: %ld vs %ld\n", size1, size2);
      closeFiles (f1, f2);
      return 0;  // Return 0 because they can't be identical
   }
   rewind (f1);   //Compare the contents character by character
   rewind (f2);
   int char1, char2;
   while ((char1 = fgetc (f1)) != EOF && (char2 = fgetc (f2)) != EOF) {  // Read one character from each file
      if (char1 != char2) {  // If the characters are different
         printf ("Files differ at character: '%c' vs '%c'\n", char1, char2);
         closeFiles (f1, f2);
         return 0;  // Files are not identical, return 0
      }
   }
   closeFiles (f1, f2);
   return 1;  // Files are identical, return 1
}

int main (int argc, char** argv) {
   printf ("FSM Test Harness\n");
   if (argc != 2) {
      printf ("Usage: %s <FSM executable name>\n", argv[0]);
      return -1;
   }
   const char* inputFiles[] = {
       "TData/test1in.txt", "TData/test2in.txt", "TData/test3in.txt", "TData/test4in.txt", "TData/test5in.txt", "TData/test6in.txt"
   };
   const char* expectedOutputFiles[] = {
       "TData/test1out.txt", "TData/test2out.txt", "TData/test3out.txt", "TData/test4out.txt", "TData/test5out.txt", "TData/test6out.txt"
   };
   const char* outputFile = "TData/testOutput.txt";
   FILE* outFile = fopen (outputFile, "a");
   if (!outFile) {
      printf ("Error opening output file for appending\n");
      return 1;
   }
   fclose (outFile);  // Close the file after the check, it will be opened again when writing the output
   for (int i = 0; i < NTESTS; i++) {
      const char* inputFile = inputFiles[i];
      const char* expectedOutputFile = expectedOutputFiles[i];
      if (ExecProgram (argv[1], (char*)inputFile, (char*)outputFile)) {
         printf ("\nError executing test %d\n", i + 1);
         return 1;  // Exit immediately if execution fails
      }
      else if (!CompareFiles (outputFile, expectedOutputFile)) {
         printf ("\nTest %d failed at output for %s\n", i + 1, inputFile);
         return 1;  // Exit immediately on failure
      }
   }
   printf ("All test cases passed.\n");
   return 0;
}