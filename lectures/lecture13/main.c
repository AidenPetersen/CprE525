
#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void generate_points(double *points, int size) {
  double acc = 0;
  for (int i = 0; i < size; i++) {
    points[i] = acc;
    acc += 0.95L / (double)(size - 1);
  }
  return;
}

double sample_poly(double x, double *polynomial, int dim) {
  double y = 0;
  for (int j = 0; j < dim; j++) {
    y += polynomial[j] * pow(x, (double)(j));
  }
  return y;
}

#define N 20
#define M 5

// This function computes the least square approximation of sin(2pix) for 20
// steps between 0-1
int main() {

  double points[N];
  generate_points(points, N);
  vector x = new_vector(N);
  x.val = points;
  vector f = new_vector(N);
  // Matrices
  matrix A = new_matrix(N, M + 1);

  // Initialize A to powers of each x value in points
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M + 1; j++) {
      mget(A, i, j) = pow(vget(x, i), (double)(j - 1));
    }
  }
  // Set f to sin(2pix) for each x in points
  for (int i = 1; i < N; i++) {
    vget(f, i) = sin(2 * 3.1415926535 * vget(x, i));
  }

  // Take transpose of A
  matrix AT = matrix_T(&A);

  // get A^T*A
  matrix ATA = matrix_mult(&AT, &A);

  // get A^T*f
  vector ATf = matrix_vector_mult(&AT, &f);

  // Solve for a in (A^TA)a = (A^Tf)
  vector a = solve(&ATA, &ATf);
  double *poly = a.val;

  for (int i = 0; i < N; i++) {
    printf("%lf %lf\n", points[i], sample_poly(points[i], poly, M + 1));
  }
}
