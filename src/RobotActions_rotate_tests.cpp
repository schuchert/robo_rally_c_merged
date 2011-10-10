#include <CppUTest/TestHarness.h>
#include "Coordinate.h"
#include "Movement.h"
#include "Robot.h"
#include "RobotAction.h"

TEST_GROUP(RA_r) {
	Robot *robot;

	void setup() {
		robot = Robot_create(NULL, Coordinate_create(5,5), E);
	}
	void teardown() {
		Robot_destroy(robot);
	}
};

TEST(RA_r, rotate_clockwise_90) {
	Action_rotate(robot, D90, clockwise);
	CHECK_EQUAL(S, Robot_facing(robot));
}

TEST(RA_r, rotate_clockwise_180) {
	Action_rotate(robot, D180, clockwise);
	CHECK_EQUAL(W, Robot_facing(robot));
}

TEST(RA_r, rotate_clockwise_270) {
	Action_rotate(robot, D270, clockwise);
	CHECK_EQUAL(N, Robot_facing(robot));
}

TEST(RA_r, rotate_counter_clockwise_90) {
	Action_rotate(robot, D90, counter_clockwise);
	CHECK_EQUAL(N, Robot_facing(robot));
}

TEST(RA_r, rotate_counter_clockwise_180) {
	Action_rotate(robot, D180, counter_clockwise);
	CHECK_EQUAL(W, Robot_facing(robot));
}

TEST(RA_r, rotate_counter_clockwise_270) {
	Action_rotate(robot, D270, counter_clockwise);
	CHECK_EQUAL(S, Robot_facing(robot));
}
