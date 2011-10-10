#include <CppUTest/TestHarness.h>
#include "Movement.h"
#include "Coordinate_test_helper.h"

TEST_GROUP(direction) {
	enum { x = 10, y = 10 };
	Coordinate c;
	void setup() {
		c = Coordinate_create(x, y);
	}
};

TEST(direction, forwards_west_moves_west) {
	CHECK_EQUAL(Coordinate_create(x - Size3, y), Direction_apply(W, forward, Size3, c));
}

TEST(direction, backwards_west_moves_east) {
	CHECK_EQUAL(Coordinate_create(x + Size3, y), Direction_apply(W, backwards, Size3, c));
}

TEST(direction, forwards_east_moves_east) {
	CHECK_EQUAL(Coordinate_create(x + Size3, y), Direction_apply(E, forward, Size3, c));
}

TEST(direction, backwards_east_moves_west) {
	CHECK_EQUAL(Coordinate_create(x - Size3, y), Direction_apply(E, backwards, Size3, c));
}

TEST(direction, forwards_north_moves_north) {
	CHECK_EQUAL(Coordinate_create(x, y + Size3), Direction_apply(N, forward, Size3, c));
}

TEST(direction, backwards_north_moves_south) {
	CHECK_EQUAL(Coordinate_create(x, y - Size3), Direction_apply(N, backwards, Size3, c));
}

TEST(direction, forwards_south_moves_south) {
	CHECK_EQUAL(Coordinate_create(x, y - Size3), Direction_apply(S, forward, Size3, c));
}

TEST(direction, backwards_south_moves_south) {
	CHECK_EQUAL(Coordinate_create(x, y + Size3), Direction_apply(S, backwards, Size3, c));
}
