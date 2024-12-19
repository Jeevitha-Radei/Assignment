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
      if (ch1 == EOF || ch2 == EOF)  break;   // If either file has ended, break out of the loop
      if (ch1 == '\n' || ch1 == ' ')  continue;
      if (ch2 == '\n' || ch2 == ' ')  continue;
      if (ch1 != ch2) {   // Compare the characters
         printf ("Error at bit no. %d, Expected %c, Actual %c\n", bitNum, ch2, ch1);
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
       "test1in.txt", "test2in.txt", "test3in.txt", "test4in.txt", "test5in.txt", "test6in.txt"
   };
   for (int i = 0; i < NTESTS; i++) {
      const char* inputFile = inputFiles[i];
      char expectedOutputFile[256];         // Construct the expected reference output file name
      snprintf (expectedOutputFile, sizeof (expectedOutputFile), "test%dout.txt", i + 1);
      char generatedOutputFile[256];       // Construct the generated output file name
      snprintf (generatedOutputFile, sizeof (generatedOutputFile), "test%dactl.txt", i + 1);
      if (ExecProgram (argv[1], (char*)inputFile, generatedOutputFile) != 0) printf ("\nError executing test %d\n", i + 1);
      else printf (compareFiles (generatedOutputFile, expectedOutputFile) ? "\nNo error testing %s\n" : "\nError comparing output for %s\n", inputFile);
   }
   return 0;
}