#include "quad.h"
#include <math.h>

double quad_area(quad_t quad) {
  return fabs(0.5 * ((quad.n1.x * quad.n2.y + quad.n2.x * quad.n3.y +
                      quad.n3.x * quad.n4.y + quad.n4.x * quad.n1.y) -
                     (quad.n2.x * quad.n1.y + quad.n3.x * quad.n2.y +
                      quad.n4.x * quad.n3.y + quad.n1.x * quad.n4.y)));
}
