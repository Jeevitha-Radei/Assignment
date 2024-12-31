// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Complex.c - Functions for various arithmetic operations on complex numbers.
// ------------------------------------------------------------------------------------------------
#include "Complex.h"
#include <math.h>

ComplexNumber OpAdd (ComplexNumber a, ComplexNumber b) {
   return (ComplexNumber) { a.Real + b.Real, a.Img + b.Img };
}

ComplexNumber OpSub (ComplexNumber a, ComplexNumber b) {
   return (ComplexNumber) { a.Real - b.Real, a.Img - b.Img };
}

ComplexNumber OpMul (ComplexNumber a, ComplexNumber b) {
   return (ComplexNumber) {
      a.Real* b.Real - a.Img * b.Img,
         a.Real* b.Img + a.Img * b.Real
   };
}

float Modulus (ComplexNumber a) {
   return sqrt (a.Real * a.Real + a.Img * a.Img);
}

ComplexNumber Conjugate (ComplexNumber a) {
   return (ComplexNumber) { a.Real, -a.Img };
}