#ifndef EIGEN_H_
#define EIGEN_H_
#include "matrix.h"

/**
 * INPUT: matrix A(REAL & SYMMETRIC), tolerance TOL, max iterations MaxIters,
 * vector v0 OUTPUT: EIGEN VALUE
 * */
double RaleightQuotient(matrix *A, double TOL, int MaxIters, vector *v0);

/**
 * INPUT: DIAGONALIZABLE MATRIX A, tolerance TOL, max iterations MaxIters,
 * INITIAL VECTOR v0 OUTPUT: EIGEN VALUE
 * */
double PowerIteration(vector *v0, double TOL, int MaxIters, matrix *A);

/**
 * INPUT: u closest eigenvalue approx, matrix A(REAL & SYMMETRIC), tolerance
 * TOL, max iterations MaxIters, vector v0
 * OUTPUT: EIGEN VALUE
 * */
double ShiftedInverseIteration(double u, vector *v0, double TOL, int MaxIters,
                               matrix *A);

#endif // EIGEN_H_
