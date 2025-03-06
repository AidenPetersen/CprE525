#include "eigen.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void fillA(matrix *m) {

  for (int i = 1; i <= m->cols; i++) {
    for (int j = 1; j <= m->rows; j++) {
      mgetp(m, i, j) = 0;
    }
  }

  for (int i = 1; i <= m->cols; i++) {
    for (int j = i; j <= m->rows; j++) {
      mgetp(m, j, i) = (double)rand() / (double)(RAND_MAX) * 100;
    }
  }
}
void fillv(vector *v) {
  for (int i = 1; i <= v->size; i++) {
    vgetp(v, i) = (double)rand() / (double)(RAND_MAX) * 100;
  }
}

int main() {
  matrix A = new_matrix(4, 4);
  vector v = new_vector(4);
  fillA(&A);
  fillv(&v);
  print_matrix(&A);
  print_vector(&v);
  double evRQ = RaleightQuotient(&A, 1e-10, 5, &v);
  printf("Raleight Quotient: %lf\n", evRQ);

  double evPI = PowerIteration(&v, 1e-10, 1000, &A);
  printf("Power Iteration: %lf\n", evPI);

  double evSI = ShiftedInverseIteration(5, &v, 1e-10, 1000, &A);
  printf("Inverse Shift Power Iteration: %lf\n", evSI);
}
