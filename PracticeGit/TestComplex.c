// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Testomplex.c -  Program to perform arithmetic operations on complex numbers.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include "Complex.h"

 // Function to print complex numbers
void PrintComplex (ComplexNumber c);

// Function to compare both values
int CompareComplex (ComplexNumber result, float expectedReal, float expectedImg);

// Function to run the test cases
void RunTestCases ();

void PrintComplex (ComplexNumber c) {
   if (c.img >= 0) printf ("%.2f + %.2fi\n", c.real, c.img);
   else printf ("%.2f - %.2fi\n", c.real, -c.img);
}

int CompareComplex (ComplexNumber result, float expectedReal, float expectedImg) {
   return (result.real == expectedReal && result.img == expectedImg);
}

void RunTestCases () {
   ComplexNumber input[] = { {3.0, 7.0}, {4.0, -3.0} };
   float expected[] = { 7.00, 4.00, -1.00, 10.00, 33.00, 19.00, 7.62, 3.00, -7.00 };
   printf ("Running Additon Test...\n");
   ComplexNumber resultAdd = OpAdd (input[0], input[1]);
   printf ("Expected: %.2f + %.2fi\n", expected[0], expected[1]);
   printf ("Result: ");
   PrintComplex (resultAdd);
   printf ("%s\n\n", (CompareComplex (resultAdd, expected[0], expected[1])) ? "Passed" : "Failed");
   printf ("Running Subtraction Test...\n");
   ComplexNumber resultSub = OpSub (input[0], input[1]);
   printf ("Expected: %.2f + %.2fi\n", expected[2], expected[3]);
   printf ("Result: ");
   PrintComplex (resultSub);
   printf ("%s\n\n", (CompareComplex (resultSub, expected[2], expected[3])) ? "Passed" : "Failed");
   printf ("Running Multiply Test...\n");
   ComplexNumber resultMul = OpMul (input[0], input[1]);
   printf ("Expected: %.2f + %.2fi\n", expected[4], expected[5]);
   printf ("Result: ");
   PrintComplex (resultMul);
   printf ("%s\n\n", (CompareComplex (resultMul, expected[4], expected[5])) ? "Passed" : "Failed");
   printf ("Running Modulus Test...\n");
   float modResult = Modulus (input[0]);
   printf ("Expected: %.2f\n", expected[6]);
   printf ("Result: %.2f\n", modResult);
   float epsilon = 0.01;
   printf ("%s\n\n", (fabs (modResult - expected[6]) < epsilon) ? "Passed" : "Failed");
   printf ("Running Conjugate Test...\n");
   ComplexNumber resultConj = Conjugate (input[0]);
   printf ("Expected: %.2f + %.2fi\n", expected[7], expected[8]);
   printf ("Result: ");
   PrintComplex (resultConj);
   printf ("%s\n\n", CompareComplex (resultConj, expected[7], expected[8]) ? "Passed" : "Failed");
}

void GetUserInput () {
   ComplexNumber A, B;
   printf ("Enter the real part and imaginary part of the first complex number: ");
   scanf_s ("%f %f", &A.real, &A.img);
   printf ("Enter the real part and imaginary part of the second complex number: ");
   scanf_s ("%f %f", &B.real, &B.img);
   printf ("\nAddition: ");
   PrintComplex (OpAdd (A, B));
   printf ("\nSubtraction: ");
   PrintComplex (OpSub (A, B));
   printf ("\nMultiplication: ");
   PrintComplex (OpMul (A, B));
   printf ("\nModulus of A: %.2f\n", Modulus (A));
   printf ("\nConjugate of A: ");
   PrintComplex (Conjugate (A));
}

int main () {
   int choice, operationChoice;
   do {
      printf ("\nSelect an option:\n1. Run Test Cases\n2. Complex Number Operations\n3. Exit\nEnter your choice (1-3): ");
      scanf_s ("%d", &choice);
      switch (choice) {
      case 1:
         RunTestCases ();
         break;
      case 2:
         GetUserInput ();
         break;
      case 3:
         printf ("Exiting the program.\n");
         break;
      default:
         printf ("Invalid choice! Please enter a number between 1 and 3.\n");
         break;
      }
   } while (choice != 3);  // Continue until the user chooses to exit
   return 0;
}