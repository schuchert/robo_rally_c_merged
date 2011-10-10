#include "Coordinate_test_helper.h"
#include <stdio.h>

bool operator !=(Coordinate lhs, Coordinate rhs) {
	return !Coordinate_are_equal(lhs, rhs);
}

SimpleString StringFrom(Coordinate c) {
	static char buf[64];
	sprintf(buf, "{%d,%d}", c.x, c.y);
	return buf;
}
