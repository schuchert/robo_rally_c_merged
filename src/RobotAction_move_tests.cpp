#include <CppUTest/TestHarness.h>
#include "Robot.h"
#include "RobotAction.h"
#include "Coordinate.h"
#include "Board.h"

TEST_GROUP(RA_m) {
	Robot *robot;
	Board *board;
	RobotAction *action;
	void setup() {
		Coordinate size = Coordinate_create(10,10);
		board = Board_create(size);
		Coordinate start = Coordinate_create(5,5);
		robot = Robot_create(board, start, E);
		action = NULL;
	}
	void teardown() {
		RobotAction_destroy(action);
		Robot_destroy(robot);
		Board_destroy(board);
	}
};

#include "Coordinate_test_helper.h"

TEST(RA_m, backward_1) {
	Action_move(robot, Size1, backwards);
	Coordinate expected = Coordinate_create(4, 5);
	CHECK_EQUAL(expected, Robot_location(robot));
}

TEST(RA_m, backward_2) {
	Action_move(robot, Size2, backwards);
	Coordinate expected = Coordinate_create(3, 5);
	CHECK_EQUAL(expected, Robot_location(robot));
}

TEST(RA_m, backward_3) {
	Action_move(robot, Size3, backwards);
	Coordinate expected = Coordinate_create(2, 5);
	CHECK_EQUAL(expected, Robot_location(robot));
}

SimpleString StringFrom(Orientation o) {
	switch(o) {
	case N:
		return "N";
	case E:
		return "E";
	case S:
		return "S";
	case W:
		return "W";
	default:
		return "<unknown>";
	}
}

TEST(RA_m, clockwise_1) {
	Action_rotate(robot, D90, clockwise);
	CHECK_EQUAL(S, Robot_facing(robot));
}
