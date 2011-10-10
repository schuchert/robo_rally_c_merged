#include "Coordinate.h"

Coordinate Coordinate_create(int x, int y) {
	Coordinate value = { x, y };
	return value;
}

int Coordinate_are_equal(Coordinate lhs, Coordinate rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}
