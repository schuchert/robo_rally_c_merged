#include <CppUTest/TestHarness.h>

#include "Movement.h"

TEST_GROUP(orientation) {
};

TEST(orientation, counter_clockwise_90) {
	enum Orientation r = Orientation_rotate(N, counter_clockwise, D90);
	CHECK_EQUAL(W, r);
}

TEST(orientation, counter_clockwise_180) {
	enum Orientation r = Orientation_rotate(W, counter_clockwise, D180);
	CHECK_EQUAL(E, r);
}

TEST(orientation, counter_clockwinse_270) {
	enum Orientation r = Orientation_rotate(S, counter_clockwise, D270);
	CHECK_EQUAL(W, r);
}

TEST(orientation, counter_clockwinse_360) {
	enum Orientation r = Orientation_rotate(W, counter_clockwise, D360);
	CHECK_EQUAL(W, r);
}

TEST(orientation, clockwise_90) {
	enum Orientation r = Orientation_rotate(N, clockwise, D90);
	CHECK_EQUAL(E, r);
}

TEST(orientation, clockwise_180) {
	enum Orientation r = Orientation_rotate(E, clockwise, D180);
	CHECK_EQUAL(W, r);
}

TEST(orientation, clockwinse_270) {
	enum Orientation r = Orientation_rotate(S, clockwise, D270);
	CHECK_EQUAL(E, r);
}

TEST(orientation, clockwinse_360) {
	enum Orientation r = Orientation_rotate(E, clockwise, D360);
	CHECK_EQUAL(E, r);
}
