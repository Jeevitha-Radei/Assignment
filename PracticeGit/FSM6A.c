// -----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -----------------------------------------------------------------------------------------------
// Jeevitha R
// FSM6A.c - FSM state transition implementation in C
// -----------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/// State diagram reference: file://C:/Work/Training24/PracticeGit/Assignment6A.jpg
typedef enum {
   S0,  // Initial state
   S1,  // '0'
   S2,  // '01' or '1101'
   S3,  // '011'
   S4,  // '0110' or '110'
   S5,  // '11'
   S6   // '1'
} State;

///<summary> Function to get the next state and output based on the current state and input. </summary>
State MealyState (State currentState, int input, int* output);

State MealyState (State currentState, int input, int* output) {
   switch (currentState) {
   case S0:
      *output = 0;
      return (input == 0) ? S1 : S6;   // Transition to S1 else S6
   case S1:
      *output = 0;
      return(input == 1) ? S2 : S1;   // Transition to S2 after '01' else S1
   case S2:
      *output = 0;
      return (input == 1) ? S3 : S1;   // Transitions to S3 after '011'
   case S3:
      if (input == 0) {
         *output = 1;   // output '1' upon seeing '0110'
         return S4;   // Transitions to S4
      }
      else {
         *output = 0;
         return S5;   // Transitions to S5 if input is '1'
      }
   case S4:
      if (input == 1) {
         *output = 1;   // output '1' upon seeing '1101'
         return S2;    // Return to S2
      }
      else {
         *output = 0;
         return S1;   // Return to S1 if input is '0'
      }
   case S5:
      *output = 0;
      return(input == 0) ? S4 : S5;   // Transition to S4 else stay in S5
   case S6:
      *output = 0;   // Output '0' and transition to S1 if '0' or S5 if '1'
      return (input == 0) ? S1 : S5;
   default: return S0;   // Default return to initial state
   }
}

int main (int argc, char* argv[]) {
   if (argc != 3) {
      printf ("Usage: %s <input_file> <output_file>\n", argv[0]);
      return 1;
   }
   State currentState = S0;
   int output = 0;
   FILE* inputFile = fopen (argv[1], "r");
   FILE* outputFile = fopen (argv[2], "w");
   if (inputFile == NULL|| outputFile==NULL) {
      perror ("Error opening the file");
      return 1;
   }
   char inputChar;
   printf ("\nReading input from %s...\n", argv[1]);
   while (fscanf (inputFile, "%c", &inputChar) == 1) {
      if (inputChar == '0' || inputChar == '1') {   // Ignore any non '0' or '1' characters (such as newlines, spaces)
         int input = inputChar - '0';   // Convert '0'/'1' char to integer 0/1
         currentState = MealyState (currentState, input, &output);
         fprintf (outputFile, "%d", output);
      }
   }
   printf ("Finished processing input. Output written to %s.\n", argv[2]);
   fclose (inputFile);
   fclose (outputFile);
   return 0;
}