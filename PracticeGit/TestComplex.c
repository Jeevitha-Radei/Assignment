// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Testomplex.c -  Program to perform arithmetic operations on complex numbers.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include "Complex.h"

/// <summary>Function to check if two floats are approximately equal</summary>
int CompareFloat (float a, float b, float epsilon);

/// <summary>Function to compute the expected values for the operations</summary>
void ComputeExpectedValues (ComplexNumber a, ComplexNumber b, float* expected);

/// <summary>Function to compare two complex numbers</summary>
int CompareComplex (ComplexNumber result, float expectedReal, float expectedImg);

int CompareFloat (float a, float b, float epsilon) {
   return fabs (a - b) < epsilon;
}

void ComputeExpectedValues (ComplexNumber a, ComplexNumber b, float* expected) {
   expected[0] = a.Real + b.Real;   // Addition
   expected[1] = a.Img + b.Img;
   expected[2] = a.Real - b.Real;   // Subtraction
   expected[3] = a.Img - b.Img;
   expected[4] = a.Real * b.Real - a.Img * b.Img;   // Multiplication
   expected[5] = a.Real * b.Img + a.Img * b.Real;
   expected[6] = sqrt (a.Real * a.Real + a.Img * a.Img);   // Modulus
   expected[7] = a.Real;   // Conjugate 
   expected[8] = -a.Img;
}

void PrintComplex (ComplexNumber c) {
   printf ("%.2f %s %.2fi\n", c.Real, (c.Img >= 0) ? "+" : "-", fabs (c.Img));
}

int CompareComplex (ComplexNumber result, float expectedReal, float expectedImg) {
   return (fabs (result.Real - expectedReal) < 0.01 && fabs (result.Img - expectedImg) < 0.01);
}

int CheckModulusTestResult (const char* testName, float result, float expected, float epsilon) {
   if (!CompareFloat (result, expected, epsilon)) {
      printf ("Test Failed for %s!\n", testName);
      return 0;
   }
   return 1;  // Return 1 for success
}

int CheckTestResult (const char* testName, ComplexNumber result, float expectedReal, float expectedImg) {
   if (!CompareComplex (result, expectedReal, expectedImg)) {
      printf ("Test Failed for %s!\n", testName);
      return 0;
   }
   return 1;  // Return 1 for success
}

void RunTestCases () {
   ComplexNumber input[] = { {3.0, 7.0}, {4.0, -3.0} };
   float expected[9], epsilon = 0.01;
   ComplexNumber a, b;
   for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
         a = input[i];
         b = input[j];
         printf ("\nRunning tests for Complex %.2f + %.2fi and Complex %.2f %s %.2fi...\n",
            a.Real, a.Img, b.Real, (b.Img >= 0) ? "+" : "-", fabs (b.Img));
         ComputeExpectedValues (a, b, expected);
         ComplexNumber (*operations[])(ComplexNumber, ComplexNumber) = { OpAdd, OpSub, OpMul };
         const char* operationNames[] = { "Addition", "Subtraction", "Multiplication" };
         for (int k = 0; k < 3; k++) {
            printf ("\nPerforming %s:\n", operationNames[k]);
            ComplexNumber result = operations[k] (a, b);
            printf ("Expected: %.2f %s %.2fi\nResult: ", expected[2 * k], (expected[2 * k + 1] >= 0)
               ? "+" : "-", fabs (expected[2 * k + 1]));
            PrintComplex (result);
            if (!CheckTestResult (operationNames[k], result, expected[2 * k], expected[2 * k + 1])) return;
         }
         printf ("\nRunning Modulus Test for Complex %.2f + %.2fi...\n", a.Real, a.Img);
         float modResult = Modulus (a);
         printf ("Expected: %.2f\nResult: %.2f\n", expected[6], modResult);
         if (!CheckModulusTestResult ("Modulus", modResult, expected[6], epsilon)) return;
         printf ("\nRunning Conjugate Test for Complex %.2f + %.2fi...\n", a.Real, a.Img);
         ComplexNumber resultConj = Conjugate (a);
         printf ("Expected: %.2f %s %.2fi\nResult: ", expected[7], (expected[8] >= 0) ? "+" : "-", fabs (expected[8]));
         PrintComplex (resultConj);
         if (!CheckTestResult ("Conjugate", resultConj, expected[7], expected[8])) return;
      }
   }
   printf ("\nAll tests passed successfully!\n");
}

int main () {
   RunTestCases ();
   return 0;
}