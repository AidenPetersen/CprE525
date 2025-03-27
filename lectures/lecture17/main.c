#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int cargs, char **args) {
  if (cargs < 4) {
    printf("All args not given");
    return 1;
  }
  int threads = atoi(args[1]);
  int n = atoi(args[2]);
  int k = atoi(args[3]);

  double time1 = omp_get_wtime();
  double v[n];
  double u[n];

  #pragma omp parallel for num_threads(threads)
  for(int i = 0; i < n; i++){
      v[n] = (double) rand();
  }

  #pragma omp parallel for num_threads(threads)
  for(int i = 0; i < n; i++){
      u[i] = 0;
      int x = v[i];
      double prev = 1;
      for(int j = 0; j < k-1; j++){
          prev *= x;
          u[i] += prev;
      }
  }

  double time2 = omp_get_wtime();
  printf("TIME: %lf\n", time2 - time1);
}
