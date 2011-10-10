#pragma once
#ifndef TILE_H_
#define TILE_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "Movement.h"

typedef struct Tile Tile;
typedef struct TileWalls {
	char wallMask;
} TileWalls;

enum BoardElementMove {
   Part1 = 1,
   Part2 = 2,
   Part3 = 3,
   Part4 = 4
};


typedef int (*TILE_M_F)(Tile *, enum Orientation, enum Direction);
typedef int (*TILE_A_F)(Tile *, struct Robot *, enum BoardElementMove, enum RegisterPhase);

Tile *Tile_create(TILE_M_F, TileWalls);
void Tile_destroy(Tile *);
TileWalls Tile_walls_at(enum Orientation);

int Tile_empty(Tile *, enum Orientation, enum Direction);
int Tile_allows_movement_in(Tile *, enum Orientation, enum Direction);

#ifdef __cplusplus
}
#endif

#endif /* TILE_H_ */
