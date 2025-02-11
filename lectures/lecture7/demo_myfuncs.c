#include <math.h>
#include <stdio.h>

// double sqrtIter(double x, double s) { return 0.5 * (x + s / x); }

int factorial(int x) {
  int acc = 1;
  for (int i = 1; i <= x; i++) {
    acc *= i;
  }
  return acc;
}

double myexp(double x) {
  double acc = 1;
  int i = 1;
  while (1) {
    double acc_old = acc;
    acc += (pow(x, (double)i)) / ((double)factorial(i));
    if (i > 13) {
      break;
    }
    i++;
  }
  return acc;
}

double myln(double x) {
  double s = x;
  int i = 0;
  while (1) {
    double s_old = s;
    s = s - 1 + x * exp(-s);
    if (i > 10) {
      break;
    }
    i++;
  }
  return s;
}

int main() {
  printf("5!: %d\n", factorial(5));
  printf("e^5:\n\tMy exp: %lf\n\tLib exp: %lf\n\n", myexp(5), exp(5));
  printf("ln(3):\n\tMy ln: %lf\n\tLib ln: %lf\n\n", myln(5), log(5));
}
