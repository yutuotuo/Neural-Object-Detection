
#include "point.h"

#include "math.h"

qreal Point::distanceTo(const Point &other) {
  qreal dist = 0;
  
  for (int i=0; i<size(); i++) {
    dist += pow(other[i]-at(i), 2);
  }
  
  return sqrt(dist);
}