#pragma once
#ifndef ROBOTACTION_H_
#define ROBOTACTION_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "Movement.h"
struct Robot;

typedef void (*ACTION_F)(struct Robot*,int, int);
typedef struct RobotAction RobotAction;

RobotAction *RobotAction_create(ACTION_F, enum Direction, enum Size);
void RobotAction_destroy(RobotAction *);

void Action_move(struct Robot *robot, int size, int direction);
void Action_rotate(struct Robot *robot, int size, int direction);

void RobotAction_execute(RobotAction *, struct Robot *);

#ifdef __cplusplus
}
#endif

#endif /* ROBOTACTION_H_ */
