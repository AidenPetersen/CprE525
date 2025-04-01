#include <math.h>
#include <omp.h>
#include <stdio.h>
#define N 100000

int thread_count = 1;

void init_vec(double *v) {
  for (int i = 0; i < N; i++) {
    v[i] = 1;
  }
}

int main() {
  double vec[N];
  init_vec(vec);

  for (int thread_count = 1; thread_count < 17; thread_count *= 2) {
    // 2NORM FINE
    double sum = 0;
    double vecf2[N];
    init_vec(vecf2);
    const double t1 = omp_get_wtime();
#pragma omp parallel for reduction(+ : sum) num_threads(thread_count)
    for (int i = 0; i < N; i++) {
      sum += vec[i] * vec[i];
    }
    sum = sqrt(sum);
#pragma omp parallel for num_threads(thread_count)
    for (int i = 0; i < N; i++) {
      vecf2[i] = vecf2[i] / sum;
    }
    const double t2 = omp_get_wtime();
    printf("2NORM FINE THREADS %d TIME: %lf RESULE: %lf\n", thread_count,
           t2 - t1, sum);

    // MAXNORM FINE
    double mx = 0;
    double vecfmax[N];
    init_vec(vecfmax);
    const double t3 = omp_get_wtime();
#pragma omp parallel for reduction(max : mx) num_threads(thread_count)
    for (int i = 0; i < N; i++) {
      mx = vecfmax[i] > mx ? vecfmax[i] : mx;
    }

#pragma omp parallel for num_threads(thread_count)
    for (int i = 0; i < N; i++) {
      vecfmax[i] = vecfmax[i] / sum;
    }
    const double t4 = omp_get_wtime();
    printf("MAXNORM FINE THREADS %d TIME: %lf RESULT: %lf\n", thread_count,
           t4 - t3, mx);

    // 2NORM COARSE

    double sum2 = 0;
    double vecc2[N];
    init_vec(vecc2);
    const double t5 = omp_get_wtime();
#pragma omp parallel for shared(sum2)
    for (int i = 0; i < thread_count; i++) {
      int istart = i * (N / thread_count);
      int iend = (i + 1) * (N / thread_count) - 1;
      int s = 0;
      for (int i = istart; (i < iend) && (i < N); i++) {
        s += vec[i] * vec[i];
      }
#pragma omp critical
      sum2 += s;
    }

#pragma omp parallel for num_threads(thread_count)
    for (int i = 0; i < N; i++) {
      vecc2[i] = vecc2[i] / sum;
    }
    sum2 = sqrt(sum2);
    const double t6 = omp_get_wtime();
    printf("2NORM COARSE THREADS %d TIME: %lf RESULT: %lf\n", thread_count,
           t6 - t5, sum2);

    // MAXNORM COARSE

    double mx2 = 0;
    double veccmax[N];
    init_vec(veccmax);
    const double t7 = omp_get_wtime();
#pragma omp parallel for shared(mx2)
    for (int i = 0; i < thread_count; i++) {
      int istart = i * (N / thread_count);
      int iend = (i + 1) * (N / thread_count) - 1;
      int s = 0;
      for (int i = istart; i < iend && i < N; i++) {
#pragma omp critical
        mx2 = vec[i] > mx2 ? vec[i] : mx2;
      }
    }

#pragma omp parallel for num_threads(thread_count)
    for (int i = 0; i < N; i++) {
      vecc2[i] = veccmax[i] / mx2;
    }
    const double t8 = omp_get_wtime();
    printf("2NORM COARSE THREADS %d TIME: %lf RESULT: %lf\n", thread_count,
           t8 - t7, mx2);
  }
}
