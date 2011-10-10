#include "RobotAction.h"
#include "Robot.h"
#include "Board.h"
#include "CommonMemory.h"
#include "Movement.h"

struct RobotAction {
	ACTION_F action;
	enum Direction direction;
	enum Size size;
};

RobotAction *RobotAction_create(ACTION_F a, enum Direction d, enum Size s) {
	RobotAction *value = acquire(sizeof(RobotAction));
	value->action = a;
	value->direction = d;
	value->size = s;
	return value;
}

void RobotAction_destroy(RobotAction *value) {
	release(value);
}

void RobotAction_execute(RobotAction *a, struct Robot *r) {
	a->action(r,a->size, a->direction);
}

void Action_move(struct Robot *robot, int size, int direction) {
	int i = 0;
	for(i = 0; i < size; ++i) {
		if(!Board_can_move_through(Robot_board(robot), robot, direction))
			break;
		Coordinate candidateDestination = Direction_apply(Robot_facing(robot), direction, 1, Robot_location(robot));
		Robot_move_to(robot, candidateDestination);
	}
}

void Action_rotate(struct Robot *robot, int size, int direction) {
	 enum Orientation o = Robot_facing(robot);
	 o = (o + (size * direction)) % 4;
	 Robot_set_facing(robot, o);

}
