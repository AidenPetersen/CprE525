#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

double xs[SIZE];
double ys[SIZE];
double c0[] = {1.0};
double c1[] = {0, 1.0};
double c2[] = {-1, 0, 2};
double c3[] = {0, -3, 0, 4};
double c4[] = {1, 0, -8, 0, 8};
double c5[] = {0, 5, 0, -20, 0, 16};

double sample_poly(double x, double *polynomial, int dim) {
  double y = 0;
  for (int j = 0; j < dim; j++) {
    y += polynomial[j] * pow(x, (double)j);
  }
  return y;
}

double chebyshev(int n, double x) {
  double y = 0;
  switch (n) {
  case 5:
    y += sample_poly(x, c5, 6);
  case 4:
    y += sample_poly(x, c4, 5);
  case 3:
    y += sample_poly(x, c3, 4);
  case 2:
    y += sample_poly(x, c2, 3);
  case 1:
    y += sample_poly(x, c1, 2);
  case 0:
    y += sample_poly(x, c0, 1);
    break;
  default:
    printf("INVALID N TOO BIG OR SMALL");
    exit(1);
  }
  return y;
}

void load_out(int n) {
  for (int i = 0; i < SIZE; i++) {
    xs[i] = (double)i / 20;
    ys[i] = chebyshev(n, xs[i]);
  }
}

int main(int argc, char *argv[]) {
  int N = atoi(argv[1]);
  load_out(N);
  FILE *fp = fopen("chebyshev.txt", "w");
  for (int i = 0; i < SIZE; i++) {
    fprintf(fp, "%lf,%lf\n", xs[i], ys[i]);
  }
  fclose(fp);
  return system("python3 viz.py");
}
