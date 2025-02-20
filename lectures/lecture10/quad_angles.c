#include "quad.h"
#include <math.h>

double __single_angle(point_t p1, point_t p2, point_t p3) {
  double result =
      atan2(p3.y - p2.y, p3.x - p2.x) - atan2(p1.y - p2.y, p1.x - p2.x);
  if (result < 0) {
    result += 2 * M_PI;
  }
  return result;
}

void quad_angles(quad_t quad, double *angles) {
  angles[0] = __single_angle(quad.n4, quad.n1, quad.n2) * 180 / M_PI;
  angles[1] = __single_angle(quad.n1, quad.n2, quad.n3) * 180 / M_PI;
  angles[2] = __single_angle(quad.n2, quad.n3, quad.n4) * 180 / M_PI;
  angles[3] = __single_angle(quad.n3, quad.n4, quad.n1) * 180 / M_PI;
}
