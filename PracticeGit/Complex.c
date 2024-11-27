// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Program.c - Functions for various arithmetic operations on complex numbers.
// ------------------------------------------------------------------------------------------------
#include "Complex.h"
#include <math.h>

ComplexNumber OpAdd (ComplexNumber a, ComplexNumber b) {
   ComplexNumber c;
   c.real = a.real + b.real;
   c.img = a.img + b.img;
   return c;
}

ComplexNumber OpSub (ComplexNumber a, ComplexNumber b) {
   ComplexNumber c;
   c.real = a.real - b.real;
   c.img = a.img - b.img;
   return c;
}

ComplexNumber OpMul (ComplexNumber a, ComplexNumber b) {
   ComplexNumber c;
   c.real = a.real * b.real - a.img * b.img;
   c.img = a.real * b.img + a.img * b.real;
   return c;
}

float Modulus (ComplexNumber a) {
   return sqrt (a.real * a.real + a.img * a.img);
}

ComplexNumber Conjugate (ComplexNumber a) {
   ComplexNumber c;
   c.real = a.real;
   c.img = -a.img;
   return c;
}