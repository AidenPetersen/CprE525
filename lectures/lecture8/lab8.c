#include <math.h>
#include <stdio.h>

int factorial(int n) {
  if (n < 0) {
    printf("Input must be non-negative");
    return -1;
  }
  if (n == 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

double myexp(double x) {
  double e = 2.718281828459;
  double x0 = (double)((int)x);
  double int_pow = pow(e, x0);
  double dec = x - x0;

  double acc = 1;
  int i = 1;
  while (1) {
    double acc_old = acc;
    acc += (pow(dec, (double)i)) / ((double)factorial(i));
    if (i > 13) {
      break;
    }
    i++;
  }
  return acc * int_pow;
}

void generate_points(double *points, int size) {
  double acc = 0;
  for (int i = 0; i < size; i++) {
    points[i] = acc;
    acc += 1.0L / (double)(size - 1);
  }
  return;
}

int main() {
  FILE *output;
  output = fopen("output.txt", "w");
  int size = 51;
  double points[51];
  generate_points(points, size);
  for (int i = 0; i < size; i++) {
    fprintf(output, "%lf,%lf\n", points[i], myexp(points[i]));
  }
}
