#include "quad.h"
#include <stdio.h>

int main() {
  printf("Enter your 4 points, format \"x y\"\n");
  quad_t quad;
  printf("p1:\n");
  scanf("%lf %lf", &quad.n1.x, &quad.n1.y);
  printf("p2:\n");
  scanf("%lf %lf", &quad.n2.x, &quad.n2.y);
  printf("p3:\n");
  scanf("%lf %lf", &quad.n3.x, &quad.n3.y);
  printf("p4:\n");
  scanf("%lf %lf", &quad.n4.x, &quad.n4.y);
  double angles[4];
  double area = quad_area(quad);
  double perim = quad_perimeter(quad);
  quad_angles(quad, angles);
  printf("Area: %lf\n", area);
  printf("Perimeter: %lf\n", perim);
  printf("Angles: %lf, %lf, %lf, %lf\n", angles[0], angles[1], angles[2],
         angles[3]);
}
