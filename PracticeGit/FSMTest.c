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
int compareFiles (const char* file1, const char* file2);

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

int compareFiles (const char* file1, const char* file2) {
   printf ("Comparing files: %s and %s\n", file1, file2);
   FILE* f1 = fopen (file1, "r");
   FILE* f2 = fopen (file2, "r");
   if (!f1 || !f2) {
      printf ("Error: One or more files could not be opened.\n");
      return 0;
   }
   int bitNum = 1;
   while (1) {
      int ch1 = fgetc (f1);
      int ch2 = fgetc (f2);
      if (ch1 == EOF || ch2 == EOF) break;   // If either file has ended, break out of the loop
      if (ch1 == '\n' || ch1 == ' ') continue;
      if (ch2 == '\n' || ch2 == ' ') continue;
      if (ch1 != ch2) {   // Compare the characters
         printf ("Error at bit no. %d, Expected %c (0x%x), Actual %c (0x%x)\n", bitNum, ch2, ch2, ch1, ch1);
         fclose (f1);
         fclose (f2);
         return 0;
      }
      bitNum++;
   }
   fclose (f1);
   fclose (f2);
   return 1;  // Files are identical (no differences)
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
      else {
         if (!compareFiles (outputFile, expectedOutputFile)) {
            printf ("\nTest %d failed at output for %s\n", i + 1, inputFile);
            return 1;  // Exit immediately on failure
         }
      }
   }
   printf ("All test cases passed.\n");
   return 0;
}