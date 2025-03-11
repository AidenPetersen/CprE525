#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "trimatrix.h"

void fillA(matrix *m) {

  for (int i = 1; i <= m->cols; i++) {
    for (int j = 1; j <= m->rows; j++) {
      mgetp(m, i, j) = 0;
    }
  }

  for (int i = 1; i <= m->cols; i++) {
    for (int j = i; j <= m->rows; j++) {
      mgetp(m, j, i) = (double)rand() / (double)(RAND_MAX) * 1;
    }
  }
}

int main() {
    matrix L = new_matrix(6,6);
    fillA(&L);
    matrix LT = matrix_T(&L);
    matrix A = matrix_mult(&L, &LT);

    trimatrix T = new_trimatrix(6);
    Hessenberg(&A, &T);

    printf("Symmetric A:\n");
    print_matrix(&A);

    printf("Tridiagonal Hessenberg T:\n");
    print_trimatrix(&T);

    // QR to find eigenvalues of T (same as A)
    QRA(&T);
    printf("Diagonal QR w/ Eigenvalues:\n");
    print_trimatrix(&T);
}
