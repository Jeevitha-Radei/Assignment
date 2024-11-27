// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Complex.h - Complex numbers 
// ------------------------------------------------------------------------------------------------

#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
   float real, img;
} ComplexNumber;

/// <summary> Function to add two complex numbers. </summary>
ComplexNumber OpAdd (ComplexNumber a, ComplexNumber b);

/// <summary> Function to subtract two complex numbers. </summary>
ComplexNumber OpSub (ComplexNumber a, ComplexNumber b);

/// <summary> Function to multiply two complex numbers. </summary>
ComplexNumber OpMul (ComplexNumber a, ComplexNumber b);

/// <summary> Function to compute modulus of a complex number. </summary>
float Modulus (ComplexNumber a);

/// <summary> Function to compute the conjugate of a complex number. </summary>
ComplexNumber Conjugate (ComplexNumber a);

#endif