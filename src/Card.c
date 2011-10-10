#include "Card.h"
#include "CommonMemory.h"
#include "Robot.h"
#include "RobotAction.h"

struct Card {
	RobotAction *action;
	Priority priority;
};

Card *Card_create(RobotAction *a, Priority p) {
	Card *value = acquire(sizeof(Card));
	value->action = a;
	value->priority = p;
	return value;
}

void Card_destroy(Card *value) {
	release(value);
}

void Card_apply(Card * c, Robot *r) {
	RobotAction_execute(c->action, r);
}
