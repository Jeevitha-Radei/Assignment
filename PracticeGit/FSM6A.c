// -----------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -----------------------------------------------------------------------------------------------
// Jeevitha R
// FSM6A.c - FSM state transition implementation in C
// -----------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ERROR_FILE_OPEN 2
#define ERROR_INVALID_ARG 3
#define ERROR_INVALID_INPUT 4
#define MAX_OUTPUT_SIZE 1000

typedef enum {
   S0,  // Initial state
   S1,  // '0'
   S2,  // '01' or '1101'
   S3,  // '011'
   S4,  // '0110' or '110'
   S5,  // '11'
   S6,  // '1'
} State;

///<summary>Function to get the next state and output based on the current state and input.</summary>
State MealyState (State currentState, int input, int* output);

State MealyState (State currentState, int input, int* output) {
   switch (currentState) {
   case S0:
      *output = 0;
      return (input == 0) ? S1 : S6;   // Transition to S1 else S6
   case S1:
      *output = 0;
      return (input == 1) ? S2 : S1;   // Transition to S2 after '01' else S1
   case S2:
      *output = 0;
      return (input == 1) ? S3 : S1;   // Transitions to S3 after '011'
   case S3:
      *output = !input;  // output '1' on '0110', else '0'
      return (input == 0) ? S4 : S5;   // Transitions to S4 if input is '0', else S5
   case S4:
      *output = input;  // output '1' on '1101', else '0'
      return (input == 1) ? S2 : S1;   // Return to S2 if input is '1', else S1
   case S5:
      *output = 0;
      return (input == 0) ? S4 : S5;   // Transition to S4 else stay in S5 
   case S6:
      *output = 0;
      return (input == 0) ? S1 : S5; 
   default:
      *output = 0;
      return S0;  // Default return to initial state
   }
}

int main (int argc, char* argv[]) {
   if (argc != 3) {
      printf ("Usage: %s <input_file> <output_file>\n", argv[0]);
      return ERROR_INVALID_ARG;
   }
   State currentState = S0;
   int output = 0;
   FILE* inputFile = fopen (argv[1], "r");
   FILE* outputFile = fopen (argv[2], "w");
   if (inputFile == NULL || outputFile == NULL) {
      perror ("Error opening the file");
      return ERROR_FILE_OPEN;
   }
   char outputBuffer[MAX_OUTPUT_SIZE], inputChar;
   int outputIndex = 0;
   while (fscanf (inputFile, "%c", &inputChar) == 1) {
      if (inputChar == '0' || inputChar == '1') {
         int input = inputChar - '0';
         currentState = MealyState (currentState, input, &output);
         outputBuffer[outputIndex++] = output + '0';  // Store output as char
      } else  currentState = MealyState (currentState, 0, &output);  // Handle invalid chars
   }
   if (outputIndex > 0) {
      outputBuffer[outputIndex] = '\0';  // Null-terminate the string
      fprintf (outputFile, "%s", outputBuffer);  // Write the output to file
   }
   printf ("Finished processing input. Output written to %s.\n", argv[2]);
   fclose (inputFile);
   fclose (outputFile);
   return 0;
}