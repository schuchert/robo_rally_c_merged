#pragma once
#ifndef ROBOT_H_
#define ROBOT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Movement.h"
struct Coordinate;
struct Robot;
struct Board;
struct Card;

typedef int StepNumber;
typedef struct Robot Robot;

Robot* Robot_create(struct Board *, struct Coordinate, enum Orientation);
void Robot_destroy(struct Robot *);
void Robot_set_step(Robot *, StepNumber, struct Card *);
void Robot_execute(struct Robot *, StepNumber);
int Robot_is_at(struct Robot *, struct Coordinate);
enum Orientation Robot_facing(Robot *);
void Robot_set_facing(Robot *, enum Orientation);
struct Coordinate Robot_location(Robot *);
void Robot_move_to(Robot *, struct Coordinate);
struct Board *Robot_board(Robot *);

#ifdef __cplusplus
}
#endif


#endif /* ROBOT_H_ */
