#pragma once
#ifndef BOARD_H_
#define BOARD_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "Coordinate.h"
#include "Movement.h"
struct Coordinate;
struct Tile;
struct Robot;
typedef struct Board Board;

Board *Board_create(struct Coordinate upperRight);
void Board_destroy(Board *);
void Board_set_tile(Board *, struct Tile *, Coordinate);
int Board_can_move_through(Board *, struct Robot *, enum Direction);


#ifdef __cplusplus
}
#endif

#endif /* BOARD_H_ */
