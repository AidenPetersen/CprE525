#include <stdio.h>

#pragma once

typedef struct {
  double x;
  double y;
} point_t;

typedef struct {
  point_t n1;
  point_t n2;
  point_t n3;
  point_t n4;
} quad_t;

double quad_area(quad_t quad);
double quad_perimeter(quad_t quad);
void quad_angles(quad_t quad, double *angles);
