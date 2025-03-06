#include "eigen.h"
#include "matrix.h"
#include <math.h>
#include <stdio.h>

double RaleightQuotient(matrix *A, double TOL, int MaxIters, vector *v0) {
  matrix I = new_matrix(A->rows, A->cols);
  for (int i = 1; i <= A->cols; i++) {
    for (int j = 1; j <= A->rows; j++) {
      if (i == j) {
        mget(I, i, j) = 1;
      } else {
        mget(I, i, j) = 0;
      }
    }
  }

  double vnorm = vector_norm(v0);
  vector v = vector_div(v0, vnorm);
  vector Av = matrix_vector_mult(A, &v);
  double l = vector_dot_mult(&Av, &v);
  int mstop = 0;
  int k = 0;

  while (mstop == 0) {
    k = k + 1;
    matrix lI = matrix_mult_scalar(&I, l);
    matrix AsublI = matrix_sub(A, &lI);

    vector w = solve(&AsublI, &v);
    v = vector_div(&w, vector_norm(&w));
    Av = matrix_vector_mult(A, &v);
    double l_old = l;
    l = vector_dot_mult(&Av, &v);

    if (fabs(l - l_old) < TOL || k == MaxIters) {
      mstop = 1;
    }
  }
  return l;
}

double PowerIteration(vector *v0, double TOL, int MaxIters, matrix *A) {
  double vnorm = vector_norm(v0);
  vector v = vector_div(v0, vnorm);

  vector Av = matrix_vector_mult(A, &v);
  double l = vector_dot_mult(&Av, &v);

  int mstop = 0;
  int k = 0;
  while (mstop == 0) {
    k = k + 1;
    vector w = matrix_vector_mult(A, &v);
    v = vector_div(&w, vector_norm(&w));

    Av = matrix_vector_mult(A, &v);
    double l_old = l;
    l = vector_dot_mult(&v, &Av);

    if (fabs(l - l_old) < TOL || k == MaxIters) {
      mstop = 1;
    }
  }
  return l;
};

double ShiftedInverseIteration(double u, vector *v0, double TOL, int MaxIters,
                               matrix *A) {
  matrix I = new_matrix(A->rows, A->cols);
  for (int i = 1; i <= A->cols; i++) {
    for (int j = 1; j <= A->rows; j++) {
      if (i == j) {
        mget(I, i, j) = 1;
      } else {
        mget(I, i, j) = 0;
      }
    }
  }
  double vnorm = vector_norm(v0);
  vector v = vector_div(v0, vnorm);

  vector Av = matrix_vector_mult(A, &v);
  double l = vector_dot_mult(&Av, &v);

  int mstop = 0;
  int k = 0;
  while (mstop == 0) {
    k = k + 1;
    matrix uI = matrix_mult_scalar(&I, u);
    matrix AsubuI = matrix_sub(A, &uI);
    vector w = solve(&AsubuI, &v);
    v = vector_div(&w, vector_norm(&w));

    Av = matrix_vector_mult(A, &v);
    double l_old = l;
    l = vector_dot_mult(&v, &Av);
    if (fabs(l - l_old) < TOL || k == MaxIters) {
      mstop = 1;
    }
  }
  return l;
}
