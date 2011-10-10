#include "Movement.h"
#include <stddef.h>
enum Orientation Orientation_rotate(enum Orientation o, enum Direction d, enum Size s) {
   return (o + s * d) % 4;
}

Coordinate Direction_apply(enum Orientation o, enum Direction d, enum Size s, Coordinate c) {
   Coordinate result = c;
   int *target = (o == N || o == S) ? &result.y : &result.x;
   int multiplier = (o == N || o == E) ? d : -d;
   *target += multiplier * s;
   return result;
}

enum Orientation Orientation_actual(enum Orientation o, enum Direction d) {
   return (o + (d == forward ? 0 : 2)) % 4;
}
