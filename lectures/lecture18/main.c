#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000

#define A 0.0
#define B 1.0

int thread_count = 16;

double f(double x) { return sin(x); }

void gen_pts(double *pts) {
  for (int i = 0; i < N; i++) {
    pts[i] = A + ((B - A) / N * i);
  }
}

int main() {
    double xs[N];
    gen_pts(xs);
    double ss[N];
    double sum = 0;

    // Calculate trapezoids
    #pragma omp parallel num_threads(thread_count)
    for(int i = 0; i < N - 1; i++){
       double a = xs[i];
       double b = xs[i + 1];
       ss[i] = (b-a)/6 * (f(a) + 4*f((a + b) / 2) + f(b));
    }

    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < N - 1; i++){
        sum += ss[i];
    }
    printf("integral %lf -> %lf  sin(x) dx = %lf\n", A, B, sum);

}
