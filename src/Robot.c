#include "Robot.h"
#include "Board.h"
#include "Coordinate.h"
#include "Card.h"
#include "Movement.h"
#include "CommonMemory.h"

struct Robot {
	Board *currentBoard;
	Coordinate locationOnBoard;
	enum Orientation facing;
	Card *steps[5];
};

Robot* Robot_create(Board *board, Coordinate c, enum Orientation o) {
	Robot *value = acquire(sizeof(Robot));
	value->currentBoard = board;
	value->locationOnBoard = c;
	value->facing = o;
	return value;
}

void Robot_destroy(Robot *value) {
	release(value);
}

void Robot_set_step(Robot *r, StepNumber n, Card *c) {
	r->steps[n-1] = c;
}

void Robot_execute(Robot *r, StepNumber n) {
	Card_apply(r->steps[n-1], r);
}

int Robot_is_at(Robot *r, Coordinate c) {
	return Coordinate_are_equal(r->locationOnBoard, c);
}

enum Orientation Robot_facing(Robot *r) {
	return r->facing;
}

void Robot_set_facing(Robot *r, enum Orientation o) {
	r->facing = o;
}

struct Coordinate Robot_location(Robot *r) {
	return r->locationOnBoard;
}

void Robot_move_to(Robot *r, struct Coordinate c) {
	r->locationOnBoard = c;
}

Board *Robot_board(Robot *r) {
	return r->currentBoard;
}
