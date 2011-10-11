#include <CppUTest/TestHarness.h>

#include "Coordinate_test_helper.h"
#include "Robot.h"
#include "RegisterPhase.h"
#include "Board.h"
#include "Card.h"
#include "RobotAction.h"
#include "Movement.h"
#include "Tile.h"

TEST_GROUP(r_b_c_e) {
	Board *board;
	Robot *robot;
	Card *cards[10];
	RobotAction *actions[10];
	int cards_created;
	int actions_created;

	virtual void setup() {
		Coordinate upperRight = Coordinate_create(20, 20);
		board = Board_create(upperRight);

		Coordinate startLocation = Coordinate_create(10, 10);
		robot = Robot_create(board, startLocation, N);

		cards_created = 0;
		actions_created = 0;
	}

	virtual void teardown() {
		Board_destroy(board);
		Robot_destroy(robot);
		for (int i = 0; i < actions_created; ++i)
			RobotAction_destroy(actions[i]);
		for (int i = 0; i < cards_created; ++i)
			Card_destroy(cards[i]);
	}

	RobotAction *create_action(ACTION_F f, enum Direction d, enum Size s) {
		actions[actions_created] = RobotAction_create(f, d, s);
		return actions[actions_created++];
	}

	Card *create_move_card(enum Direction d, enum Size s) {
		cards[cards_created] = Card_create(create_action(Action_move, d, s),
				500);
		return cards[cards_created++];
	}

	Card *create_rotate_card(enum Direction d, enum Size s) {
		cards[cards_created] = Card_create(create_action(Action_rotate, d, s),
				500);
		return cards[cards_created++];
	}
	void check_at(int x, int y) {
		CHECK_EQUAL(Coordinate_create(x,y), Robot_location(robot));
	}
	void check_facing(enum Orientation o) {
		CHECK_EQUAL(o, Robot_facing(robot));
	}
	void check_facing_at(enum Orientation o, int x, int y) {
		check_facing(o);
		check_at(x, y);
	}
};

TEST(r_b_c_e, fully_move_and_rotate) {
	Robot_set_register(robot, One, create_move_card(forward, Size2));
	Robot_set_register(robot, Two, create_rotate_card(counter_clockwise, D90));
	Robot_set_register(robot, Three, create_move_card(backwards, Size2));
	Robot_set_register(robot, Four, create_rotate_card(clockwise, D270));
	Robot_set_register(robot, Five, create_move_card(backwards, Size2));
	for (enum RegisterPhase i = One; i < BeyondLast; i = RegisterPhase(i + 1))
		Robot_execute(robot, i);
	check_facing_at(S, 12, 14);
}

TEST(r_b_c_e, cannot_move_through_wall) {
	Coordinate twoNorth = Coordinate_create(10, 12);
	Tile *tile = Tile_create(Tile_empty, Tile_walls_at(N), RegisterPhaseGroup_create(Rfg_All));
	Board_set_tile(board, tile, twoNorth);
	RobotAction *action = create_action(Action_move, forward, Size3);
	RobotAction_execute(action, robot);
	CHECK_EQUAL(twoNorth, Robot_location(robot));
}

TEST(r_b_c_e, move_forward) {
	Card *card = create_move_card(forward, Size1);
	Robot_set_register(robot, One, card);
	Robot_execute(robot, One);
	check_facing_at(N, 10, 11);
}
