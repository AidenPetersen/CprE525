#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100

double xs[SIZE];
double ys[SIZE];
double c0[] = {1.0};
double c1[] = {1.0, 0};
double c2[] = {2, 0, -1};
double c3[] = {4,0, -3 ,0};
double c4[] = {8,0,-8,0,1};
double c5[] = {16,0,-20,0,5,0};

void sample_poly(double* polynomial, int dim){
    for(int i = 0; i < SIZE; i++){

        xs[i] = (double) i / 20;
        ys[i] = 0;
        for(int j = 0; j < dim; j++){
            ys[i] += polynomial[j] * pow(xs[i], (double)j);
        }
    }
}

double* chebyshev(int n){
    switch (n) {
        case 0:
            return c0;
            break;
        case 1:
            return c1;
            break;
        case 2:
            return c2;
            break;
        case 3:
            return c3;
            break;
        case 4:
            return c4;
            break;
        case 5:
            return c5;
            break;
        default:
            printf("INVALID N TOO BIG OR SMALL");
            exit(1);
        }
}



int main(int argc, char* argv[]){
    int N = atoi(argv[1]);
    double* poly = chebyshev(N);
    int size = N+1;
    sample_poly(poly, size);
    FILE* fp = fopen("chebyshev.txt", "w");
    for(int i = 0; i < SIZE; i++){
        fprintf(fp, "%lf,%lf\n", xs[i], ys[i]);
    }
    return system("python3 viz.py");
}
