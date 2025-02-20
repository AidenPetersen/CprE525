#include "quad.h"
#include <math.h>

double __dist2d(point_t p1, point_t p2) {
  double xdiff = fabs(p1.x - p2.x);
  double ydiff = fabs(p1.y - p2.y);
  return sqrt(xdiff * xdiff + ydiff * ydiff);
}

double quad_perimeter(quad_t quad) {
  double s1 = __dist2d(quad.n1, quad.n2);
  double s2 = __dist2d(quad.n2, quad.n3);
  double s3 = __dist2d(quad.n3, quad.n4);
  double s4 = __dist2d(quad.n4, quad.n1);
  return s1 + s2 + s3 + s4;
}
